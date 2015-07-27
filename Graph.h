/* 
 * File:   Graph.h
 * Author: Nico
 *
 * Created on 25 de octubre de 2013, 19:34
 */

#ifndef GRAPH_H
#define	GRAPH_H

#include <vector>
#include <list>

class Edge; // Forward declaration of Graph class. 

/* Edge class, which only needs a destination vertex, because it will be 
 * used in an adjacency list.
 */

class Edge {
public:
    int destination;
    double weight;
    Edge();
};

/* My graph objects implementation. Here i implement each graph using an
 * adjacency list and also a connectivity matrix (for faster verification of
 * edge existence between two vertices).
 */
class Graph {
public:
    Graph();
    Graph(int n);
    virtual ~Graph();
    
    int V();
    int E();
    bool adjacent(int x, int y);
    std::vector<int> neighbours(int x);
    int get_node_value();
    void set_node_value();
    double get_edge_value(int x, int y);
    void set_edge_value(int x, int y, double w);
    void GenerateRandomGraph(double minEdgeWeight, double maxEdgeWeight, double EdgeDensity);
    double prob();
    void clear();
private:
    int nVertex;
    int nEdges;
    Edge e;
    std::vector< std::vector<Edge> > adjList;
    std::vector< std::vector<bool> > connMatrix;
};



#endif	/* GRAPH_H */

