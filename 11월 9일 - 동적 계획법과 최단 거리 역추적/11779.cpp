//
// Created by user on 2021-11-16.
//


#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; //페어 typedef설정
const int INF = 1e8; //최대값 설정

//역추적
vector<int> back(int x, vector<int> &path) { //x: 도착정점 부터
    vector<int> result(0); //정답 벡터
    while (x != 0) {
        result.push_back(x); //역으로 넣어줌
        x = path[x]; //다음 정점
    }
    return result; //리턴
}

int dijkstra(int n, int s, int e, vector<vector<ci>> &graph, vector<int> &path) {
    vector<int> dist(n + 1, INF); //경로 벡터 할당
    priority_queue<ci, vector<ci>, greater<>> pq; //오름차순 우선순위 큐

    //시작 위치 초기화
    dist[s] = 0; //0으로 초기화
    pq.push({0, s}); //초기화해서 큐에 넣어줌

    while (!pq.empty()) {
        int weight = pq.top().first; //가중치
        int node = pq.top().second; //중간 정점
        pq.pop(); //탐색할 거 꺼냄

        if (weight > dist[node]) //이미 탐색한 정점 (이 코드 없으면 시간초과)
            continue; //다음 정점으로 넘어감

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리
            if (dist[next_node] > next_weight) { //더 짧은 경로
                dist[next_node] = next_weight; //짧은 경로 갱신
                path[next_node] = node; //경로 저장
                pq.push({next_weight, next_node}); //가중치랑 정점 넣어줌
            }
        }
    }
    return dist[e]; //경로 리턴
}

/**
 * 다익스트라 역추적
 * - 기본 문제: 최소 비용 구하기
 */

int main() {
    int n, m, a, b, c, s, e;

    //입력
    cin >> n >> m; //도시의 개수 n , 버스의 개수 m
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //인접 리스트
    vector<int> path(n + 1, 0); //경로 저장
    while (m--) {
        cin >> a >> b >> c; //버스의 출발도시 번호, 도착지 도시 번호, 버스 비용
        graph[a].push_back({b, c}); //단방향 그래프
    }
    cin >> s >> e; //구간 출발점의 도시번호, 도착점의 도시번호

    //연산
    int ans = dijkstra(n, s, e, graph, path);
    //다익스트라
    vector<int> result = back(e, path); //역추적

    //출력
    cout << ans << '\n' << result.size() << '\n'; //최소비용, 포함되는 도시의 개수 출력
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' '; //도시 순서대로 출력
    return 0;
}