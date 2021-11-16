//
// Created by user on 2021-11-16.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e5; //최대값 설정

//역추적
vector<int> back(int x, vector<int> &path) { //x: k(도착지점)부터
    vector<int> result(0); //정답 경로
    while (x != -1) {
        result.push_back(x); //역 따라가면서 으로 넣어줌
        x = path[x]; //다음 정점
    }
    return result; //역추적 벡터 리턴
}

int bfs(int n, int k, vector<int> &path) {
    vector<int> check(SIZE + 1, 0); //체크 벡터 할당
    queue<int> q; //큐에 좌푯값 저장
    int ans = 0; //최단 시간

    check[n] = 1; //시작 노드 방문 체크
    q.push(n); //시작 노드 초기화
    while (!q.empty()) {
        int x = q.front(); //현재 탐색하려는 위치
        q.pop(); //탐색하기 위해 꺼냄

        if (x == k) { //동생 찾으면 탐색 종료.
            ans = check[x] - 1; //시작 노드 초기화를 1로 했기 때문에 1을 빼줌
            break; //탈출
        }

        vector<int> child = {x - 1, x + 1, x * 2}; //자식노드
        for (int i = 0; i < 3; i++) {
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) { //범위 내에 있고, 첫 방문이라면
                check[child[i]] = check[x] + 1; //체크해줌
                path[child[i]] = x; //경로 저장
                q.push(child[i]); //큐에 넣어줌
            }
        }
    }
    return ans; //답 리턴
}

/**
 * 최단거리(BFS) 역추적
 * - 기본 문제: 숨바꼭질
 */

int main() {
    vector<int> path(SIZE + 1, -1); //경로 저장 벡터
    int n, k;

    //입력
    cin >> n >> k; //수빈이 위치, 동생 위치

    //연산
    int ans = bfs(n, k, path); //동생 찾는 빠른 시간 출력
    vector<int> result = back(k, path); //역 추적

    //출력
    cout << ans << '\n'; //최단 시간 출력
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' '; //역추적한 이동 경로 출력
    return 0;
}