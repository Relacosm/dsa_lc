class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int a=1,b=2,ways;
        for(int i=3;i<=n;i++){
            ways=a+b;
            a=b;
            b=ways;
        }
        return ways;
    }
};