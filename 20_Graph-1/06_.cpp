/*

GFG :: Topological sort

Topological Sort is a linear ordering of the vertices in a Directed Acyclic Graph (DAG)
such that for every directed edge `u → v`, vertex `u` comes before `v` in the ordering.

### Key Points:
- Works only on DAGs (no cycles).
- Used in tasks like scheduling,build systems,course prerequisites, etc.

### Example:
For a graph with edges:
```
A → B  
A → C  
B → D  
C → D
```
One possible topological sort: `A, B, C, D` or `A, C, B, D`

*/


#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
    
    void topoDfs(int src, unordered_map<int,bool>& vis, vector<int> adj[], vector<int>& ans) {
    
        vis[src] = true;
        
        for(auto nbr: adj[src]) {
            if(!vis[nbr]) {
                topoDfs(nbr,vis,adj,ans);
            }
        }
        
        //backtrack
        ans.push_back(src);
        
    }
    
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    unordered_map<int,bool> visited;
	    int n = V;
	    vector<int> ans;
	    
	    for(int i=0; i<n; i++) {
	        if(!visited[i]) {
	            topoDfs(i,visited,adj,ans);
	        }
	    }
	    //reverse the ordering
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};
