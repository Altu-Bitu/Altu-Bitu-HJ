//
// Created by user on 2021-11-30.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //루트 정점
        return node; //루트 노드 번호 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); //x가 있는 집합의 루트 노드
    int yp = findParent(y); //y가 있는 집합의 루트 노드

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false; //싸이클이 있음을 알림
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true; //싸이클 없음
}

/**
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */
int main() {
    int n, m, x, y;

    //입력
    cin >> n >> m; //평면상의 점 n개, m번째 차례
    parent.assign(n, -1); //집합의 부모 벡터 할당
    for (int i = 0; i < m; i++) {
        cin >> x >> y; //i번째 차례에 플레이어가 선택한 두 점의 번호

        //연산 & 출력
        if (!unionInput(x, y)) { //유니온 할 수 없음 = 사이클이 생성됨
            cout << i + 1; //차례 출력
            return 0; //끝
        }
    }
    cout << 0; //다 유니온 가능하면 사이클이 없으므로 0 출력
}