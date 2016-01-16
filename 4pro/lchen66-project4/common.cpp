#include "common.h"
#include <stdio.h>
#include <string.h> /* for strncpy */
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <ifaddrs.h>

#include <stdio.h>
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>
#include "DHTNode.h"
#include <iostream>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using std::cout;
using std::endl;


using namespace std;

string get_eth_ip(void)
{
	struct ifaddrs *addrs, *tmp;
	getifaddrs(&addrs);
	tmp = addrs;
	char host[NI_MAXHOST];

	while (tmp) {
		if (tmp->ifa_addr 
				&& !strncmp(tmp->ifa_name, "eth", 3)  
				&& tmp->ifa_addr->sa_family == AF_INET)
			getnameinfo(tmp->ifa_addr, sizeof(struct sockaddr_in),
					host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
		tmp = tmp->ifa_next;
	}

	freeifaddrs(addrs);
	return host;
}
std::string addId(const std::string &id, int exp)
{
	char idstr[65];
	snprintf(idstr, 65, id.c_str());
	int carry = (1 << (exp % 4));
	for(int i = 256 / 4 - exp / 4 - 1; i >= 0; i--) {
		int k = HEXTODEC(idstr[i]);
		k += carry;
		carry = k / 16;
		idstr[i] = DECTOHEX(k % 16);
		if (carry == 0)
			break;
	}
	return idstr;
}

bool keyCompare(const std::string &left,
		const std::string &middle,
		const std::string &right)
{
	if (left == right || left == middle || right == middle)
		return true;
	return right > left ? (middle > left && middle < right)
		: ((middle > left && middle > right) ||
				(middle < left && middle < right));
}

boost::shared_ptr<DHTNodeClient> connectClientAgency(const std::string &ip, int port)
{
    boost::shared_ptr<TSocket> socket(new TSocket(ip.c_str(), port));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    boost::shared_ptr<DHTNodeClient> client(new DHTNodeClient(protocol));

    try {
        transport->open();
    } catch (...) {
		cerr << "Error! connect to ip : port " << ip << " : " << port << endl;
        client = boost::shared_ptr<DHTNodeClient>();
    }
    return client;
}

