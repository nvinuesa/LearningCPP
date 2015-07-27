#include "PriorityQueue.h"
#include <iostream>
#include <vector>
using namespace std;

//Default constructor
PriorityQueue::PriorityQueue()
{
   element n; n.node = -1; n.length = -1;
   heap.push_back(n); // 0-th element won't be used in the heap
   indexmap_on = true;
}

//Another constructor
PriorityQueue::PriorityQueue(int MAXSIZE)
{
   element n; n.node = -1; n.length = -1;
   heap.push_back(n); // 0-th element won't be used in the heap
   for(int i = 0; i < MAXSIZE; i++) index.push_back(-1);
   indexmap_on = false;
}

//Default destructor
PriorityQueue::~PriorityQueue()
{
}

// checks if heap is empty
bool PriorityQueue::isEmpty()
{
    return heap.size() == 1; //In our implementation, heap always has the 0-th element
}

//returns size of the heap
size_t PriorityQueue::size()
{
  return heap.size()-1; //Since 0-th element is not counted
}

//Inserts a new element into the heap
void PriorityQueue::insert (element n)
{
  heap.push_back(n);
  int N = heap.size() - 1;//location of the newly added last element
  if(!indexmap_on) index[n.node] = N; //update index
  else indexmap[n.node] = N;
  swim(N);
}

//Deletes the minimum element which is at heap[1];
element PriorityQueue::delmin()
{
  element n;
  if(!isEmpty()) {
     n = heap[1];
     heap[1] = heap[heap.size()-1]; //Exchange heap[1] with the last element
     if(!indexmap_on) {
        index[heap[1].node] = 1; //update index
        index[n.node] = -1;      //delete the last element
     }
     else {
        indexmap[heap[1].node] = 1;  //update indexmap
        indexmap.erase(n.node); //delete the last element
     }
     heap.erase(heap.end()-1);
     if (heap.size() > 2) sink(1);
  }
  else cout<<"Trying to delete from empty heap "<<endl;
  return n;
}

//Swims a light element up the heap
void PriorityQueue::swim(int pos)
{
  while( pos >= 2 && (heap[pos].length < heap[pos/2].length)) { //while the parent is not lighter
     if(!indexmap_on) {
        index[heap[pos/2].node] = pos;
        index[heap[pos].node] = pos/2;
     }
     else {
        indexmap[heap[pos/2].node] = pos;
        indexmap[heap[pos].node] = pos/2;
     }
     element temp = heap[pos/2];
     heap[pos/2] = heap[pos];
     heap[pos] = temp;
     pos = pos/2;
  }
}

//Sinks a heavy element down the heap
void PriorityQueue::sink(int pos)
{
   int N = heap.size();
   while((2*pos < N && heap[2*pos].length < heap[pos].length) || (2*pos+1 < N && heap[2*pos+1].length < heap[pos].length)) { //while the children are lighter
      if(2*pos + 1 >= N || heap[2*pos].length < heap[2*pos+1].length) {
          if(!indexmap_on) {
             index[heap[2*pos].node] = pos;
             index[heap[pos].node] = 2*pos;
          }
          else {
             indexmap[heap[2*pos].node] = pos;
             indexmap[heap[pos].node] = 2*pos;
          }
          element temp = heap[2*pos];
          heap[2*pos] = heap[pos];
          heap[pos] = temp;
          pos = 2*pos;
      }
     else {
          if(!indexmap_on) {
             index[heap[2*pos+1].node] = pos;
             index[heap[pos].node] = 2*pos+1;
          }
          else {
             indexmap[heap[2*pos+1].node] = pos;
             indexmap[heap[pos].node] = 2*pos+1;
          }
          element temp = heap[2*pos+1];
          heap[2*pos+1] = heap[pos];
          heap[pos] = temp;
          pos = 2*pos+1;
     }
   }
}

//change priority or updates
void PriorityQueue::update(int node, double length)
{
   //index[i] has the location of node i in the heap
   if(!indexmap_on) {
       if(index[node] != -1 && length < heap[index[node]].length) { //if node exists, update
          heap[index[node]].length = length;
          swim(index[node]);
       }
       else if (index[node] == -1) { //if doesn't exist, add new
          element temp; temp.node = node; temp.length = length;
          insert(temp);
       }
   }
   else {
       if(indexmap.find(node) != indexmap.end() && length < heap[indexmap[node]].length) { //if node exists, update
          heap[indexmap[node]].length = length;
          swim(indexmap[node]);
       }
       else if (indexmap.find(node) == indexmap.end()) { //if doesn't exist, add new
          element temp; temp.node = node; temp.length = length;
          insert(temp);
       }
   }
}

//Prints the heap, mainly for DEBUGGING purpose
void PriorityQueue::print()
{
  for(size_t j = 0; j < heap.size(); j++)
  {
     cout<<heap[j].node<<" "<<heap[j].length<<endl;
  }
  cout<<endl;
}
