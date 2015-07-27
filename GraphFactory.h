/* 
 * File:   GraphFactory.h
 * Author: Nico
 *
 * Created on 1 de noviembre de 2013, 12:44
 */

#ifndef GRAPHFACTORY_H
#define	GRAPHFACTORY_H

class Graph; // Forward declaration of Graph class.

/* Random graph generation object. It takes as arguments the number of vertices,
 * the graph's density, and minimum and maximum edge weights.
 * The inline function prob() will use cstdlib's rand() to generate a random
 * number between 0 and 1.
 */
class GraphFactory {
public:
    GraphFactory();
    GraphFactory(double min, double max);
    virtual ~GraphFactory();
    
    void newRandomGraph(int n, double edgeProb, Graph* G);
    double prob();
private:
    double minEdgeWeight, maxEdgeWeight;
};

#endif	/* GRAPHFACTORY_H */

