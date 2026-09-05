class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time=0;
        vector<int> mp(26,0);
        priority_queue<int> q;
        for(char &c:tasks){
           mp[c-'A']++;
        }
        for(int i=0;i<26;i++){
            if(mp[i]>0)q.push(mp[i]);
        }
        while(!q.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!q.empty()){
                int freq=q.top();
                q.pop();
                freq--;
                temp.push_back(freq);
                }
            }
            for(int &i:temp){
                if(i>0)q.push(i);
            }
            if(q.empty())time += temp.size();
            else time+=n+1;
        }
    return time;
    }
};