class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char task : tasks){
            freq[task - 'A']++;
        }
        sort(freq.begin(),freq.end());
        int chunk=freq[25]-1;
        int idel=chunk*n;

        for(int i=24;i>=0;i--){
            idel-=min(chunk,freq[i]);
        }

        if(idel<0){
            return tasks.size();
        }
        return tasks.size()+idel;
    }
};