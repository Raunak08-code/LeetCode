class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> st;
        vector<int> cansee(n,0);
        cansee[n-1] = 0;
        st.push(heights[n-1]);

        for(int i=n-2; i>=0; i--){
            int count =0;
            //pop 
            while(st.size()>0 && st.top()<heights[i]){
                st.pop();
                count++;
            }
            //ans
            if(st.size() != 0)  count++;
            cansee[i] = count;
            //else cansee[i] = count++;
            //push
            st.push(heights[i]);
        }
        return cansee;
    }
};