all: server client

server:
	gcc server.c erproc.c -o server

client:
	gcc client.c erproc.c -o client

clean:
	rm -rf *.o client server
