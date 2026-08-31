class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f, t;
        f = 0;
        t = 0;
        int i, n=bills.size();
        for(i=0;i<n;i++)
        {
            if (bills[i] == 5)
            {
                f++;
            }
            else if (bills[i] == 10)
            {
                f--;
                if (f<0)
                {
                    return false;
                }
                t++;
            }
            else
            {
                if (t>0 && f > 0)
                {
                    t--;
                    f--;
                }
                else if (f>=3)
                {
                    f -= 3;
                }
                else
                {
                    return false;

                }
            }

        }
        return true;
    }
};