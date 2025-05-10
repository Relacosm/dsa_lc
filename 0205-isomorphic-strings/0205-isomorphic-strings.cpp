class Solution {
public:
    bool isIsomorphic(string s, string t) {
     if(s.length()!=t.length()){
        return false;
     }
     int maps[256]={0};
     int mapt[256]={0};
     
     for(int i=0;i<s.length();i++){
        char c1=s[i];
        char c2=t[i];

        if((maps[c1] && maps[c1]!=c2)||
          (mapt[c2] && mapt[c2]!=c1)){
            return false;
          }
        maps[c1]=c2;
        mapt[c2]=c1;
     }
     return true;
    }
};