#!/bin/sh

CCVERSION=-std=c++11
#OPT=-O2
#TEST=-DTEST
DEBUG=-g -DDEBUG 
THRIFT_PATH=/home/yaoliu/src_code/local/
#THRIFT_PATH=/usr/local/


CFLAGS=-Wall -Wno-format -fPIC $(CCVERSION) $(OPT) $(DEBUG) $(TEST)

CC=g++
LIBS = -lthrift
INCLUDE_PATH = -I $(THRIFT_PATH)/include/ -I $(THRIFT_PATH)/include/thrift/
LIB_PATH = -L$(THRIFT_PATH)/lib/

OBJS=FileStore.o chord_join_remove_dht_types.o chord_join_remove_dht_constants.o sha256.o 
OBJSERVER=server.o
OBJCLIENT=client.o 



all: server client 

server: $(OBJS) $(OBJSERVER)
	$(CC) -o server $^ $(CFLAGS) $(LIBS) $(LIB_PATH)
	
client: $(OBJS) $(OBJCLIENT)
	$(CC) -o client $^ $(CFLAGS) $(LIBS) $(LIB_PATH)

%.o: %.cpp
	$(CC) $(INCLUDE_PATH) -c $(CFLAGS) -o $@ $^

clean:
	rm -f *.o server client 

rebuild: clean all



