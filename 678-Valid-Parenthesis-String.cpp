class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx =0;

        for(char c :s ){
            if(c=='('){
                mn+=1;
                mx+=1;
            }
            else if(c==')'){
                mn-=1;
                mx-=1;
            }
            else{
                mn-=1;
                mx+=1;
            }

            if(mn<0)
            mn=0;

            if(mx<0)
            return false;
        }

        return mn==0;
    }
};