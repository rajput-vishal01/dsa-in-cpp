// leetcode 983. Minimum Cost For Tickets

class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int i){
        //base case
        if(i >= days.size()) return 0;

        //1 day pass taken
        int cost1 = costs[0]+solve(days,costs,i+1);

        //7 days pass taken
        int passEndDay=days[i]+6; //as pass starts from that day to emd to the week
        int j=i;
        while(j<days.size() && days[j] <= passEndDay ){
            j++;
        }
        int cost2 = costs[1]+solve(days,costs,j);

        //30 days pass taken
        passEndDay=days[i]+29; //as pass starts from that day to emd to the month
        j=i;
        while(j<days.size() && days[j] <= passEndDay ){
            j++;
        }
        int cost3 = costs[2]+solve(days,costs,j);

        return min(cost1,min(cost2,cost3));
    }

    int solveTD(vector<int>& days, vector<int>& costs,int i,vector<int>&dp){
        //base case
        if(i >= days.size()) return 0;

        if(dp[i] != -1 ) return dp[i];

        //1 day pass taken
        int cost1 = costs[0]+solveTD(days,costs,i+1,dp);

        //7 days pass taken
        int passEndDay=days[i]+6; //as pass starts from that day to emd to the week
        int j=i;
        while(j<days.size() && days[j] <= passEndDay ){
            j++;
        }
        int cost2 = costs[1]+solveTD(days,costs,j,dp);

        //30 days pass taken
        passEndDay=days[i]+29; //as pass starts from that day to emd to the month
        j=i;
        while(j<days.size() && days[j] <= passEndDay ){
            j++;
        }
        int cost3 = costs[2]+solveTD(days,costs,j,dp);

        dp[i] = min(cost1,min(cost2,cost3));
        return dp[i];
    }

    int solveBU(vector<int>& days, vector<int>& costs,int i,vector<int>&dp){
        //base case
        dp[days.size()] = 0;

        for(int i=days.size()-1;i>=0;i--){
            //1 day pass taken
            int cost1 = costs[0]+dp[i+1];

            //7 days pass taken
            int passEndDay=days[i]+6; //as pass starts from that day to emd to the week
            int j=i;
            while(j<days.size() && days[j] <= passEndDay ){
                j++;
            }
            int cost2 = costs[1]+dp[j];

            //30 days pass taken
            passEndDay=days[i]+29; //as pass starts from that day to emd to the month
            j=i;
            while(j<days.size() && days[j] <= passEndDay ){
                j++;
            }
            int cost3 = costs[2]+dp[j];
            dp[i] = min(cost1,min(cost2,cost3));
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i=0;
        // return solve(days,costs,i);
        // vector<int>dp(days.size(),-1);
        // return solveTD(days,costs,i,dp);
        vector<int>dp(days.size()+1,-1);
        return solveBU(days,costs,i,dp);
    }
};