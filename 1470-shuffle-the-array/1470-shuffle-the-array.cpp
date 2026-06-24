class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(2*n);
        int j=0;
        for(int i=0; i<(2*n); i++){
            if(i%2==0) result[i] = nums[j];
            else {
                result[i] = nums[j+n];
                j++;
            }
        }    
        return result;
    }
};