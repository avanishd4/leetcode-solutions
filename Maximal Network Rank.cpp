//  TC -> O(E + N^2)
//  SC->  O(E)


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,unordered_set<int>> adj;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curr=adj[i].size() +adj[j].size();
                if(adj[j].count(i)){
                    curr--;
                }
             ans=max(curr,ans);
            }
                 
        }
        return ans;
    }
    
};
