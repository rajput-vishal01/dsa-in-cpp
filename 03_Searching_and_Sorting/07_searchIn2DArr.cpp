/*Leetcode :- 74. Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity. 



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row=matrix.size();
        int col = matrix[0].size();

        int n = row*col;

        int s=0;
        int e = n-1;
        int mid = s+(e-s)/2;

        while(s<=e){
            //finding rowIndex and colIndex using mid
            //this is the only diff in 2d array
            int rowIndex=mid/col;
            int colIndex=mid%col;

            if(matrix[rowIndex][colIndex]==target){
                return true;
            }
            else if (target >matrix[rowIndex][colIndex]){
                //move right
                s=mid+1;
            }
            else{
                //move left
                e=mid-1;
            }
             mid = s+(e-s)/2;
        }
        return false;
        
    }
};















*/