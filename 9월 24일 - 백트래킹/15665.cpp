//
// Created by user on 2021-10-01.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 7; //배열 크기
const int RANGE = 10000; //주어지는 수 범위

int n, m, leng; //leng: 서로 다른 수의 개수
int num[SIZE], ans[SIZE]; //중복을 배제한 num배열과 답 배열

void backtracking(int cnt) {
    if (cnt == m) { //길이 m이라면 (기저조건)
        for (int i = 0; i < cnt; i++) //바로 출력
            cout << ans[i] << ' '; // m이 2면 1 2 이런식으로 출력
        cout << '\n'; //각 수열마다 한줄씩 띄어 출력
        return; //수열을 출력했으면 다시 리턴
    }
    for (int i = 0; i < leng; i++) { //중복 수 모두 제거되었으므로 따로 체크할 필요 없이 수열을 만든다
        ans[cnt] = num[i]; //답 배열에 넣어줌
        backtracking(cnt + 1); //인덱스 증가시키며 호출
    }
}

/**
 * [백트래킹 풀이] (176ms)
 * 조건: 같은 수 여러 번 사용 가능, 수열은 중복되면 안됨, 사전 순으로 출력
 * '같은 수 여러 번' -> 완전탐색
 * '수열 중복되면 안됨'
 * -> 현재 중복으로 들어오는 수가 존재하여, 그냥 완전탐색을 진행하면 중복 수열이 생김
 * -> 따라서, 중복으로 들어오는 수를 제거하여 다른 배열에 저장한 후, 완전탐색을 하자!
 * '사전 순으로 출력' (N과 M(1)과 동일)
 */

int main() {
    vector<bool> check(RANGE, false); //중복 수 제거하며 받기 위한 체크 배열
    int a; //n개의 수가 될 입력들

    //입력 (중복 제거하며 num 배열에 저장하기)
    cin >> n >> m; //n개의 자연수 중에서 m개를 고르기 위한 입력
    for (int i = 0; i < n; i++) {
        cin >> a; //n개만큼 자연수를 받음
        if (!check[a]) //처음 나온 수라면
            num[leng++] = a; //num배열에 저장해줌
        check[a] = true; //그리고 나왔다고 표시함
    }

    //연산
    sort(num, num + leng); //사전 순으로 증가하도록

    //연산 + 출력
    backtracking(0); //0부터 시작

    return 0; //종료
}