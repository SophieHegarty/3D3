//
//  bellmanford.cpp
//  bellmanford
//
//  Created by Sophie Hegarty on 21/03/2018.
//  Copyright © 2018 Sophie Hegarty. All rights reserved.
//

#include "bellmanford.hpp"
#include <iostream>
#include <cmath>
#include <climits>
#include <new>
//#include <bits/stdc++.h>
// A C++ program for Bellman-Ford's single source
// shortest path algorithm.


// holds info on the weight of the edge
struct Edge_graph
{
    int source, destination, weight;
};

// struct graph, conatins info on the graph eg. vertices and edges
struct Graph
{
    int Vertex, Edge;
    struct Edge_graph* edge;
};

// creates graph with vertex and edge
struct Graph* New_graph(int Vertex, int Edge)
{
    struct Graph* graph = new Graph;
    graph->Vertex = Vertex;
    graph->Edge = Edge;
    graph->edge = new Edge_graph[Edge];
    return graph;
}

// A utility function used to print the solution
void print(int distance[], int n)
{
    printf("Vertex:   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, distance[i]);
}


void BellmanFord(struct Graph* graph, int source)
{
    //set vertices and edges from graph
    int Vertex = graph->Vertex;
    int Edge = graph->Edge;
    int distance[Vertex];
    
    // Initialize distances from source to all other vertices as infinity
    for (int i = 0; i < Vertex; i++){
        distance[i]   = INT_MAX;
        distance[source] = 0;
    }
    // Relax all edges |V| - 1 times
    for (int i = 1; i <= Vertex-1; i++) //do it for number of vertices
    {
        for (int j = 0; j < Edge; j++) //do it for the number of edges in each vertex
        {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }
    
    // Check for negative-weight cycles, no negatives in our case.
    for (int i = 0; i < Edge; i++)
    {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
            printf("Contains negative weight!");
    }
    
    print(distance, Vertex);
    
    return;
}


int main()
{
    //NEED TO IMPLEMENT TO WRITE TO TEXT FILE AND REWRITE FILE
    int Vertex = 6;  
    int Edge = 9;
    struct Graph* graph = New_graph(Vertex, Edge);
    
    // add edge 0-1
    graph->edge[0].source = 0;
    graph->edge[0].destination = 1; //to B
    graph->edge[0].weight = 3;
    
    // add edge 0-4
    graph->edge[1].source = 0;
    graph->edge[1].destination = 4; // to E
    graph->edge[1].weight = 1;
    
    // add edge 1-2
    graph->edge[2].source = 1;
    graph->edge[2].destination = 2;
    graph->edge[2].weight = 3;
    
    // add edge 1-5
    graph->edge[3].source = 1;
    graph->edge[3].destination = 5;
    graph->edge[3].weight = 1;
    
    // add edge 1-4
    graph->edge[4].source = 1;
    graph->edge[4].destination = 4;
    graph->edge[4].weight = 2;
    
    // add edge 2-3
    graph->edge[5].source = 2;
    graph->edge[5].destination = 3;
    graph->edge[5].weight = 2;
    
    // add edge 2-5
    graph->edge[6].source = 2;
    graph->edge[6].destination = 5;
    graph->edge[6].weight = 1;
    
    // add edge 4-5
    graph->edge[7].source = 4;
    graph->edge[7].destination = 5;
    graph->edge[7].weight = 3;
    
    // add edge 5-3
    graph->edge[8].source = 5;
    graph->edge[8].destination = 3;
    graph->edge[8].weight = 3;
    
    BellmanFord(graph, 0);
    
    return 0;
}
