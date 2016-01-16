#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "DHTNode_server.skeleton.h"

using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char *argv[])
{
  int port = 9090;

  if (argc != 3) {
	  cerr << "arguments error!, using " << argv[0] << " port interval " <<
		  endl;
      return 1;
  }

  port = atoi(argv[1]);
  int inter_time = atoi(argv[2]);

  call_main(port, inter_time);
  return 0;
}
