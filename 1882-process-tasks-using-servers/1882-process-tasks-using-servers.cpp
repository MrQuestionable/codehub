class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> free_servers;
        typedef pair<long long, pair<int, int>> BusyServer;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busy_servers;
        for(int i=0;i<n;i++){
            free_servers.push({servers[i],i});
        }
        vector<int> ans(m);
        long long waiting=0;
        for(int j=0;j<m;j++){
            waiting=max(waiting,(long long)j);
        
        if(free_servers.empty()){
            waiting=busy_servers.top().first;
        }
        while(!busy_servers.empty() && busy_servers.top().first <= waiting){
            free_servers.push(busy_servers.top().second);
            busy_servers.pop();
        }
        auto best = free_servers.top();
        free_servers.pop();
        ans[j]=best.second;
        busy_servers.push({waiting + tasks[j], best});
        }
    return ans;    
    }
};