class Solution {
public:
    bool isPalindrome(int x) {
        if(x>=0){
            int check = x;
            long  n=0;
            while( x != 0){
                n =(n*10) + (x%10);
                x = x/10;
            }
            if (n > INT_MAX || n< INT_MIN) return false;

            if( (int)n == check ) return true;
            else return false;
        }
        else return false;
    }
};