/* 
 * File:   GraphFactory.cpp
 * Author: Nico
 * 
 * Created on 1 de noviembre de 2013, 12:44
 */

#include <cstdlib> //needed for rand().
#include <iostream> //needed for time().
#include "GraphFactory.h"
#include "Graph.h"
using namespace std;

inline double GraphFactory::prob() {return (rand() % 100) / 100.0;}

GraphFactory::GraphFactory() : minEdgeWeight(0), maxEdgeWeight(1) {
}

GraphFactory::GraphFactory(double min, double max) {
    minEdgeWeight=min;
    maxEdgeWeight=max;
    srand(time(0)); // Seed the rand() function, when constructing the object.
    
}

GraphFactory::~GraphFactory() {
}

void GraphFactory::newRandomGraph(int n, double edgeProb,Graph* G) {
    // Graph* G = new Graph(n);
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            if(i!=j && prob()<edgeProb) {
                double w = minEdgeWeight+ (prob()*(maxEdgeWeight-minEdgeWeight));
                G->set_edge_value(i,j,w);
            }           
        }
    }
    // return G;
}