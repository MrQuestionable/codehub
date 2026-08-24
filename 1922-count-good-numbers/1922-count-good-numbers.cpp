class Solution {
private:
    int Mod=1000000007;
    long long modPow(long long n,long long m){
        if(m==0)return 1;
        long long half=modPow(n,m/2);
        long long halfs=(half*half)%Mod;
        if(m%2==0){
            return halfs;
        }
        return (halfs*n)%Mod;
    }
public:
    int countGoodNumbers(long long n) {
       long long eveni=(n+1)/2;
       long long oddi=n/2;
       long long oddchoi=modPow(4,oddi);
       long long evenchoi=modPow(5,eveni);

       return (evenchoi * oddchoi)% Mod; 
    }
};