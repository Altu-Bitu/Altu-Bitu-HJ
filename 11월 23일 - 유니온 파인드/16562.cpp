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
        return node; //루트 노드 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x가 들어있는 집합의 루트 노드
    int yp = findParent(y); //y가 들어있는 집합의 루트 노드

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return; //리턴
        //앞선 라이브코딩 코드와 달리 parent[xp]가 클때
    if (parent[xp] > parent[yp]) //새로운 루트 xp
        //앞선 라이브코딩 코드와 달리 parent[xp] += parent[yp] 해주는 과정 없음
        parent[yp] = xp;
    else //새로운 루트 yp
        parent[xp] = yp;
}

int friendshipCost(int n) {
    int sum = 0; //합 초기화
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0) //루트 정점이라면
            sum += -parent[i]; //음수인 루트값(친구비)를 양수로 바꿔서 더해줌
    }
    return sum; //합 리턴
}

int main() {
    int n, m, k, v, w, cost;

    //입력
    cin >> n >> m >> k; //학생수, 친구관계 수, 가지고 있는 돈
    parent.assign(n + 1, 0); //부모 벡터 할당
    for (int i = 1; i <= n; i++) {
        cin >> cost; //친구비
        parent[i] = -cost; //루트 정점에 필요한 친구비(음수)를 저장
    }

    //연산
    while (m--) {
        cin >> v >> w; //학생v와 학생w가 서로 친구
        unionInput(v, w); //유니온
    }

    int ans = friendshipCost(n); //친구비 계산

    //출력
    if (ans <= k) //k보다 작으면(친구를 다 사귈 수 있으면)
        cout << ans; //답 출력
    else
        cout << "Oh no"; //아니면 oh no
}
