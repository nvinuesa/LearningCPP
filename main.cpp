/* 
 * File:   main.cpp
 * Author: Nico
 *
 * Created on 18 de octubre de 2013, 19:31
 * Version 1
 */

#include <iostream>
#include <queue>
#include "Graph.h"
#include "GraphFactory.h"
#include "Dijkstra.h"
#include "MonteCarloShortestPath.h"
using namespace std;


int main() 
{
    
//    // First Monte Carlo simulation (0.2 graph density)
//    MonteCarloShortestPath first(50,1.2,1.0,10.0,10000);
//    // Second Monte Carlo simulation (0.4 graph density)
//    MonteCarloShortestPath second(50,0.4,1.0,10.0,1000);
    clock_t tStart = clock(); //Start time - Used to find the time taken to compute
    MonteCarloShortestPath first(50,0.2,1.0,10.0,10000);
    
//    Graph G(50);
//    for(int i=0;i<10000;i++) {
//        G.GenerateRandomGraph(1,10,0.4);
//        
//        // cout << G.get_edge_value(0,1) << ' ' << endl;
////        for (int i=0; i<G.neighbours(0).size(); i++) 
////                cout << G.neighbours(0).at(i) << ' ' ;
//        //G.clear();
//    }  
    cout<<"Time taken: "<< (double) (clock() - tStart) / CLOCKS_PER_SEC <<" seconds"<<endl;
//    for(int i=0;i<2;i++) {
//        Graph *G=new Graph(6);
//        f.newRandomGraph(G->V(),0.8,G);
//        cout << G->get_edge_value(0,1) << ' ';
//        for (int i=0; i<G->neighbours(0).size(); i++) 
//                cout << G->neighbours(0).at(i) << ' ' ;
//        G->clear();
//    }

    return 0;
}

