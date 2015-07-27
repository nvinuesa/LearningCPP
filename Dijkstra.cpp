/* 
 * File:   Dijkstra.cpp
 * Author: Nico
 * 
 * Created on 1 de noviembre de 2013, 16:23
 */

#include <queue>
#include <vector>
#include <list>
#include "Dijkstra.h"
#include "Graph.h"
#include <iostream>
using namespace std;

Dijkstra::Dijkstra() {
    // G = g;
}

Dijkstra::~Dijkstra() {
}

double* Dijkstra::shortestPath(int source, int target, list<int>& path,Graph &G) {
    double *dist = new double[G.V()];
    bool visited[G.V()];
    int previous[G.V()];
    Edge e;
    int u; 
    double accum;
    priority_queue<Edge, vector<Edge>, mycomparison> minQueue;
    for(int i=0;i<G.V();i++) {
        dist[i] = INFINITE;  
        visited[i] = false;  
    }
    dist[source] = 0;
    e.destination = source;
    e.weight = dist[source];
    minQueue.push(e);
    while (!minQueue.empty()) {
        e = minQueue.top();
        u = e.destination;
        if(u==target) {
            path.push_front(u);
            while(u!=source) {
                path.push_front(previous[u]);
                u = previous[u];
            }
            break;
        }
        minQueue.pop();
        visited[u] = true;
        for(int i=0;i<G.neighbours(u).size();i++) {
            accum = dist[u] + G.get_edge_value(u,G.neighbours(u).at(i));
            if(accum<dist[G.neighbours(u).at(i)] && !visited[G.neighbours(u).at(i)]) {
                dist[G.neighbours(u).at(i)] = accum;
                previous[G.neighbours(u).at(i)] = u;
                e.destination = G.neighbours(u).at(i);
                e.weight = G.get_edge_value(u,G.neighbours(u).at(i));
                minQueue.push(e);
            }
        }
    }
    return dist;
}

mycomparison::mycomparison() {
}

bool mycomparison::operator() (const Edge& lhs, const Edge& rhs) const {
    return (lhs.weight>rhs.weight);
}

