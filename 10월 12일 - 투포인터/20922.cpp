//
// Created by user on 2021-11-02.
//

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100000;

int findLen(vector<int> &arr, int n, int k) {
    vector<int> cnt(MAX + 1, 0); //각 원소 등장 횟수
    //답, 왼, 오 초기화
    int ans = 0, left = 0, right = 0;

    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    while (left <= right && right < n) {
        if (cnt[arr[right]] + 1 <= k) { //현재 right가 가리키는 원소를 포함해도 등장 횟수가 k번 이하
            cnt[arr[right]]++; //한칸 옮겨서 늘림
            ans = max(ans, (right - left) + 1); //최대 길이 갱신
            right++;//옮겨가니까 더해주기
        } else { //현재 right가 가리키는 원소를 포함하면 등장 횟수가 k번을 초과
            cnt[arr[left]]--; //한칸 옮겨서 줄임
            left++; //옮겨가니까 더해주기
        }
    }
    return ans; //답 리턴
}

/**
 * 1. 최장 연속 부분 수열의 '길이'를 구해야 함 -> 구간 내의 모든 원소를 고려하기 때문에 한쪽에서 시작하는 투 포인터
 * 2. 각 원소의 최댓값이 100,000이기 때문에 배열로 등장 횟수 체크할 수 있음
 * 3. right를 옮기고 바로 원소를 추가했던 기존 방법과 달리, 일단 포인터만 옮겨놓고 원소를 추가해도 되는지 확인
 */
int main() {
    int n, k;

    //입력
    cin >> n >> k; //n길이, 같은 원소가 k개 이하
    vector<int> arr(n, 0);//길이 벡터 초기화
    for (int i = 0; i < n; i++)
        cin >> arr[i]; //값 넣어줌

    //연산 & 출력
    cout << findLen(arr, n, k);
}