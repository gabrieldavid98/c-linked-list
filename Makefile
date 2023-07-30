default:
	gcc -Wall -Werror main.c node.c -o app -g -std=c11
	./app

node.o: node.c
	gcc -c node.c