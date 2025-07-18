// Leetcode :2125. Number of Laser Beams in a Bank

class Solution {
public:
    int countDevices(string &row){
        int c=0;
        for(auto it : row){
            c+=it-'0';
        }
        return c;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int>devices;
        for(auto rows:bank){
            devices.push_back(countDevices(rows));
        }
        int totalBeams=0;
        for(int i=0;i<devices.size();i++){

           if(devices[i]>0){  // Only process rows with devices
                int j = i + 1;
                while(j<devices.size()){
                    if(devices[j] > 0){  // Found next row with devices
                        totalBeams += devices[i] * devices[j];
                        break;  // Connect only to immediate next row with devices
                    }
                    j++;  // Move to next row if current has no devices
                }
            }
        }
        return totalBeams;
    }
};