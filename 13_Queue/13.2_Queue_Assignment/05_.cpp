//Leetcode 933 : number-of-recent-calls

class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        //push the new req.
        q.push(t);

        while(!q.empty() && q.front()<(t-3000)) q.pop(); //removes old reqs

        //return all the recent req. within the range
         return q.size();

    }
};
