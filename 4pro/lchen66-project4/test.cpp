#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <unistd.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <pthread.h>
#include <string>
#include "DHTNode.h"
#include "sha256.h"
#include "common.h"
#include "DHTNode_server.skeleton.h"

#include "stable_chord_types.h"
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>
#include <iostream>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using boost::shared_ptr;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::set;
using std::string;
using std::map;

#define NODES	256
#define PRED 0
#define SUCC 1
#define BLACK	"\033[1;30m"
#define RED 	"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define WHITE	"\033[1;37m"
#define END		"\033[0m"

bool checkCorrect(const vector<string> &nodes, const string key, const string id, const int type)
{
	const int size = nodes.size();
	switch(type)
	{
		case PRED :
			{
				if (key == nodes[0])
				{
					return id == nodes[size - 1];
				}
				else 
				{
					auto it = find(nodes.begin() + 1, nodes.end(), key);
					return id == *(it - 1);
				} 
				break;
			}
		case SUCC :
			{
				if (key == nodes[size -1])
				{
					return id == nodes[0];
				}
				else 
				{
					auto it = find(nodes.begin(), nodes.end() - 1, key);
					return id == *(it + 1);
				}
			    break;
			}
		default :
			return false;
			break;
	}
	return false;

}
string getDesizedKey(const string &client, const vector<string> &nodes)
{
    const int size = nodes.size();	
	if (client == nodes[size -1])
	{
		return nodes[0];
	}
	else 
	{
		auto it = find(nodes.begin(), nodes.end() - 1, client);
		return *(it + 1);
	}
}

struct Data {
    int port_num;
    int inter_time;
};

void *func(void *arg)
{
    Data *data = (Data *)arg;
    call_main(data->port_num, data->inter_time);
    return NULL;
}

int main(int argc, char *argv[])
{
	int totalNodes;
    int port_num_start;
    int inter_time;
	int i, j;
    vector<string> nodes;
	string ip;
	NodeID target;
    map<string, vector<string> > fingers;
	int iterations = 0;

    if (argc < 4) {
		cout << "argument error!, using " << argv[0] << 
			" port inter_time num " << endl;
        return 1;
    }

    port_num_start = atoi(argv[1]);
    inter_time = atoi(argv[2]);
    totalNodes = atoi(argv[3]);

    Data data[totalNodes];
    
	// start all the server, one thread one server running
    for(i = 0; i < totalNodes; i++) {
        data[i].inter_time = inter_time;
        data[i].port_num = port_num_start + i;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, func, (void *)(data + i));
    }

    sleep(1);
    ip = get_eth_ip();
    srand(time(NULL));
	cout << "Join all nodes one by one! " << endl;
    nodes.push_back(sha256_ip_port_hex(ip, port_num_start));
	for (i = 1; i < totalNodes; i++) {
		int join_port = port_num_start + i;
		shared_ptr<DHTNodeClient> client = 
			connectClientAgency(ip, join_port);
		target.__set_ip(ip);
		target.__set_port(join_port - 1); //join the nodes who just joined in
		target.__set_id(sha256_ip_port_hex(ip, join_port - 1));
        client->join(target);
        nodes.push_back(sha256_ip_port_hex(ip, port_num_start + i));
	}
    sort(nodes.begin(), nodes.end());
    for(i = 0; i < totalNodes; i++) {
        string currid = nodes[i];
        int index = 0;
        vector<string> currftable;

        for(j = i + 1; j < totalNodes; j++) {
            if (index == NODES)
                break;
            string key = addId(nodes[i], index);
            while(index < NODES && keyCompare(nodes[i], key, nodes[j])) {
                currftable.push_back(nodes[j]);
                index++;
            }
        }
        for(j = 0;;j++) {
            if (index == NODES)
                break;
            string key = addId(nodes[i], index);
            while(index < NODES && 
                    keyCompare(nodes[i], key, nodes[j])) {
                currftable.push_back(nodes[j]);
                index++;
            }
        }
        fingers[nodes[i]] = currftable;
    }

	while (true) {
        int pcorrect = 0, scorrect = 0, fentries = 0,
            incorrectftnum = 0, correctftnum = 0,
        	find_scorrect = 0, total_findPred = 0;
		NodeID pred, succ;

        for(i = 0; i < totalNodes; i++) {
            string clientId = sha256_ip_port_hex(ip, port_num_start + i);
            const vector<string> &correctft = fingers[clientId];
            vector<NodeID> currftable;
            shared_ptr<DHTNodeClient> client = 
               connectClientAgency(ip, port_num_start + i);

            client->getNodePred(pred);
            client->getFingertable(currftable);
			// the first entry in finger table
			succ = currftable[0]; 
			if (checkCorrect(nodes, clientId, pred.id, PRED))
                pcorrect++;
			if (checkCorrect(nodes, clientId,  succ.id, SUCC))
                scorrect++;

			// compare the correctness for fingertables
			set<string> count;
			count.clear();
            for(j = 0; j < NODES; j++) {
                if (currftable[j].id.empty()) {
                } else {
					count.insert(currftable[j].id);
                    fentries++;
                    if (currftable[j].id != correctft[j])
                        incorrectftnum++;
                    else
                        correctftnum++;
                }
            }
            for (auto item : currftable)
			{
				if (item.id.empty())
					;//cout << "***********emmpty*********" << endl;
				else 
				    ;//cout << item.id << endl;
			}
            string succid = addId(clientId, 0);
            NodeID find_succ_ret;
            string toCompare = getDesizedKey(clientId, nodes); 
			NodeID actual;
            client->getNodeSucc(actual);
            client = connectClientAgency(ip, succ.port);
            client->findSucc(find_succ_ret, succid);
            if (find_succ_ret.id == toCompare)
			{
                find_scorrect++;
            	total_findPred += find_succ_ret.count;
			}
        }
		// output of the results here
		cout << "------------------" << "Iteration: " 
			<< iterations << "------------------" << endl;
		cout << "correct predecessors: " << RED << pcorrect << END <<
			" correct successors: " << RED << scorrect << END 
			<< " nodes: " << RED << totalNodes << END << endl;
		cout <<	"correct fingertable entries: " << 
			MAGENTA << correctftnum  << END  << endl; 
		cout << "incorrect fingertable entries: " 
			<< MAGENTA << incorrectftnum << END << endl;
		cout << "fingertable entries have been set: " 
			<< MAGENTA << fentries << END << endl;
		cout << "[EXTRA] total number of correct successor nodes returned by "
			<< "findSucc() : " <<
			 GREEN << find_scorrect << END << endl;
		cout << "[EXTRA] average number of correct successor nodes returned by "
			<< "findSucc() : " <<
			 GREEN << (double) find_scorrect / totalNodes << END << endl;
		cout << "[EXTRA] total number of calls to findPred for correct "
			<< "successor returned: " << 
			GREEN << total_findPred << END << endl;
		if (find_scorrect == 0) find_scorrect++;
		cout << "[EXTRA] average number of calls to findPred for correct "
			<< "successor returned: " << 
			GREEN << (double) total_findPred / find_scorrect << END << endl;
		cout << endl;
        sleep(inter_time);
		iterations++;
    }
	assert(false);
    return 0;
}

