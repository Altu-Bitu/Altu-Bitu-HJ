//
// Created by user on 2021-10-01.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9; //최소비용을 위해 초기값 높게 설정

vector<bool> visited; //이 도시를 방문했었나~~ 판별
vector<vector<int>> matrix; //방문할 도시들
int ans = INF; //최소비용을 위해 초기값 높게 설정

/**
 * 모든 도시를 방문한 뒤 돌아올 수 있는 모든 경우 탐색
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 */
void backtracking(int n, int start_city, int cur_city, int cnt, int cost) {
    if (cost >= ans) //생각해보기 : 이 조건문이 없으면 어떻게 될까요?
        return; //현재 비용이 최소값보다 높으면 굳이 더 찾아볼 필요가 없으니 리턴
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][start_city] != 0) //현재 도시에서 출발도시로 돌아오는 비용이 0이 아니면
            ans = min(ans, cost + matrix[cur_city][start_city]);
        //기존에 있었던 최소값이랑 여태껏 든 비용+다시 돌아가는 비용을 비교해서 작은걸 답에 넣어줌
        return; //호출했던 곳으로 돌아감
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true; //방문 처리
            backtracking(n, start_city, i, cnt + 1, cost + matrix[cur_city][i]);
            //기존 비용에서 cur_city에서 i도시로 가는 비용 추가해서 호출
            visited[i] = false; //미방문 처리
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * !주의! 모든 도시를 방문 후 시작 도시로 돌아와야 하기 때문에 어떤 도시에서 출발했는지 알고 있어야 함.
 */
int main() {
    int n; //도시의 수

    //입력
    cin >> n; //도시의 수 입력받음
    visited.assign(n, false); //도시의 수만큼 방문안했다고 초기화
    matrix.assign(n, vector<int>(n, 0)); //도시 수만큼 2차원 배열 설정
    for (int i = 0; i < n; i++) //행 {
        for (int j = 0; j < n; j++) //열
            cin >> matrix[i][j]; //비용 행렬 저장
    }

    //연산
    //i번째 도시를 시작으로 순회
    for (int i = 0; i < n; i++) {
        visited[i] = true; //방문 처리
        backtracking(n, i, i, 1, 0); //n개의 도시를 i도시에서 시작해서 현재 i도시에 있음. 거친 도시 수를 세는 0, 아직 비용 0
        visited[i] = false; //미방문 처리
    }

    //출력
    cout << ans; //외판원 순회에 필요한 최소 비용 출력
}