// Leetcode 871. Minimum Number of Refueling Stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops=0;
        int dist=0;

        priority_queue<pair<int,int>>pq; //{fuel,pos}
        int fuel = startFuel;

        int i=0;
        while(true){
            while(i<stations.size()){
                //push stations within my reach at my current level
                if(stations[i][0] <= dist+fuel){
                    pq.push({stations[i][1],stations[i][0]});
                }else{
                    break;
                }
                ++i;
            }

            //reached
            if(dist + fuel >= target) return stops;

            //no station to reach
            if(pq.empty()){
                return -1;
            }

            //refuel
            auto top = pq.top(); pq.pop();
            fuel = (dist + fuel - top.second) + top.first;
            dist = top.second;
            ++stops;
        }

        return stops;
    }
};
