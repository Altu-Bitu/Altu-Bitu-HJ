//
// Created by user on 2021-11-23.
//


#include <iostream>
#include <vector>

using namespace std;

bool is_tree;
vector<bool> visited;
vector<vector<int>> graph;

void dfs(int node, int parent) {
    if (visited[node]) { //이미 방문한 정점이라면 사이클이 발생한 것
        is_tree = false; //트리가 아님
        return; //리턴
    }

    visited[node] = true; //방문 처리
    for (int i = 0; i < graph[node].size(); i++) {
        if (graph[node][i] != parent) //부모 정점이 아니라면
            dfs(graph[node][i], node); //계속 탐색
    }
}

void printResult(int num, int cnt) {
    cout << "Case " << num; //케이스 번호
    if (cnt == 0)
        cout << ": No trees.\n"; //트리가 아님
    else if (cnt == 1)
        cout << ": There is one tree.\n"; //하나 있음
    else
        cout << ": A forest of " << cnt << " trees.\n"; //트리가 이렇게 있음
}

int main() {
    int n, m, a, b, test_case = 0;

    while (true) {
        test_case++; //테스트 케이스 늘림

        //입력
        cin >> n >> m; //정점의 개수 n, 간선의 개수 m
        if ((n == 0) && (m == 0)) //종료 조건
            break;// 종료
        visited.assign(n + 1, false); //방문 벡터 생성
        graph.assign(n + 1, vector<int>(0)); //그래프 생성
        while (m--) { //무방향 그래프
            cin >> a >> b; //간선들
            graph[a].push_back(b); //무방향이라 서로에게 넣어줌
            graph[b].push_back(a); //여기도
        }

        //연산
        int tree_cnt = 0; //초기화
        for (int i = 1; i <= n; i++) {
            if (visited[i]) //이미 방문한 정점
                continue; //다음으로 넘어감
            is_tree = true; //트리임을 표시
            dfs(i, -1); //dfs 연산
            if (is_tree) //트리가 맞다면
                tree_cnt++; //트리개수 늘려줌
        }

        //출력
        printResult(test_case, tree_cnt); //출력
    }
}