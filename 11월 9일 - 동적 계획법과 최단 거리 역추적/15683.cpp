//
// Created by user on 2021-11-16.
//

#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 65;
vector<vector<int>> board;

//cctv 범위 표시
void ray(int row, int col, int dir) {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    //상 우 좌 하

    while (row >= 0 && row < n && col >= 0 && col < m && board[row][col] != 6) { //dir 방향으로 뻗어나가며 cctv 표시
        if (board[row][col] == 0) //다른 cctv를 지우지 않기 위해 빈 공간일 때만 표시
            board[row][col] = 7; //visited 표시
        row += dr[dir]; //특정방향으로 뻗어나감
        col += dc[dir]; //위와 동일
    }
}

//cctv 방향 지정
void install(int cctv, int row, int col, int dir) {
    if (cctv >= 1) //1, 2, 3, 4, 5번 cctv
        ray(row, col, dir); //위로
    if (cctv >= 2 && cctv != 3) //2, 4, 5번 cctv
        ray(row, col, (dir + 2) % 4); //아래로
    if (cctv >= 3) //3, 4, 5번 cctv
        ray(row, col, (dir + 1) % 4); //옆으로
    if (cctv == 5) //5번 cctv
        ray(row, col, (dir + 3) % 4); //다시 옆으로
}

//사각지대 계산
int blindSpot() {
    int cnt = 0; //사각지대 카운트
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i][j]) //0이면
                cnt++; //카운트
        }
    }
    return cnt; //리턴
}

void backtracking(int idx) {
    if (idx == n * m) { //기저 조건 : 사무실의 모든 위치 확인
        ans = min(ans, blindSpot()); //사각지대 계산 후 최솟값 갱신
        return;
    }

    int row = idx / m; //가로로 나눈 행
    int col = idx % m;  //나누고 남은 열
    int cur = board[row][col]; //현재 위치
    if (cur == 0 || cur == 6 || cur == 7) //cctv가 없는 곳
        return backtracking(idx + 1); //1더해서 리턴

    vector<vector<int>> save = board; //unvisited 처리용 board 상태 저장
    for (int i = 0; i < 4; i++) { //4개의 방향에 대해 cctv 설치
        install(cur, row, col, i); //설치 함수 호출
        backtracking(idx + 1); //인덱스 더해서 백트래킹
        board = save; //초기화

        //2번 cctv의 방향 종류는 2개, 5번 cctv의 방향 종류는 1개
        if ((cur == 2 && i == 1) || (cur == 5 && i == 0))
            break; //탈출
    }
}

/**
 * cctv가 설치될 수 있는 모든 경우를 고려하는 완전탐색 문제
 *
 * 1. 각 cctv에 대해 가능한 모든 방향을 고려하여 설치
 *    1, 3, 4번 cctv : 4방향
 *    2번 cctv : 2방향
 *    5번 cctv : 1방향
 * 2. install 함수에서 각 cctv의 빛이 뻗어나갈 방향을 잡음
 * 3. ray 함수에서 cctv의 감시 가능 범위 표시
 * 4. 모든 위치를 확인했으면 blindSpot 함수를 통해 사각지대 계산
 *
 * 풀이 : https://myunji.tistory.com/411
 * 해당 코드는 위 링크의 코드를 리팩토링한 코드입니다.
 * 말로는 풀이를 설명하기 어려우니 링크를 꼭 확인해주세요!
 */
int main() {
    //입력
    cin >> n >> m; //사무실의 세로크기 n, 가로크기 m
    board.assign(n, vector<int>(m)); //사무실 벡터
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j]; //값 넣어줌
    }

    //연산
    backtracking(0); //백트래킹

    //출력
    cout << ans; //답
}