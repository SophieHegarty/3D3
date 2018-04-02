#include "vector.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

routing::routing(string file, char id)
{
    routing(string file, char id)

    fstream vfs;
    if(!vfs.open(file,std::fstream::in)){
        cout << "Failed to open :" << file << "\n";
    }
    char* line;
    int streamsize = 50;
    string portholder;
    int n;

    //setting up initial node in the table
    node mynode = new node;
    mynode.id = id;
    mynode.port = -1;
    //parse file into vectors
    for(vfs.getline(line,streamsize)){
        //NB* Assumes no duplicate lines
        //Assumes CSV format
        //Assumes info startpoints at [0],[2],[4]...[n+1]
        //Assumes cost <10
        
        n = 0;//cursor
        
        if(line[0] != id){
            //line not intended for this node
            //however may contain self port info
            if(mynode.port < 0 && line[2] == id){
                n = 4;portholder = "";
                while (line[n] != ','){
                    portholder += line[n];
                    n++;
                }
                mynode.port = stoi(portholder,nullptr);

            }
        }
        else{
            vector nv = new vector;
            nv.nextPortName = line[2]//Should be Reciever id
            n = 4;portholder = "";
            while (line[n] != ','){
                portholder += line[n];
                n++;
            }
            nv.nextPortNumber = stoi(portholder,nullptr);
            n++;//move cursor from , -> cost
            nv.cost = (int)(line[n] - '0');
            mynode.nodesVectors += nv;
        }
    }
    memset((char *)&mynode.addr, 0, sizeof(mynode.addr));
    mynode.addr.sin_family = AF_INET;
    mynode.addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    mynode.addr.sin_port = htons(mynode.port);
    neighbour += mynode;
    vfs.close();

}