//
// Created by user on 2021-11-16.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &table) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int new_dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                if (new_dist < graph[i][j]) { //i->k->j가 i->j보다 빠른 경로라면
                    graph[i][j] = new_dist; //갱신 시켜줌
                    table[i][j] = table[i][k]; //경로를 k까지 가는 경로로 갱신
                }
            }
        }
    }
}

/**
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 16을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */
int main() {
    int n, m, s, d, c;

    //입력
    cin >> n >> m; //집하장의 개수, 집하장간의 경로의 개수
    // graph - 플로이드-워셜 결과 행렬 그래프
    // table - 경로표
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    vector<vector<int>> table(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0; //대각선은 0으로

    while (m--) { //무방향 그래프
        cin >> s >> d >> c; //두 집하장의 번호, 필요한 시간
        //간선 정보
        graph[s][d] = graph[d][s] = c; //cost 넣어줌

        //경로 정보
        table[s][d] = d; //s에서 d로 가는데 거쳐할 d
        table[d][s] = s; //d에서 s로 가는데 거쳐야할 s
    }

    //연산
    floydWarshall(n, graph, table);

    //출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) //대각선이면
                cout << "- ";
            else
                cout << table[i][j] << ' '; //경로표 출력
        }
        cout << '\n';
    }
}