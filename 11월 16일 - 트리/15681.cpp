//
// Created by user on 2021-11-23.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt;

int treeDp(int cur, vector<vector<int>> &graph) {
    if (subtree_cnt[cur] != -1) //이미 탐색했던 상태
        return subtree_cnt[cur]; //리턴

    //서브트리에 속한 정점의 수를 세고, 저장
    subtree_cnt[cur] = 0; //정점의 개수
    int node = 1; //노드 초기화
    for (int i = 0; i < graph[cur].size(); i++)
        node += treeDp(graph[cur][i], graph); //재귀적으러 계산
    return subtree_cnt[cur] = node; //계산한 정점개수 넣어주고 리턴
}

/**
 * PPT 트리의 정점의 수 구하기 응용
 *
 * 1. 루트에서부터 dfs 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 계산
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q, u, v, input;

    //입력
    cin >> n >> r >> q; //정점의 수, 루트의 번호, 쿼리의 수
    vector<vector<int>> graph(n + 1, vector<int>(0));
    //그래프 할당
    subtree_cnt.assign(n + 1, -1);
    //서브트리 개수

    while (--n) { //무방향 그래프
        cin >> u >> v; //간선
        graph[u].push_back(v); //서로에게 할당
        graph[v].push_back(u);
    }

    //연산
    treeDp(r, graph);

    //출력
    while (q--) {
        cin >> input; //정점 u
        cout << subtree_cnt[input] << '\n';
    }
}
