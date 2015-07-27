#include "Graph.h"
#include "PriorityQueue.h"

class ShortestPath
{
   public:
     ShortestPath(); //Default Constructor
     ShortestPath(Graph &G, int start = 0); //Another constructor for a given graph G and starting vertex (default: 0)
     ~ShortestPath(); //Default Destructor
     void solve(Graph &G, int start = 0); // Using Dijkstra's algorithm, finds shortest paths to all vertices from start (default: 0)
     double path_length(int j); //gives length of shortest path from start to j
     std::vector <int> GetPath(int j); //Gets path from start to j

   private:
      std::vector <int> parent; //stores parent or prev of a vertex on its shortest path to start
      std::vector <double> lengthTo; //Stores shortest lengths to all vertices from vertex start
};
