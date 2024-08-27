class Solution {
public:
    string minWindow(string s, string t) {
     int i=0,j=0;
     int n=s.size();

     unordered_map<char,int> mp;

     for(auto x: t)
     mp[x]++;

     int cnt=mp.size(); 
     string ans=""; 
     string res="";
     int mn=INT_MAX;
     int ms=0;

     while(j<n){
       
        //  if(mp[s[j]]==0)
        //  cnt--;

         mp[s[j]]--;
         if(mp[s[j]]==0)
         cnt--;

        //  j++;

         while(cnt==0){
if(j-i+1<mn){
mn=j-i+1;
ms=i;
}

mp[s[i]]++;


if(mp[s[i]]>0)
cnt++;

i++;
         }
         j++;
     } 

if(mn!=INT_MAX)
return s.substr(ms,mn);

return "";
    }
};