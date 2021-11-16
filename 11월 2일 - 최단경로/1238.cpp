//
// Created by user on 2021-11-07.
//


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,x;
typedef pair<int,int> ci;
const int INF = 1e9;

//걍 다익스트라..
vector<int> dijkstra(int n, int s,vector<vector<ci>> &g){
    vector<int> dist(n+1, INF);
    priority_queue<ci,vector<ci>,greater<>> pq;

    dist[s]=0;
    pq.push({0,s});

    while(!pq.empty()){
        int t = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        if(t>dist[d])
            continue;

        for(int i=0; i<g[d].size(); i++){
            int nxt_node = g[d][i].first;
            int nxt = t+g[d][i].second;
            if (dist[nxt_node]>nxt){
                dist[nxt_node]=nxt;
                pq.push({nxt,nxt_node});
            }
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie();

    cin >> n >> m >> x;
    vector<vector<ci>> g(n+1, vector<ci>());
    vector<vector<ci>> r_g(n+1, vector<ci>());

    while(m--){
        int s,e,t;
        cin >> s >> e >> t;
        g[s].emplace_back(e,t);
        r_g[e].emplace_back(s,t);
    }

    //벡터로 미리 저장해둠
    vector<int> go = dijkstra(n,x,g);
    vector<int> back = dijkstra(n,x,r_g);
    //다익스트라를 두번 적용해서
    //목적지로가는거+목적지에서돌아오는거 의 최대값을 구하면 됨
    int res=0;
    for(int i=1;i<=n;i++){
        res = max(res, go[i]+back[i]);
    }

    cout << res << "\n";
    return 0;
}