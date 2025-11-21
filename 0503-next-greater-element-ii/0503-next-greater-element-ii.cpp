class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> result(n,-1);

        // for(int i= n-1 ; i>=i+1 ; i--){
        //     curr = nums[i];
        //     while(st.size()>0 && st.top()<nums[i]){
        //         st.pop();
        //     }

        //     if(st.size() == 0) result[i] = -1;
        //     else result[i] = st.top();

        //     st.push(nums[i]);
        // }

        for(int i =2*n-1; i>=0 ; i--){
            int curr = nums[i%n];
            while(st.size()>0 && st.top()<=curr){
                st.pop();
            } 
            if(st.size() > 0) result[i%n] = st.top();

            st.push(curr);
        }
        return result;
    }
};