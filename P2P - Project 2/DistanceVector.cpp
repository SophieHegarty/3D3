#include "vector.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void routing::setup(string file, char id)
{


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
            rvector nv = new rvector;
            nv.nextPortName = line[2]//Should be Reciever id
            n = 4;portholder = "";
            while (line[n] != ','){
                portholder += line[n];
                n++;
            }
            nv.nextPortNumber = stoi(portholder,nullptr);
            n++;//move cursor from , -> cost
            nv.cost = (int)(line[n] - '0');
            mynode.nodesVectors.push_back(nv);
        }
    }
    memset((char *)&mynode.addr, 0, sizeof(mynode.addr));
    mynode.addr.sin_family = AF_INET;
    mynode.addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    mynode.addr.sin_port = htons(mynode.port);
    neighbour.push_back(mynode);
    vfs.close();

}


string routing::generateUpdate(){
    //CSV format
    //lines separated by "\n"
    string upd = "",line = "";
    //scan nodes
    for(node n : neighbour){
        //sends full table
        //could possibly be trimmed for smaller packets
        line += "%c,%d,%d\n",n.id,n.port,(int)n.nodesVectors.size();//id,port,#vectors
        for(rvector v : nodesVectors){
            line += "%d,%d,%c\n",v.cost,v.nextPortNumber,v.nextPortName;//cost,npNum,npName
            //note bestpath and bestcost are locally calculated upon table update so are not sent
        }
        upd += line;
        line = "";
    }
    return upd;
}
void routing::consumeUpdate(string upd){
    //load update into stringstream
    stringstream ss = new stringstream(upd);
    int linesize = 50;
    string line = "";
    while (ss.getline(line,linesize)){
        //parse node line
        int edges;
        for (int i = 0; i < edges;i++){
            //parse edge lines
        }
        //check if node is new
            //add to vector & print update
        //check if existing node needs updating
            //update & print update
    }
}

routing::routing(string file, char id)
{

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
            rvector nv = new rvector;
            nv.nextPortName = line[2]//Should be Reciever id
            n = 4;portholder = "";
            while (line[n] != ','){
                portholder += line[n];
                n++;
            }
            nv.nextPortNumber = stoi(portholder,nullptr);
            n++;//move cursor from , -> cost
            nv.cost = (int)(line[n] - '0');
            mynode.nodesVectors.push_back(nv);
        }
    }
    memset((char *)&mynode.addr, 0, sizeof(mynode.addr));
    mynode.addr.sin_family = AF_INET;
    mynode.addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    mynode.addr.sin_port = htons(mynode.port);
    neighbour.push_back(mynode);
    vfs.close();

}
