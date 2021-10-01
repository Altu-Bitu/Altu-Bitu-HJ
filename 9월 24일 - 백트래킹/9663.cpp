//
// Created by user on 2021-10-01.
//

#include <iostream>

using namespace std;

const int SIZE = 15; //n의 최대 크기

int n, ans; //입력받을 n과 결과로 출력할 ans
bool check_col[SIZE]; //열 체크
bool check_left[SIZE * 2]; //좌하향 대각선 체크
bool check_right[SIZE * 2]; //우하향 대각선 체크

void backtracking(int cnt) { //cnt: 행
    if (cnt == n) { //기저조건, n개의 퀸이 모두 놓임
        ans++; //정답 증가
        return; //호출된 곳으로 다시 리턴
    }
    for (int i = 0; i < n; i++) { //i: 열
        if (!check_col[i] && !check_left[cnt + i] && !check_right[cnt - i + n]) { //모두 false여야 배치 가능
            //(cnt, i)에 퀸 배치 -> 그에 따른 열, 좌하향 대각선, 우하향 대각선 체크해줌
            check_col[i] = true; //ex)i가 1이면 1열에 해당되는 것들 true
            check_left[cnt + i] = true; // ex)cnt+i가 2면 행과 열을 합쳐서 2가되는 좌하향 대각선에 해당되는 것들 true
            check_right[cnt - i + n] = true; // ex) cnt-i+n가 4면 행에서 열을 빼고 n을 더하면 4가 되는 우하향 대각선에 해당되는 것들 true
            backtracking(cnt + 1); //다음 행 호출
            //재탐색이 가능하도록 원래상태로 돌려놓음
            check_col[i] = false; // 열에 해당했던 것 false
            check_left[cnt + i] = false; // 좌하향 대각선에 해당했던 것 false
            check_right[cnt - i + n] = false; // 우하향 대각선에 해당했던 것 false
        }
    }

}

/**
 * 시간 1684ms
 */

int main() {
    //입력
    cin >> n; //nxn 체스판에 놓을 퀸 n개

    //연산
    backtracking(0); //0행부터 시작

    //출력
    cout << ans << '\n'; //결과 출력

    return 0; //종료
}