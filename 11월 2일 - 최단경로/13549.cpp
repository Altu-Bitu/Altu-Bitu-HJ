//
// Created by user on 2021-11-09.
//


#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 100000;

int zeroOneBfs(int n, int k) {
    vector<int> check(SIZE + 1, 0); //정점에 도착한 시간
    deque<int> dq; //덱으로 구현
    int ans = 0;

    //시작 위치 초기화
    check[n] = 1; //시작 위치를 1로
    dq.push_back(n); //덱에 현 위치 넣어줌

    while (!dq.empty()) {
        int x = dq.front(); //현재 탐색하려는 위치
        dq.pop_front(); //탐색하려는 위치 꺼냄

        if (x == k) { //동생 찾으면 탐색 종료. 시작 위치를 1로 초기화 했기 때문에 1을 빼줌
            ans = check[x] - 1; //초기화할때 했던 1 빼줌
            break; //빠져나감
        }

        int next = x * 2; //순간이동
        //범위를 벗어나지 않고, 탐색하지 않은 곳일때
        if (next <= SIZE && !check[next]) {
            check[next] = check[x]; //갱신. 순간이동이므로 0초
            dq.push_front(next); //정점 덱에 넣어줌
        }

        next = x - 1; //뒤로 걷기
        //0보다 크거나 같고, 탐색하지 않은 곳일때
        if (next >= 0 && !check[next]) {
            check[next] = check[x] + 1; //1초 더해서 갱신
            dq.push_back(next);//정점 덱에 넣어줌
        }

        next = x + 1; //앞으로 걷기
        //범위에서 벗어나지 않고, 탐색하지 않은 곳일 때
        if (next <= SIZE && !check[next]) {
            check[next] = check[x] + 1; //1초 더해서 갱신
            dq.push_back(next);//정점 덱에 넣어줌
        }
    }
    return ans; //답 시간 리턴
}

/**
 * x좌표 위에서 2*x, x-1, x+1의 위치로 계속 이동하며 탐색
 * 이동에 대한 가중치는 0, 1 두 가지이므로 다익스트라가 아니라 덱으로 풀 수 있음 (0-1 BFS)
 *
 * !주의!
 * 순간이동으로 이동하는 경우를 걸어서 이동하는 경우보다 먼저 고려해야 함
 * -> 어차피 순간이동은 push_front 되는데 왜?
 * -> 1에서 2로 이동할 땐 걷는 것도 가능하고 순간이동도 가능함
 *    걷는 방법을 먼저 고려하면 check 배열이 갱신되어 순간이동을 고려할 수 없음
 */
int main() {
    int n, k;

    //입력
    cin >> n >> k; //수빈이가 있는 위치, 동생이 있는 위치

    //연산 & 출력
    cout << zeroOneBfs(n, k) << '\n';
}
