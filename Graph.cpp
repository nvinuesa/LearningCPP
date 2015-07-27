/* 
 * File:   Graph.cpp
 * Author: Nico
 * 
 * Created on 25 de octubre de 2013, 19:34
 */

#include "Graph.h"
#include <vector>
#include <list>
#include <iostream>
using namespace std;

Graph::Graph() : nVertex(0),nEdges(0) {
}

Graph::Graph(int n) {
    nVertex = n;    
    nEdges = 0;
    
    srand(time(0)); // Seed the rand() function, when constructing the object.
    
    vector<Edge> list;
    vector<bool> conn(nVertex,0);
    // connMatrix = new vector<bool>[nVertex];
    for (int i = 0; i < nVertex; i++) {
        adjList.push_back(list);
        connMatrix.push_back(conn);
    }
}

Graph::~Graph() {
//    delete &e;
//    delete[] &adjList;
//    delete[] &connMatrix;
}

int Graph::V() {
    return nVertex;
}

int Graph::E() {
    return nEdges;
}

bool Graph::adjacent(int x, int y) {
    return connMatrix[x][y];
}

vector<int> Graph::neighbours(int x) {
    vector<int> listOfNeighbours;
    for (std::vector<Edge>::iterator it = adjList[x].begin(); it != adjList[x].end(); it++) 
        listOfNeighbours.push_back(it->destination);
    return listOfNeighbours;
}

double Graph::get_edge_value(int x, int y) { 
    for (std::vector<Edge>::iterator it = adjList[x].begin(); it != adjList[x].end(); it++) {
        if(it->destination==y)
            return it->weight;
    }
}

void Graph::set_edge_value(int x, int y, double w) {  
    if( x<nVertex && y<nVertex  ) {
        Edge e;
        e.destination = y;
        e.weight = w;
        // Fill the adjacency matrix. As we are dealing with undirected graph, 
        // this matrix should be symmetrical, hence the second line:
        connMatrix[x][y] = true; 
        connMatrix[y][x] = true; 
        // Idem for the edge list:
        adjList[x].push_back(e);
        e.destination = x;
        adjList[y].push_back(e);
        nEdges+=1;
    }
}

void Graph::clear() {
    adjList.clear();
    connMatrix.clear();
}

void Graph::GenerateRandomGraph(double minEdgeWeight, double maxEdgeWeight, double EdgeDensity) {
    adjList.clear();
    connMatrix.clear();   
    vector<Edge> list;
    vector<bool> conn(nVertex,0);
    for (int i = 0; i < nVertex; i++) {
        adjList.push_back(list);
        connMatrix.push_back(conn);
    }
    for(int i=0;i<nVertex;i++) {
        for(int j=i;j<nVertex;j++) {
            if(i!=j && prob()<EdgeDensity) {
                double w = minEdgeWeight+ (prob()*(maxEdgeWeight-minEdgeWeight));
                this->set_edge_value(i,j,w);
            }           
        }
    }
    
}

inline double Graph::prob() {return (rand() % 100) / 100.0;}

Edge::Edge() : destination(0),weight(0) {
}
