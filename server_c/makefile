objs = server.o client.o
apps : server client
.PHONY : apps

server : server.o
	cc -o server server.o

client : client.o
	cc -o client client.o

server.o : server.c

client.o : client.c

.PHONY : clean

clean : 
	-rm server client $(objs)
