class Solution {
public:
    // vector<int> asteroidCollision(vector<int>& as) {
    //     int n= as.size();
    //     stack<int> st;
    //     // for(int i=0; i<as.size(); i++){
    //     //     if(as[i]>0){ //positive
    //     //         while(as[i]>0){
    //     //             st.push(as[i]);
    //     //             i++;
    //     //         }
    //     //         // check for who survive the collision...
    //     //         while(st.size()>0 && i<n && st.top()<= -(as[i])){
    //     //             st.pop();
    //     //         }
    //     //         // if(i ==n && st.size() != 0) {
    //     //         //     while(! st.empty()){
    //     //         //         remaining.push_back(st.top());
    //     //         //         st.pop();
    //     //         //     }
    //     //         // }
    //     //         if(st.size() == 0) remaining.push_back(as[i]);
    //     //         else remaining.push_back(st.top());
    //     //     }
    //     //     else{   //as[i]<0..negative
    //     //         while(i < 0){
    //     //             st.push(as[i]);
    //     //             i--;
    //     //         }
    //     //         //check for remaing..
    //     //         while(st.size()>0 && st.top()> -as[i]){
    //     //             st.pop();
    //     //         }
    //     //         if(st.size() == 0) remaining.push_back(as[i]);
    //     //         else remaining.push_back(st.top());
    //     //     }  
    //     // }

    //     for(int i=0; i<n; i++){
    //         if(as[i]>0){
    //             st.push(as[i]);
    //         }
    //         else{ //    if(as[i]<0){
    //             while(st.size()>0 && st.top()<=-as[i] && i<n){ 
    //                 st.pop();
    //             }
    //             st.push(as[i]);;
    //             if(st.top()==as[i]) st.pop();
    //             //if(st.size() != 0 && i<n) st.push(as[i]);
    //             else st.push(as[i]);
    //         }
    //     }
    //     vector<int> remaining(st.size(),0);

    //     for(int i = st.size()-1; i>=0; i--){
    //         remaining[i] = st.top();
    //         st.pop();
    //     }
    //     return remaining;
    // }
    vector<int> asteroidCollision(vector<int>& as) {
        int n = as.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {

            // Current asteroid
            int cur = as[i];

            // Case 1: no collision possible → simply push
            if(st.empty() || cur > 0) {
                st.push(cur);
            } 
            else {
                // cur is negative → collision may happen
                while(!st.empty() && st.top() > 0 && st.top() < abs(cur)) {
                    st.pop();   // top is smaller, destroyed
                }

                // After popping smaller ones:

                // Case 2: equal size → both explode
                if(!st.empty() && st.top() > 0 && st.top() == abs(cur)) {
                    st.pop();
                }
                // Case 3: stack is empty or top is negative → cur survives
                else if(st.empty() || st.top() < 0) {
                    st.push(cur);
                }
                // Case 4: top is bigger positive → cur is destroyed → do nothing
            }
        }

        // Build remaining in correct order
        vector<int> remaining(st.size());
        for(int i = st.size()-1; i >= 0; i--) {
            remaining[i] = st.top();
            st.pop();
        }

        return remaining;
    }

};

