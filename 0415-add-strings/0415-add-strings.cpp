class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1,j=num2.size()-1,carry=0;
        string result;

        while(i>=0||j>=0||carry>0){
             carry+=(i>=0)?num1[i--]-'0':0;
             carry+=(j>=0)?num2[j--]-'0':0;
             result.push_back(carry%10+'0');
             carry/=10;
        }
        return{result.rbegin(),result.rend()};
    }
};