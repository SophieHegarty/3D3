#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <netinet/in.h>

using namespace std;

#define NUM_ROUTERS 5
struct rvector{
private:
    int getCost(){ return cost; }
    void setCost(int n_cost){ cost = n_cost;}
    int getNextPortNumber(){ return nextPortNumber; }
    void setPortNumber(int n_nextPortNumber){ nextPortNumber = n_nextPortNumber;}
    char getNextPortName(){ return nextPortName; }
    void setNextPortName(char n_nextPortName){ nextPortName = n_nextPortName;}
public:
    
    int cost;
    int nextPortNumber;
    char nextPortName;

};
struct node{
    char id;
    int port;
    char bestpath;//next hop from current to this node
    int bestcost;//total cost from current to this node
    sockaddr_in addr;
    std::vector<struct rvector> nodesVectors;
};
class routing
{
    public:
    routing(string file,char id);
    void setup(string file,char id);
    void consumeUpdate(string upd);
    string generateUpdate();
    std::vector<struct node> neighbour;
};
