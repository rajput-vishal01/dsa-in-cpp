/*

Weighted Graphs: 

Adj List ::  
eg:
0 -> {(1,3),(2,4)}
to -> {(form, weight),(form, weight)}



V.V.V.V.V Imp -> BFS AND DFS : 

*/


#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph {
  public:
    //first int -> u
    //second int -> v
    //third int -> wt
    unordered_map<int,list< pair<int,int>  > > adjList;

    void addEdge(int u, int v, int weight, bool direction) {
      //direction = 0 -> undirected graph
      //direction = 1 => directed graph
      if(direction == 0) {
        adjList[u]. push_back({v,weight});
        adjList[v].push_back({u,weight});
      }
      else {
        //directed edge
        adjList[u].push_back({v,weight});
      }
    }

    void printAdjList(int n) {

      for(int i=0; i<n; i++) {
        cout << i << ": ";
        cout << "{ ";
        list< pair<int,int> > temp = adjList[i];
        for(auto j:temp) {
          //j is a pair here
          cout <<"("<<j.first<<","<<j.second<<"), ";
        }
        cout << "}" << endl;
      }
    }

    /*
    

Breadth-First Search (BFS):

Concept:
BFS explores the graph level by level. It starts at the source node, visits all its immediate neighbors, then moves to the neighbors' neighbors, and so on. 
This approach is useful for finding the shortest path in unweighted graphs.

Implementation in Code:
In your code, the bfsTraversal() function uses a queue to store nodes that need to be processed. 
It marks nodes as visited to avoid reprocessing them. The process continues until the queue is empty.


    */

    void bfsTraversal(int src) {
      queue<int> q;
      unordered_map<int,bool> visited;

      //initial state
      q.push(src);
      visited[src] = true;

      while(!q.empty()) {
        int frontNode = q.front();
        cout << frontNode <<", ";
        q.pop();

        for(auto neighbour: adjList[frontNode]) {
          //neighbour -> pair
          //first -> node
          //second -> weight
          int node = neighbour.first;
          int weight = neighbour.second;
          if(!visited[node]) {
            q.push(node);
            visited[node] = true;
          }
        }

      }
    cout << endl;

    }

/*


Depth-First Search (DFS):

Concept:
DFS goes as deep as possible down one path before backtracking. It starts at a source node and recursively visits an 
unvisited neighbor, following each branch to its end before moving back and checking other branches. This approach is useful for tasks like pathfinding or detecting cycles.

Implementation in Code:
In your code, the dfsTraversal() function uses a helper dfsHelper() that performs the 
recursive traversal. It marks each visited node to prevent revisiting.

*/

    void dfsHelper(int src, unordered_map<int,bool>& visited) {
      visited[src] = true;
      cout << src << ", ";

      for(auto nbr: adjList[src] ) {
        //nbr -> pair
        //first-> node
        //second -> weight 
        int node = nbr.first;
        if(!visited[node] ) {
          dfsHelper(node, visited);
        }
      }
    }

    void dfsTraversal(int n) {
      unordered_map<int,bool> visited;

      for(int src=0; src < n; src++) {
        if(!visited[src])
          dfsHelper(src, visited);
      }
      
    }
  
    /*
    Method 2: 

    DFS using Stack: 

    Concept:
    The DFS using a stack replaces recursion by explicitly managing the nodes to visit. Start with the initial node on the stack.
    While the stack isn’t empty, pop a node, process it if it hasn't been visited, and push its unvisited neighbors (in reverse order to mimic recursion).

    Implementation:
    1.Initialize a stack with the starting node and a visited map.
    2.Loop: Pop a node from the stack. If not visited, mark and process it.
    3.Push: For each unvisited neighbor, push it onto the stack.
    */
    void dfsUsingStack(int start, int n) {
      unordered_map<int, bool> visited;
      stack<int> s;
  
      // Start DFS from the starting node
      s.push(start);
  
      while(!s.empty()) {
          int current = s.top();
          s.pop();
  
          if (!visited[current]) {
              cout << current << ", ";
              visited[current] = true;
          }
  
          // Push all unvisited neighbors onto the stack.
          // Iterating in reverse order to mimic typical DFS recursive behavior.
          for(auto it = adjList[current].rbegin(); it != adjList[current].rend(); it++) {
              int neighbour = it->first;
              if (!visited[neighbour]) {
                  s.push(neighbour);
              }
          }
      }
      cout << endl;
  }
  

};

int main() {
  Graph g;
  // g.addEdge(0,1,3,1);
  // g.addEdge(0,2,4,1);
  // g.addEdge(1,2,1,1);
  // g.addEdge(2,3,16,1);
  g.addEdge(0,3,3,1);
  g.addEdge(0,5,3,1);
  g.addEdge(0,2,3,1);
  g.addEdge(2,5,3,1);
  g.addEdge(3,5,3,1);
  g.addEdge(5,4,3,1);
  g.addEdge(5,6,3,1);
  g.addEdge(4,1,3,1);
  g.addEdge(6,1,3,1);
  int n = 7;
  g.printAdjList(n);
  cout << endl << "DFS: " ;
  g.dfsTraversal(7);
  cout << endl << "DFS Using Stack: " ;
  g.dfsUsingStack(0,7);
  return 0;
}