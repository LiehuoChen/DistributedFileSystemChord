#ifndef LH_COMMON_H
#define LH_COMMON_H
#include <string>
#include <string>
#include <vector>
#include "stable_chord_types.h"
//#include "lock.h"
#include <ctime>
#include <cstdlib>


#define DECTOHEX(a) ((a) >= 10? (a) - 10 + 'a': (a) + '0');
#define HEXTODEC(a) ((a) >= 'a'? (a) - 'a' + 10 : (a) - '0')

using std::string;
class DHTNodeClient;



/****
  *get the local ip address that the server is running right now
  *return the ip address in string format
  *******/
string get_eth_ip(void);

string addId(const std::string &id, int exp);

bool keyCompare(const std::string &left,
		const std::string &middle,
		const std::string &right);


boost::shared_ptr<DHTNodeClient> connectClientAgency(const std::string &ip, int port);

#endif




