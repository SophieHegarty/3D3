#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>

#define NUM_ROUTERS 5
struct vector{
private:
    int getCost(){ return cost; }
    void setCost(int n_cost){ cost = n_cost;}
    int getNextPortNumber(){ return nextPortNumber; }
    void setCost(int n_nextPortNumber){ nextPortNumber = n_nextPortNumber;}
    char getNextPortName(){ return nextPortName; }
    void setNextPortName(char n_nextPortName){ nextPortName = n_nextPortName;}
public:
    
    int cost;
    int nextPortNumber;
    char nextPortName;

}
struct node{
    char id;
    int port;
    sockaddr_in
    std::vector<vector> nodesVectors;
};

class routing
{
public:
    



private:
    std::vector<node> neighbour;
};