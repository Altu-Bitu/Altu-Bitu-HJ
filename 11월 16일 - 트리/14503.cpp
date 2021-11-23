//
// Created by user on 2021-11-23.
//
#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>> &board) {
    //상, 우, 하, 좌
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int step = 0, ans = 0; //횟수, 답
    while (true) {
        if (board[r][c] == 0) {
            board[r][c] = 2; //빈칸이면 청소해줌
            ans++; //답늘려줌
        }

        if (step == 4) {
            //후진하면 벽인 경우
            if (board[r - dr[d]][c - dc[d]] == 1)
                return ans; //답 리턴
            r -= dr[d]; //후진
            c -= dc[d]; //후진
            step = 0; //횟수 다시 돌아감
        } else {
            d = (d + 3) % 4; //회전
            //왼쪽 방향에 청소할 공간이 없다면
            if (board[r + dr[d]][c + dc[d]]) {
                step++; //회수 늘려줌
                continue; //넘어감
            }
            r += dr[d]; //회전
            c += dc[d]; //회전
            step = 0; //횟수 다시 돌아감
        }
    }
}

/**
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d;

    //입력
    cin >> n >> m >> r >> c >> d;
    //세로, 가로, 로봇청소기가 있는 좌표, 바라보는 방향
    vector<vector<int>> board(n, vector<int>(m, 0));
    //보드 벡터
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j]; //값 넣어줌
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0;
}
