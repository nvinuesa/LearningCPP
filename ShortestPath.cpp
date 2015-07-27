#include "ShortestPath.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

//Default Constructor
ShortestPath::ShortestPath()
{
}

//Another Constructor
ShortestPath::ShortestPath(Graph &G, int start)
{
   solve(G, start);
}

//Default Destructor
ShortestPath::~ShortestPath()
{
}

//Finds the shortest paths from the given vertex start to all the vertices using Dijkstra's algorithm
void ShortestPath::solve(Graph &G, int start)
{
    int numnodes = G.V();
    parent.clear();
    lengthTo.clear();
    for(int i = 0; i < numnodes; i++) {
       parent.push_back(-1); 
       lengthTo.push_back(INFINITY);
    }
    
    PriorityQueue PQ(numnodes); //An indexed priority queue whose MAXSIZE is numnodes
    PQ.update(start, 0);

    while(!PQ.isEmpty()) {
      element popped = PQ.delmin();
      int curr_node = popped.node;
      lengthTo[curr_node] = popped.length; 
      vector <int> neighbours = G.neighbours(curr_node);

      for(size_t j = 0; j < neighbours.size(); j++) { //for every neighbour
          double length = popped.length + G.get_edge_value(curr_node, neighbours[j]);
          if(length < lengthTo[neighbours[j]]) {
             PQ.update(neighbours[j], length);
             lengthTo[neighbours[j]] = length;
             parent[neighbours[j]] = curr_node;
         }
      } 
    }
}

//returns the length of shortest path from start to j
double ShortestPath::path_length(int j)
{
   return lengthTo[j];
}

//Gets the shortest path from 0 to j
vector <int> ShortestPath::GetPath(int j)
{
   stack <int> reverse_path;
   while(parent[j] != -1) {
      reverse_path.push(j);
      j = parent[j];
   }
   reverse_path.push(j);

   vector <int> path;
   while(!reverse_path.empty()) {
       path.push_back(reverse_path.top());
       reverse_path.pop();
   }
   return path;
}
