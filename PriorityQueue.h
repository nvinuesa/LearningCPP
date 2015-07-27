#ifndef GUARD_PriorityQueue_H
#define GUARD_PriorityQueue_H

//Header file of Priority Queue implemented using a vector
//This implements special priority queue called "indexed priority queue" where we can change the priority of any element in constant time
//Minimum of the queue is always at the head, so accessed and deleted in constant time (a required operation in Djikstra's algorithm)
//Another useful operation for Dijkstra's algorithm is changing priority. 
//This is implemented in the function "update(...)". After changing priority, the minheap property is restored in O(log n) time
//REMARK: If maximum size of the queue is known at construction time, then we can use an vector or array to save the indices, 
// else we use the STL map to save the indices

#include <cstdlib>
#include <vector>
#include <map>

//Define the element that is inserted into the queue
struct element {
    int node;      //node - used as the index in the priority queue
    double length; //length of the current shortest path to node (used to compare elements)
};

class PriorityQueue
{
  public:
    PriorityQueue(); //Default constructor
    PriorityQueue(int MAXSIZE); //Another constructor, allocates MAXSIZE to the queue
    ~PriorityQueue(); //destructor
    bool isEmpty(); //checks if the queue is empty
    size_t size(); //returns size of the queue
    void insert(element n); //Add an element
    element delmin(); //deletes minimum
    void update(int node, double length); //Changes value of node to length 
    void print();

  private:
    std::vector <element> heap; //stores the heap
    std::vector <int> index; //keeps track of where the elements are in the heap
    std::map <int, int> indexmap; //same as index
    bool indexmap_on; //decides if index or indexmap should be used

    //Private functions used to maintain heap property
    void sink(int pos); //sinks a heavy element down the queue 
    void swim(int pos); //floats a lighter element up the queue
};

#endif // GUARD_PriorityQueue_H
