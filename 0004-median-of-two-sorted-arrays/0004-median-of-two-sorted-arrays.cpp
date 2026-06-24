class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0; i<n; i++){
            merged.push_back(nums1[i]);
        }
        for(int i=0; i<m; i++){
            merged.push_back(nums2[i]);
        }

        sort(merged.begin(), merged.end());
        int mid = merged.size()/ 2;
        if(merged.size()%2 != 0) return (double) merged[mid];
        else    return (double) (merged[mid]+merged[mid-1])/2;
    }
};