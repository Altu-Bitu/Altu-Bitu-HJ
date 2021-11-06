//
// Created by user on 2021-11-01.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, num; //n개의 수, 구간합 구할 횟수 m, 각각의 수 num

    //입력
    cin >> n >> m;
    vector<int> sum(n + 1, 0); // n개의 수를 담을 sum vector 생성
    //**n까지 쓸것이므로 n+1로 벡터 초기화 생성
    for (int i = 1; i <= n; i++) { //인덱스를 1부터 시작하면 i=0인 경우를 따로 처리할 필요 없음
        cin >> num; //num입력 받음
        sum[i] = sum[i - 1] + num; //첫번째 수부터 i번째 수까지의 누적합
    }

    //횟수가 다 할 때까지
    while (m--) {
        int s, e; //구간합 구할 start와 end지점
        cin >> s >> e; //입력받음

        //출력
        //1~3이면 3번째까지 더한 누적합에서 0번째까지의 누적합을 빼면
        //[1][2][3]구간합이 구해짐
        cout << sum[e] - sum[s - 1] << '\n';
    }
}