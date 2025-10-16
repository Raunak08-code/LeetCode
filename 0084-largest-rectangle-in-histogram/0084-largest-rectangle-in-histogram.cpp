class Solution {
public:
// fun for previous smaller element....
    vector<int> previousSmaller(vector<int>& arr){
        stack<int> st;
        vector<int> psi(arr.size());
        psi[0]=-1;
        st.push(0);

        for(int i=1; i<arr.size(); i++){
            //pop
            while(st.size()>0 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            //ans
            if(st.size() ==  0) psi[i]=-1;
            else psi[i] = st.top();
            //push
            st.push(i);
        }
        return psi;
    }

// next smaller element..
    vector<int> nextSmaller(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nsi(n);
        nsi[n-1]=n;
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(st.size()>0 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            //ans
            if(st.size() ==  0) nsi[i]=n;
            else nsi[i] = st.top();
            //push
            st.push(i);
        }
        return nsi;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> psi;
        psi = previousSmaller(heights);

        vector<int> nsi;
        nsi = nextSmaller(heights);
        
        int maxarea = 0;

        for(int i=0; i<heights.size(); i++){
            int area = heights[i]*(nsi[i]-psi[i]-1);//(nsi[i]-psi[i]-1) this gives the breadth of the size we needed
            maxarea = max(maxarea,area);
        }
        return maxarea;
    }
};