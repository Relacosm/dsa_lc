class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";

        string base7;
        bool isnegative=num<0;
        num=abs(num);

        while(num>0){
            base7+=to_string(num%7);
            num=num/7;
        }

        if(isnegative) base7+="-";

        reverse(base7.begin(),base7.end());
        return base7;
    }
};