CC = g++
CFLAGS = -c -Wall -pedantic
SERVER = COMserver
CLIENT = COMclient
CLIENT_SOURCES = client.cpp
SERVER_SOURCES = server.cpp
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)

all: $(SERVER) $(CLIENT) runsrv

$(SERVER): $(SERVER_OBJECTS)
	$(CC) $(SERVER_OBJECTS) -o $@
	
$(CLIENT): $(CIENT_OBJECTS)
	$(CC) $(CLIENT_OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

runsrv:
	$(SERVER)

runcl:
	$(CLIENT)