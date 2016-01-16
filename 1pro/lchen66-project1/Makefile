#!/bin/sh

OPT=-O2
CVERSION=-std=c++11
#TEST=-DTEST
DEBUG=-g -DDEBUG 
THRIFT_PATH=/home/yaoliu/src_code/local/


CFLAGS=-Wall -Wno-format -fPIC $(OPT) $(DEBUG) $(CVERSION) 

CC=g++
LIBS = -lthrift
INCLUDE_PATH = -I $(THRIFT_PATH)/include/ -I $(THRIFT_PATH)/include/thrift/
LIB_PATH = -L$(THRIFT_PATH)/lib/

OBJS=FileStore.o fileservice_types.o fileservice_constants.o
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



