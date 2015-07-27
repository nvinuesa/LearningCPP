/* 
 * File:   MonteCarloShortestPath.cpp
 * Author: Nico
 * 
 * Created on 2 de noviembre de 2013, 18:18
 */
#include <vector>
#include <list>
#include <iostream>
#include "Dijkstra.h"
#include "Graph.h"
#include "GraphFactory.h"
#include "MonteCarloShortestPath.h"
#include "ShortestPath.h"
using namespace std;

MonteCarloShortestPath::MonteCarloShortestPath() : numberVertices(0),sparsityFactor(0),minEdgeWeight(0),maxEdgeWeight(0),numberOfSimulations(0) {
}

MonteCarloShortestPath::MonteCarloShortestPath(int n, double s, double min, double max, int len) {
    cout << "Monte Carlo simulation running Dijkstra's shortest path algorithm over " << len << " random graphs with " << n << " vertices each and a density of " << s << ". The minimum edge cost is: " << min << ", its maximum is: " << max << "." << endl;
    numberVertices = n;
    sparsityFactor = s;
    minEdgeWeight = min;
    maxEdgeWeight = max;
    numberOfSimulations = len;
    int sourceNode = 0;
    
    
    
    // Dijkstra *d;
    
    list<int> path;
    double* dist;
    Graph G(numberVertices);
    int avgCounter[numberVertices-1];
    double avgDist[numberVertices-1];
    for(int i=0;i<numberVertices-1;i++) {
        avgDist[i] = 0;
        avgCounter[i] = 0;
    }
    // Main loop.
    // Dijkstra d;
    ShortestPath SP;
    for(int i=0;i<numberOfSimulations;i++) {
        
        // GraphFactory factory(minEdgeWeight,maxEdgeWeight);
        // factory.newRandomGraph(G.V(),sparsityFactor,&G);    
        G.GenerateRandomGraph(minEdgeWeight,maxEdgeWeight,sparsityFactor);
        // dist =d.shortestPath(sourceNode,(G.V()-1),path,G);   
        // SP.solve(G);
//        for(int j=0;j<numberVertices-1;j++) {
//            if(dist[j+1]<INFINITE) {
//                avgDist[j] = avgDist[j] + dist[j+1];
//                avgCounter[j] += 1;
//            }
                
        }  
         // cout << G.get_edge_value(0,1) << endl;
//    }
//    for(int k=0;k<numberVertices-1;k++) {
//        avgDist[k] = avgDist[k] / static_cast<double> (avgCounter[k]);
//        cout << "Average shortest path from node " << sourceNode << " to node " << k+1  << ":" <<'\t' << avgDist[k] << endl;
//    }    
    cout << endl;
    // delete factory;
    // delete G;
}

MonteCarloShortestPath::~MonteCarloShortestPath() {
}

