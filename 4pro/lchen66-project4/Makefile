#OPT=-O2
THRIFT_PATH=/home/yaoliu/src_code/local/

CFLAGS=-Wall -g -Wno-format -fPIC -std=c++11 $(OPT) $(DEBUG) $(TEST)

CC=g++
LIBS = -lthrift -pthread
INCLUDE_PATH = -I $(THRIFT_PATH)/include/ -I $(THRIFT_PATH)/include/thrift/
LIB_PATH = -L$(THRIFT_PATH)/lib/

OBJS=DHTNode.o stable_chord_types.o stable_chord_constants.o sha256.o DHTNode_server.skeleton.o common.o
OBJSERVER=server.o
OBJTESTSERVERS=test.o


all: server test

server: $(OBJS) $(OBJSERVER)
	$(CC) -o server $^ $(CFLAGS) $(LIBS) $(LIB_PATH)
	
test: $(OBJS) $(OBJTESTSERVERS)
	$(CC) -o test $^ $(CFLAGS) $(LIBS) $(LIB_PATH)


%.o: %.cpp
	$(CC) $(INCLUDE_PATH) -c $(CFLAGS) -o $@ $^

clean:
	rm -f *.o server test

rebuild: clean all



