/* 
 * File:   MonteCarloShortestPath.h
 * Author: Nico
 *
 * Created on 2 de noviembre de 2013, 18:18
 */

#ifndef MONTECARLOSHORTESTPATH_H
#define	MONTECARLOSHORTESTPATH_H

/* MonteCarloShortestPath objects are the main workflow for this assignment. 
 * It implements a Monte Carlo simulation by generating several random graphs of
 * the same number of vertices, minimum and maximum edge weights and graph 
 * density. 
 * In the main loop, a random graph is created using our GraphFactory class and
 * the shortest path for each vertex is computed.
 */
class MonteCarloShortestPath {
public:
    MonteCarloShortestPath();
    MonteCarloShortestPath(int n=0, double s=1, double min=1.0, double max=10.0, int len=1);
    virtual ~MonteCarloShortestPath();
private:
    double sparsityFactor;
    int numberVertices;
    double minEdgeWeight;
    double maxEdgeWeight;
    int numberOfSimulations;
};

#endif	/* MONTECARLOSHORTESTPATH_H */

