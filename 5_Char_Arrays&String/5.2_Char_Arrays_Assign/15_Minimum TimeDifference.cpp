//Leetcode: 539. Minimum Time Difference

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
    vector<int> minutes;

    for(int i=0;i<timePoints.size();i++){
        int hours =  stoi(timePoints[i].substr(0, 2));  
        int mins = stoi(timePoints[i].substr(3, 2));
        int totalTime = hours * 60 + mins;
        minutes.push_back(totalTime);
    }
   
    // Sort the minutes
    sort(minutes.begin(), minutes.end());
        
    int minDiff = INT_MAX;
     
    // Check adjacent differences
    for (int i = 1; i < minutes.size(); i++)
    {
      minDiff = min(minDiff, minutes[i] - minutes[i-1]);
    }
      // Check wrap-around (e.g., 23:59 to 00:01)
     minDiff = min(minDiff,24*60-minutes.back()+minutes[0]);

     return minDiff;

    }
};