//
// Created by user on 2021-11-30.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //루트 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x가 속한 집합의 루트
    int yp = findParent(y); //y가 속한 집합의 루트

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return; //그냥 리턴
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cmd, a, b;

    //입력
    cin >> n >> m; //n+1개의 집합, m개의 연산개수
    parent.assign(n + 1, -1); //집합 벡터 할당
    while (m--) {
        cin >> cmd >> a >> b; //a가 포함되어 있는 집합과 b가 포함되어있는 집합을
        //합치거나(0) 확인함(1)

        //연산
        if (cmd == 0) { //유니온
            unionInput(a, b);
        }
        if (cmd == 1) { //파인드
            if (findParent(a) == findParent(b))
                cout << "YES\n"; //같은 집합이면
            else
                cout << "NO\n"; //다른 집합이면
        }
    }
}
