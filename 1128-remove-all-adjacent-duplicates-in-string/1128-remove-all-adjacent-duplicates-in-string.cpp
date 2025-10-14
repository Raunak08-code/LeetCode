class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(st.size() == 0) st.push(s[i]);
            else if(st.top() != s[i]) st.push(s[i]);
            else st.pop();
        }
        string str="";
        while(st.size()){
            char ch = st.top();
            str += ch;
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};