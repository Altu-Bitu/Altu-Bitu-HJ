//
// Created by user on 2021-11-01.
//


#include <iostream>
#include <vector>

using namespace std;

//슬라이딩 윈도우로 최대 방문자 수를 구하고, 그 기간의 수를 리턴
pair<int, int> maxVisitor(int n, int x, vector<int> &visitor) {
    //윈도우 초기화
    int section_visitor = 0; //구간 방문자
    for (int i = 0; i < x; i++) //첫날부터 x일 동안의 방문자 수
        section_visitor += visitor[i];

    int ans = section_visitor; //최대 방문자 수
    int cnt = 1; //최대 방문자 수인 기간의 수

    //슬라이딩
    for (int i = x; i < n; i++) {
        section_visitor -= visitor[i - x]; //이번 윈도우에 제외되는 값
        section_visitor += visitor[i]; //이번 윈도우에 추가되는 값
        if (section_visitor > ans) { //최대 방문자 수가 갱신된다면
            cnt = 1; //횟수 초기화
            ans = section_visitor; //최대방문자수 갱신
        } else if (section_visitor == ans) //최대 방문자 수와 같다면
            cnt++; //최대값이 나온 횟수++
    }
    return make_pair(ans, cnt); //최대 구간값과 횟수 리턴
}

int main() {
    int n, x;

    //입력
    cin >> n >> x; //블로그 시작하고 지난 일수 n, 구간합을 구할 x일
    vector<int> visitor(n, 0); //방문자 수를 저장하기 위한 vector
    for (int i = 0; i < n; i++)
        cin >> visitor[i]; //n일까지의 방문자 수 입력받음

    //연산
    //x일간의 최대 방문자수
    pair<int, int> ans = maxVisitor(n, x, visitor); //함수호출

    //출력
    if (ans.first == 0) { //최대 방문자 수가 0명이라면
        cout << "SAD\n"; //슬픔이 출력
        return 0; //바로 종료
    }
    //아니면 x일간 가장 많이 들어온 방문자수, 그러한 기간이 몇 개 있는지 출력
    cout << ans.first << '\n' << ans.second;
}