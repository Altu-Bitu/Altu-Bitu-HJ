//
// Created by user on 2021-10-01.
//

#include <iostream>

using namespace std;

const int SIZE = 8; //n과 m의 최대 사이즈

int n, m; //입력받을 n과 m
int num[SIZE]; //수열

//재귀함수로 구현한 백트래킹
void backtracking(int cnt, int start) { //start: 오름차순 구현을 위한 시작 인덱스
    if (cnt == m) { //기저조건, 길이 m 수열 만든 경우
        for (int i = 0; i < cnt; i++) //바로 출력
            cout << num[i] << ' '; // m이 2면 1 2 이런식으로 출력
        cout << '\n'; //각 수열마다 한줄씩 띄어 출력
        return; //수열을 출력했으면 다시 리턴
    }
    for (int i = start; i <= n; i++) {
        num[cnt] = i; //수열 저장
        backtracking(cnt + 1, i + 1); //호출
    }
}

int main() {
    //입력
    cin >> n >> m; //1~n까지의 자연수 중에서 중복 없이 m개를 고르기 위한 입력

    //연산 + 출력
    backtracking(0, 1); //수열의 인덱스 0부터 시작, 오름차순을 위한 시작 인덱스 1부터 시작

    return 0;
}