//
// Created by user on 2021-11-30.
//


#include <iostream>
#include <vector>

using namespace std;

vector<bool> cycle;
vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //루트 노드 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x가 들어있는 집합의 루트 노드
    int yp = findParent(y); //y가 들어있는 집합의 루트 노드

    if (xp == yp) { //같은 집합에 있다면 유니온 할 수 없음
        cycle[xp] = true; //cycle이 있음 표시
        return;
    }
    if (cycle[xp] || cycle[yp]) //둘 중 하나라도 사이클이 있으면 표시
        cycle[xp] = cycle[yp] = true; //둘다 사이클로 표시
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int cntTree(int n) {
    int cnt = 0; //트리개수 초기화
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0 && !cycle[i]) //루트 정점인데 사이클도 없을 때
            cnt++; //트리개수 늘려줌
    }
    return cnt; //트리개수 반환
}

void printResult(int num, int cnt) {
    cout << "Case " << num;
    if (cnt == 0) //0개면 tree없음
        cout << ": No trees.\n";
    else if (cnt == 1) //1개면 하나
        cout << ": There is one tree.\n";
    else //여러개면 몇개인지 출력
        cout << ": A forest of " << cnt << " trees.\n";
}

int main() {
    int n, m, a, b, test_case = 0;

    while (true) {
        test_case++; //테스트 케이스 추가

        //입력
        cin >> n >> m; //정점의 개수 n, 간선의 개수 m
        if (n == 0 && m == 0) //종료 조건
            break;
        parent.assign(n + 1, -1); //부모 벡터 할당
        cycle.assign(n + 1, false); //싸이클 판별 벡터 할당
        while (m--) { //무방향 그래프
            cin >> a >> b; //간선
            unionInput(a, b); //유니온
        }

        //연산
        int tree_cnt = cntTree(n); //트리개수 세기

        //출력
        printResult(test_case, tree_cnt); //결과 출력
    }
}