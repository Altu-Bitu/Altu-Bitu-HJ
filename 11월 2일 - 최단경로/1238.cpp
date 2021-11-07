//
// Created by user on 2021-11-07.
//


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,x;
typedef pair<int,int> ci;
vector<ci> g[1001];
const int INF = 1e9;

//걍 다익스트라..
int dijkstra(int s, int e){
    vector<int> dist(1001, INF);
    priority_queue<ci,vector<ci>,greater<>> pq;

    dist[s]=0;
    pq.push({dist[s],s});

    while(!pq.empty()){
        int d = pq.top().second;
        if (d==e) return dist[e];
        pq.pop();
        for(int i=0; i<g[d].size(); i++){
            int nxt_weight = g[d][i].first;
            int nxt = g[d][i].second;
            if (dist[nxt]>dist[d]+nxt_weight){
                dist[nxt]=dist[d]+nxt_weight;
                pq.push({dist[nxt],nxt});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie();

    cin >> n >> m >> x;


    while(m--){
        int s,e,t;
        cin >> s >> e >> t;
        g[e].emplace_back(t,s);
    }
    //다익스트라를 두번 적용해서
    //목적지로가는거+목적지에서돌아오는거 의 최대값을 구하면 됨
    int res=0;
    for(int i=1;i<=n;i++){
        res = max(res, dijkstra(i,x)+ dijkstra(x,i));
    }

    cout << res << "\n";
    return 0;
}