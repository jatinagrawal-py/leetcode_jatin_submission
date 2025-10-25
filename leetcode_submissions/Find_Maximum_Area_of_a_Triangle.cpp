class Solution {
public:
    using ll = long long;
    long long maxArea(vector<vector<int>>& coords) {
        int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
    for(const auto& p : coords){
        minX = min(minX, p[0]);
        maxX = max(maxX, p[0]);
        minY = min(minY, p[1]);
        maxY = max(maxY, p[1]);
    }
    unordered_map<int, pair<int,int>> xm, ym;
    xm.reserve(coords.size());
    ym.reserve(coords.size());
    for(const auto& p : coords){
        int x = p[0], y = p[1];
        auto itx = xm.find(x);
        if(itx == xm.end()) xm[x] = {y, y};
        else {
            itx->second.first = min(itx->second.first, y);
            itx->second.second = max(itx->second.second, y);
        }
        auto ity = ym.find(y);
        if(ity == ym.end()) ym[y] = {x, x};
        else {
            ity->second.first = min(ity->second.first, x);
            ity->second.second = max(ity->second.second, x);
        }
    }
    ll ans = 0;
    for(auto& kv : xm){
        int x = kv.first;
        int y1 = kv.second.first;
        int y2 = kv.second.second;
        if(y2 > y1){
            ll base = ll(y2 - y1);
            ans = max(ans, base * ll(maxX - x));
            ans = max(ans, base * ll(x - minX));
        }
    }
    for(auto& kv : ym){
        int y = kv.first;
        int x1 = kv.second.first;
        int x2 = kv.second.second;
        if(x2 > x1){
            ll base = ll(x2 - x1);
            ans = max(ans, base * ll(maxY - y));
            ans = max(ans, base * ll(y - minY));
        }
    }
    return ans > 0 ? ans : -1;
    }
};