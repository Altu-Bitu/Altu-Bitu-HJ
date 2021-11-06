//
// Created by user on 2021-11-02.
//
#include <iostream>
#include <vector>

using namespace std;

int ans, n, m;
vector<vector<int>> board;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

//board[row][col]을 가운데로 하는 +모양 만들기
int horn(int row, int col) {

    int cnt = 0, min_block = 1001, sum = board[row][col];
    //횟수, 최소 합, 숫자 합
    for (int i = 0; i < 4; i++) {
        //상하좌우 움직임
        int nr = row + dr[i];
        int nc = col + dc[i];

        //만약 움직였는데 구간을 넘어가면 그냥 넘어감
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) //범위를 벗어나면 무시
            continue;
        //움직인 상태의 합과 최소 합 비교해서 적은 걸로 갱신
        min_block = min(min_block, board[nr][nc]); //가장자리 블럭 중 값이 가장 작은 블럭
        sum += board[nr][nc]; //움직였으니까 숫자 합에 더해줌
        cnt++; // 횟수 늘어남
    }

    if (cnt < 3) //가능한 가장자리가 최소 3개 이상이어야 함
        return 0;
    if (cnt == 3) //ㅗㅏㅜㅓ
        return sum; //합 리턴
    //+ 에서 하나 빼줌 됨
    return sum - min_block; //합에서 최소합을 빼줌
}

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum) {
    if (cnt == 4) { //기저조건 : 4개의 블럭을 탐색함
        ans = max(ans, sum); //답을 더 많은 걸로 갱신
        return; //리턴
    }

    for (int i = 0; i < 4; i++) {
        //상하좌우 움직임
        int nr = row + dr[i];
        int nc = col + dc[i];

        //만약 움직였는데 구간 벗어나면 넘어감
        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) //범위를 벗어나거나, 이미 방문했다면
            continue;
        //값을 저장해둠
        int save = board[nr][nc];
        board[nr][nc] = 0; //초기화
        //횟수 늘리고 합에 save 합해서 함수 호출
        backtracking(nr, nc, cnt + 1, sum + save);
        board[nr][nc] = save;// 함수 지나고 다시 넣어줌
    }
}

/**
 * 1. 각 블럭을 백트래킹이 가능한 블럭과 불가능한 블럭으로 나누기
 *    -> 블럭을 한붓 그리기로 그릴 수 있으면 백트래킹이 가능 아니라면 불가능
 *    -> 보라색 블럭을 제외하면 모두 백트래킹 가능
 * 2. 보라색 블럭은 + 모양에서 가장자리를 하나 제거한 것과 같음
 *    -> 가운데 블럭을 중심으로 가장자리 블럭을 붙여보고 가능한 최댓값 구하기
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 *
 * 해설 : https://myunji.tistory.com/297
 * *코드가 살짝 달라요(블로그 코드는 최적화 하기 전)
 */
int main() {
    //입력
    cin >> n >> m; //종이의 세로크기 n, 가로크기 m
    board.assign(n, vector<int>(m, 0)); //2차원 벡터생성
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];//종이에 쓰여있는 수 넣어줌
    }

    //연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, horn(i, j)); //보라색 블럭 처리
            int save = board[i][j]; //값 저장해둠

            board[i][j] = 0; //0으로 초기화
            backtracking(i, j, 1, save); //나머지 모양 처리
            board[i][j] = save; //다시 넣어줌
        }
    }

    //출력
    cout << ans; //답 출력
}
