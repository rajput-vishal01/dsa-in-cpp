// leetcode 1878: Get Biggest Three Rhombus Sums in a Grid

class Solution {
public:
    
    bool checkBounds(vector<vector<int>>& grid, vector<pair<int,int>> v){
        int m = grid.size();
        int n = grid[0].size();

        for(auto pt : v){
            if(pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n){
                return false;
            }
        }
        return true;
    }

    bool getAllVertice(vector<vector<int>>& grid, vector<pair<int,int>>& v, pair<int,int> c, int delta){
        pair<int,int> A(c.first - delta, c.second);
        pair<int,int> B(c.first, c.second + delta);
        pair<int,int> C(c.first + delta, c.second);
        pair<int,int> D(c.first, c.second - delta);

        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;

        if(checkBounds(grid, v)){
            return true;
        }
        return false;
    }

    void getAllSum(vector<vector<int>>& grid, int cx, int cy, priority_queue<int>& pq){
        pq.push(grid[cx][cy]);
        int delta = 1;

        vector<pair<int,int>> v(4);

        while(getAllVertice(grid, v, {cx, cy}, delta)){
            int cSum = 0;

            // collect boundary points in diamond
            int x = v[0].first, y = v[0].second;
            while(x != v[1].first && y != v[1].second){
                x++; y++;
                cSum += grid[x][y];
            }

            x = v[1].first; y = v[1].second;
            while(x != v[2].first && y != v[2].second){
                x++; y--;
                cSum += grid[x][y];
            }

            x = v[2].first; y = v[2].second;
            while(x != v[3].first && y != v[3].second){
                x--; y--;
                cSum += grid[x][y];
            }

            x = v[3].first; y = v[3].second;
            while(x != v[0].first && y != v[0].second){
                x--; y++;
                cSum += grid[x][y];
            }

            pq.push(cSum);
            delta++;
        }
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        priority_queue<int> pq;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                getAllSum(grid, i, j, pq);
            }
        }

        unordered_set<int> unique;
        while(!pq.empty() && unique.size() < 3){
            int val = pq.top(); pq.pop();
            if(unique.count(val) == 0){
                unique.insert(val);
                ans.push_back(val);
            }
        }

        return ans;
    }
};
