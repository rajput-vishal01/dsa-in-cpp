/*
Graph: A combination of two components—nodes and edges—that together form a complete structure.
In a graph, edges can be either directed or undirected.

The difference between a tree and a graph is that a tree has a hierarchical (or constrained) structure without cycles, whereas a graph can include cycles and multiple connections.
Every tree is a graph, but not every graph is a tree.

Important questions:
- Clone graph
- Clone tree
- Check whether a graph is a tree

Types of graphs:
- Directed and weighted graph (weights may be optional)
- Undirected and weighted graph (weights may be optional)

Degree:
- In-Degree: The number of edges directed into a vertex.
- Out-Degree: The number of edges directed out from a vertex.

Cyclic graph:
- A graph that contains at least one cycle.

Ways to Create a graphs::

--Bad way to create a Graph -> adjacency matrix 
      -- 2 array : where 0 means disconnected and 1 means connected


--Good way to create a Graph -> adjacency list
      -- uses key value mapping where the node is stored as key and to nodes which its connected are stored as values (could be multiple).
      -- So these Key value pairs could be stored in a vector or list
 
*/
#include <iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph {
  public:
    unordered_map<int,list<int> > adjList;

    void addEdge(int u, int v, bool direction) {
      //direction = 0 -> undirected graph
      //direction = 1 => directed graph
      if(direction == 0) {
        adjList[u]. push_back(v);
        adjList[v].push_back(u);
      }
      else {
        //directed edge
        adjList[u].push_back(v);
      }
    }

    void printAdjList(int n) {

      for(int i=0; i<n; i++) {
        cout << i << ": ";
        cout << "{ ";
        list<int> temp = adjList[i];
        for(auto j:temp) {
          cout << j <<", ";
        }
        cout << "}" << endl;
      }

      // It will not print empty nodes but prefer this
      // for(auto i: adjList) {
      //   cout << i.first << ": ";
      //   cout << " {";
      //   for(auto j: i.second) {
      //     cout << j <<", ";
      //   }
      //   cout << "}" << endl;
      // }
    }

};

int main() {
  Graph g;
  g.addEdge(0,1,1);
  g.addEdge(0,2,1);
  g.addEdge(1,2,1);
  g.addEdge(2,3,1);
  int n = 4;
  g.printAdjList(n);
  return 0;
}