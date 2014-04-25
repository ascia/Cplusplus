all:clean client server
client:
	gcc -g client_test.c -o client

server:
	gcc -g server_test.c -o server

clean:
	rm ./server ./client -rf
