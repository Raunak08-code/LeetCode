class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q; // student in queue..
        for(int i=0; i<students.size(); i++){
            int x = students[i];
            q.push(x);
        }
        int count =0;
        int i =0;
        while(count != q.size()){
            
            if(sandwiches[i] == q.front()){
                i++;
                q.pop();
                count =0;
            }
            else{
                int x= q.front();
                q.pop();
                q.push(x);
                count++;
            }
        }
        return count;
    }
};