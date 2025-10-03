//leetcode 1823: find-the-winner-of-the-circular-game

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        
        //put everyone in queue
        for(int i=1;i<=n;i++){
            q.push(i);
        }

        //simulate the game
        while(q.size()> 1){
            // Rotate k-1 people to the back
            for(int i = 1; i < k; i++){
                int elem = q.front();
                q.pop();
                q.push(elem);
            }
            // Remove the k-th person
            q.pop();
        }

        return q.front();
        
    }
};