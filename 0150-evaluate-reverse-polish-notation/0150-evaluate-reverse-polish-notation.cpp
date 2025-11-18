class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        string op = "";
        if(tokens.size() == 1){
            result = stoi(tokens[0]);
            return result;
        }
        for(int i=0; i<tokens.size(); i++){
            // if(st.size() == 1) return result;
            if(tokens[i] == "+" || tokens[i] == "-"  || tokens[i] == "*" || tokens[i] == "/"){
                op = tokens[i];
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                // result = second operator first...
                if( op == "+" ) result = second + first;
                else if( op == "-" ) result = second - first;
                else if( op == "*" ) result = second * first;
                else{
                    if(first != 0) result = second/first;
                    else continue;
                }
                st.push(result);
            }
            else{
                int x = stoi(tokens[i]);
                st.push(x);
            }
        }
        return result;
    }
};