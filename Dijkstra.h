/* 
 * File:   Dijkstra.h
 * Author: Nico
 *
 * Created on 1 de noviembre de 2013, 16:23
 */
#include "Graph.h"

#ifndef DIJKSTRA_H
#define	DIJKSTRA_H

const long INFINITE = 100000000; // Define infinity with a real value.
class Graph; // Forward declaration of Graph class. 
class Edge; // Forward declaration of Graph class. 

/* Dijkstra shortest path algorithm implementation. For this implementation, a 
 * min heap is used via the queue container from the stl. 
 */
class Dijkstra {

public:
    Dijkstra();
    virtual ~Dijkstra();
    
    double* shortestPath(int source, int target, std::list<int>& path,Graph& G);
private:
    // Graph G;
};

/* In order to create a min heap using the queue container, we have to create
 * our own comparison (which is std::greater by default in the stl container) 
 * which will take as arguments our own Edge objects.
 */
class mycomparison {
public:
    mycomparison();
    bool operator() (const Edge& lhs, const Edge& rhs) const;
};

#endif	/* DIJKSTRA_H */



