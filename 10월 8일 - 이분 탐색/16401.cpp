//
// Created by user on 2021-10-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int childNum(vector<int> &snacks, int len) {
    int cnt = 0; //몇 명에게 나누어주는지
    for (int i = snacks.size() - 1; i >= 0; i--) { //가장 긴 과자부터 검사
        if (snacks[i] < len) //나누어주려는 길이보다 작아지면 더 이상 못 나눠줌
            break; //탈출
        cnt += (snacks[i] / len); //길이로 나눠서 몇개 나오는지 체크
    }

    return cnt; //len으로 나눠서 나오는 과자 개수
}

int upperSearch(vector<int> &snacks, int left, int right, int target) {
    int ans = 0; //막대과자의 최대 길이
    while (left <= right) {
        int mid = (left + right) / 2; //과자의 길이
        int cnt = childNum(snacks, mid); //과자 길이가 mid일 때 몇 명에게 나눠주는지

        if (cnt >= target) { //target보다 더 많은 아이들에게 나눠준다면 -> 과자 길이를 더 늘릴 수 있음
            left = mid + 1; //하한선을 땡겨줌
            ans = mid; //최대 길이 갱신해나감
        } else {
            right = mid - 1; //상한선을 땡겨줌
        }
    }

    return ans; //막대과자의 최대길이
}

/**
 * n개의 과자가 있을 때 m명의 조카에게 각각 같은 길이로 줄 수 있는 과자의 최대 길이를 구하는 문제
 * -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?
 *
 * left: 과자 길이의 최솟값 -> 1
 * right: 과자 길이의 최댓값
 *
 * 과자를 몇 명에게 나누어줄 수 있는지 차례로 검사하다 나누어줄 수 없으면 빠져나오기 위해 정렬을 먼저 해주면 좋음
 */

int main() {
    int m, n, left = 1, right = 0;

    //입력
    cin >> m >> n; //m명의 조카, n개의 과자
    vector<int> snacks(n, 0); //과자 벡터 생성
    for (int i = 0; i < n; i++)
        cin >> snacks[i]; //과자 벡터에 길이 넣어줌

    //연산
    sort(snacks.begin(), snacks.end()); //이분탐색을 위해 정렬
    right = snacks[n - 1]; //제일 긴 과자 길이

    //연산 & 출력
    cout << upperSearch(snacks, left, right, m); //함수 호출

    return 0;
}