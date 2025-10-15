class Solution {
public:

    int nextGreaterToJ(vector<int>& arr, int j){
        for(int m=j+1; m<arr.size(); m++){
            if(arr[j]<arr[m]) return arr[m];
        }
        return -1;
    }    

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());

        for(int i =0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    int x = nextGreaterToJ(nums2,j);
                     ans[i] = x;
                    break;
                }
            }
        }
        return ans;
    }
};