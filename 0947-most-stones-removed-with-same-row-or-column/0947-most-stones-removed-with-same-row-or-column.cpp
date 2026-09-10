#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUl(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        return parent[x] = findUl(parent[x], parent);
    }

    void usets(int x, int y, vector<int>& parent, vector<int>& rank){
        int xroot = findUl(x, parent);
        int yroot = findUl(y, parent);
        if(xroot == yroot) return;
        
        if(rank[xroot] < rank[yroot]) parent[xroot] = yroot;
        else if(rank[xroot] > rank[yroot]) parent[yroot] = xroot;
        else{
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        int components = n; // Start assuming every stone is isolated
        
        // Loop through all pairs of stones
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // If they share the same row OR the same column, union them
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    
                    if(findUl(i, parent) != findUl(j, parent)){
                        usets(i, j, parent, rank);
                        components--; // Two isolated groups just merged
                    }
                }
            }
        }
        
        // The maximum stones we can remove is the Total Stones minus the Number of Components
        return n - components;
    }
};