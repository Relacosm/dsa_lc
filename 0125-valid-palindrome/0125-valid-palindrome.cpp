#include<algorithm>
#include<cctype>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned;

        for(char ch:s){
            if (isalnum(ch)){
                cleaned+=tolower(ch);
            }
        }

        int left = 0;
        int right = cleaned.size() - 1;

        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false;
            }
           left++;
           right--;
        }

        return true;
    }
};