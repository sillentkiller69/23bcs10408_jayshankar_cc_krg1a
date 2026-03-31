class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> v(n);
        for (int i = 0; i < f.size(); i++) {
            v[f[i][0]].push_back({f[i][1], f[i][2]});
        }
        priority_queue<pair<pair<int, int>, int>,
                       vector<pair<pair<int, int>, int>>,
                       greater<pair<pair<int, int>, int>>>
            pq;
        vector<pair<int, int>> vst(n, {INT_MAX, 0});
        vst[src].first = 0;
        vst[src].second = 0;

        pq.push({{0, 0}, src});
        while (!pq.empty()) {
            int x = pq.top().first.first;  // no of nodes
            int y = pq.top().first.second; // total weigh till then
            int z = pq.top().second;       // where it comes from
            pq.pop();
            for (auto [p, q] : v[z]) {
                if (x + 1 <= k + 1 && vst[p].first > y + q) {

                    vst[p].second = x + 1;
                    vst[p].first = y + q;
                    pq.push({{vst[p].second, vst[p].first}, p});
                }
            }
        }
        if (vst[dst].first == INT_MAX)
            return -1;
        return vst[dst].first;
    }
};