class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> st;
        for(int i=0; i<str.size(); i++){
            if(st.size()== 0 || st.top()!=str[i]) st.push(str[i]); 
            else st.pop();
        }
        string result="";
        while(st.size()>0){
            char ch = st.top();
            result.push_back(ch);
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};