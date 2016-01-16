#include "FileStore.h" 
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>
#include <protocol/TJSONProtocol.h>

#include <string>
#include <cstdlib>
#include <cstdio>
#include <getopt.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using std::vector;
using std::cout;
using std::endl;
using std::string;
using boost::shared_ptr;
using std::ifstream;


int main(int argc, char **argv) {
    boost::shared_ptr<TSocket> socket(new TSocket(argv[1], atoi(argv[2])));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    boost::shared_ptr<TMemoryBuffer> transportJSON(new TMemoryBuffer());
	TJSONProtocol dataToJSON(transportJSON);
	FileStoreClient client(protocol);
	RFile file;
	RFileMetadata meta;
	StatusReport status;
	transport->open();

    /* read the opts from the command line using functions provided in getopt.h */
    static struct option parameters[] = {
            {"operation",     required_argument, 0,  'o' },
            {"filename",  required_argument,       0,  'f' },
            {"user",  required_argument, 0,  'u' },
            {0,         0,                 0,  0 }
        };

    int  parame = 0;
    int opt = 0;
    char *opera = nullptr;
    char *filename = nullptr;
    char *user = nullptr;
    while((opt = getopt_long(argc - 2, argv + 2, "o:f:u:", parameters,
                    &parame)) != -1) {
        switch(opt) {
            case 'o':
                opera = optarg;
                break;
            case 'f':
                filename = optarg;
                break;
            case 'u':
                user = optarg;
                break;
            default:
                cout << " the input format is wrong " << endl;
                return 1;
                break;
        }
    }
	
	// get the parameter from command provided by client
    if (nullptr == opera || nullptr == user) {
        cout << "Errors  in input: operation or user can't be null!" << endl;
        return 1;
    } else if (0 == strcmp(opera, "read")){
        if (nullptr == filename) {
            cout << "Error in input: The filename cannot be null while reading!"
                << endl;
            return 1;
        }
        try{
            client.readFile(file,filename,user);	
        }
        catch (SystemException e){
            e.write(&dataToJSON);
            cout << transportJSON->getBufferAsString() << endl;
            return 0;
        }
        file.write(&dataToJSON);
        cout << transportJSON->getBufferAsString() << endl;
	}
	else if( 0 == strcmp(opera, "write")){
        if (nullptr == filename) {
            cout << "Error in input: The filename cannot be null while writing!"
                 << endl; 
            return 1;
        }
        /* read the local data here to be written to the server
         * if no such file on client local, do nothing
         */
        string content;
        ifstream is(filename);
        if (is)
        {
			
			/*
			streampos begin, end;
			begin = is.tellg();
			is.seekg(0, ios::end);
			end = is.tellg();
			int length = end - begin;
            is.seekg (0, ios::end);
            int length = is.tellg();
            is.seekg(0, ios::beg);
            char *buffer = new char[length + 1];
            is.read(buffer, length);
			buffer[length] = '\0';
            is.close();
			cout << "buffer is " << buffer << endl;
            content = string(buffer);
			cout << "length is: " << length << endl;
			*/

			// works fine
			is.seekg(0, std::ios::end);
			content.reserve(is.tellg());
			is.seekg(0, std::ios::beg);
			content.assign((std::istreambuf_iterator<char>(is)),
					std::istreambuf_iterator<char>());
			is.close();
			cout << "content is: " << content << endl;
			cout << "before close file" << endl;
			
            //delete []buffer;
            meta.__set_filename(filename);//filename
            meta.__set_owner(user);//owner
            meta.__set_contentLength(content.size());//contentlength
            file.__set_meta(meta);
            file.__set_content(content);
            client.writeFile(status,file);
            status.write(&dataToJSON);
            cout << transportJSON->getBufferAsString() << endl;
        }
	}
	else if(0 == strcmp(opera, "list")){
        vector<RFileMetadata> vec;
        try{
        client.listOwnedFiles(vec,user);
        }
        catch(SystemException e){
            e.write(&dataToJSON);
            cout << transportJSON->getBufferAsString() << endl;
            return 0;
        }
        
        dataToJSON.writeListBegin(::apache::thrift::protocol::T_STRUCT, 
                vec.size());
        for(unsigned int i = 0; i < vec.size(); i++) {
            vec[i].write(&dataToJSON);
        }
        dataToJSON.writeListEnd();
        cout << transportJSON->getBufferAsString() << endl;
	}
	else if(0 == strcmp(opera, "delete")){
        try{
		    client.deleteFile(status,filename,user);
        }
        catch(SystemException e){
            e.write(&dataToJSON);
            cout << transportJSON->getBufferAsString() << endl;
            return 0;
        }
		status.write(&dataToJSON);
			cout << transportJSON->getBufferAsString() << endl;
	}
	else{
		cout << "unsupported operation codes" << endl;
        return 1;
	}
	transport->close();
	return 0;
}
