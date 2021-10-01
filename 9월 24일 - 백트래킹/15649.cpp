//
// Created by user on 2021-10-01.
//


#include <iostream>

using namespace std;

const int SIZE = 8; // n과 m의 최대 사이즈

int n, m; //입력받을 n과 m
int num[SIZE]; //수열
bool check[SIZE + 1]; //수 사용 체크 배열

//재귀함수로 구현한 백트래킹
void backtrackg(int cnt) { //cnt: 수열의 인덱스
    if (cnt == m) { //기저조건, 길이 m 수열 만든 경우
        for (int i = 0; i < cnt; i++) //바로 출력
            cout << num[i] << ' '; // m이 2면 1 2 이런식으로 출력
        cout << '\n'; //각 수열마다 한줄씩 띄어 출력
        return; //수열을 출력했으면 다시 리턴
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i]) { //현재 수열에 해당 수가 없어야 사용 가능
            num[cnt] = i; //수열에 값 저장
            check[i] = true; //수 사용
            backtrackg(cnt + 1); //다음 수열 인덱스 호출
            check[i] = false; //원래 상태로 돌려놓음
        }

    }
}

int main() {
    //입력
    cin >> n >> m; //1~n까지의 자연수 중에서 중복 없이 m개를 고르기 위한 입력

    //연산 + 출력
    backtrackg(0); //수열의 인덱스 0부터 시작

    return 0;
}