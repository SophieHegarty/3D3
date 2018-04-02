#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <string>
#include <iostream>

#include "vector.h"

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

void* newPacket(char *data, string category, char source, char dest );

int main(int argc, char** argv)
{

	vector vector(argv[1], argv[2]);

	socklen_t addrlength = sizeof(sockaddr_in); 
	vector(string file, char id)
	
	int socketfd; 
	if ((socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("failed to create socket\n");
		return 0;
	}

    if (bind(socketfd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0)
	{
		perror("bind failed");
		return 0;
    }
    
    packet* one;
	memset(one, 0, sizeof(packet));
    cin.getline(one->data, BUFFER_SIZE);
    for (int i = 0; i < neighbors.size(); i++)
		{
			if (neighbors[i].id == 'A')
			{
				
				sendto(socketfd, (void*)one, sizeof(packet), 0, (struct sockaddr *)&neighbors[i].addr, sizeof(sockaddr_in));

				cout << "Sent data packet" << endl;
				cout << "Type: data" << endl;
				cout << "Source: " << m.source << endl;
				cout << "Destination: " << m.dest << endl;
				cout << "Length of packet: " << sizeof(header) + m.length << endl;
				cout << "Length of payload: " << m.length << endl;
				cout << "Payload: " << data << endl;

				free(packet);
			}
		}

    }
    

    

