// gfg : merge two binary max heaps

class Solution {
  public:
    void heapify(vector<int>& c, int i, int n) {
        int largest = i;
        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;
        
        if(leftChild < n && c[leftChild] > c[largest]) {
            largest = leftChild;
        }
        
        if(rightChild < n && c[rightChild] > c[largest]) {
            largest = rightChild;
        }
        
        if(largest != i) {
            swap(c[i], c[largest]);
            heapify(c, largest, n);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> c(a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());
        
        for(int i = c.size()/2 - 1; i >= 0; --i) {
            heapify(c, i, c.size());
        }
        
        return c;
    }
};
