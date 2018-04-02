#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <string>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>



#define BUFFER_SIZE 150
using namespace std;

struct packet
{
    string category;
	char source;
	char dest;
	int length;
	char data[BUFFER_SIZE];
};

int main(int argc, char** argv)
{
	int portno = 10001;
	sockaddr myaddr;

	memset((char *)&myaddr, 0, sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myaddr.sin_port = htons(portno);

	int socketfd; // our socket
	if ((socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("cannot create socket\n");
		return 0;
	}
	
	// bind the socket to localhost and myPort
	if (bind(socketfd, &myaddr, sizeof(myaddr)) < 0)
	{
		perror("bind failed");
		return 0;
	}

void *rcvbuf = malloc(BUFFER_SIZE);
sockaddr_in remaddr;
socklen_t addrlen = sizeof(sockaddr_in);
    for(;;)
    {
        memset(rcvbuf, 0, BUFFER_SIZE);
        int recvlen = recvfrom(socketfd, rcvbuf, BUFFER_SIZE, 0, (struct sockaddr *)&remaddr, &addrlen);
    }
}