class Solution {
public:
    int ladderLength(string beg, string end, vector<string>& wl) {
        unordered_set<string> st;
        for (auto &x: wl){
            st.insert(x);
        }

        queue<pair<string,int>> q;

        st.erase(beg);

        q.push({beg,1});

        if(beg==end)
        return 0;

        while(!q.empty()){
            string word = q.front().first;
            int step= q.front().second;
            q.pop();
        for (int i=0; i<word.size(); ++i){
            string org=word;
            for (char ch='a'; ch<='z'; ch++){
                word[i]=ch;

                if(st.find(word)!=st.end()){
                    if(word==end)
                    return step+1;
                    q.push({word,step+1});
                    st.erase(word);
                }
            }
            word=org;
        }
        }

        return 0;
    }
};