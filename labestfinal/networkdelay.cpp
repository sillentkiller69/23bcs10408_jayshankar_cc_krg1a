class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:times){
            adj[it[0]-1].push_back({it[1]-1,it[2]});

        }
        vector<int>vst(n,INT_MAX);
        vst[k-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k-1});
        while(!pq.empty()){
            int x=pq.top().second;
            int y=pq.top().first;

            pq.pop();
            for(auto [a,b]:adj[x]){
                if(vst[a]>y+b){
                    vst[a]=y+b;
                    pq.push({vst[a],a});

                }
            }

        }
        // for(auto it:vst){
        //     cout<<it<<endl;
        
        // }
        int lnd=*max_element(vst.begin(),vst.end());
        if(lnd==INT_MAX)return -1;
        return lnd;
         


        
    }
};