class Solution {
private:
    double helper(double x, long long n){
        if(n==0)return 1;
        if(n==1)return x;
        if(n%2==0){
            return helper(x*x, n/2);
        }
        else return x*helper(x,n-1);
    }
public:
    double myPow(double x, long long n) {
        long long num=n;
        if(num<0)return (1.0/helper(x,-1*num));
        else return helper(x,num);
    }
};