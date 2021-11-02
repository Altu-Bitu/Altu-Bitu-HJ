//
// Created by user on 2021-11-01.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<int, int> liquid(vector<int> &arr, int left, int right) {
    pair<int, int> ans; //리턴할 pair
    int min_diff = 2 * 1e9 + 1; //최소값

    //left는 항상 right의 왼쪽에 있어야 함
    while (left < right) {
        int mix = arr[left] + arr[right]; //두 용액을 혼합
        if (mix == 0) //그 값이 0이라면 이보다 더 0에 가까워질 수 없기 때문에 바로 리턴
            return make_pair(arr[left], arr[right]);
        if (abs(mix) < min_diff) { //0에 가까운 값을 갱신할 수 있는지 확인
            min_diff = abs(mix); //더 가까우면 갱신
            ans = make_pair(arr[left], arr[right]); //두 용액의 특성값을 저정해둠
        }
        if (mix > 0) //0보다 크면 더 작은 값을 만들어야 함
            right--; //오름차순형태이므로 왼쪽으로 이동
        else if (mix < 0) //0보다 작으면 더 큰 값을 만들어야 함
            left++; //오름차순형태이므로 오른쪽으로 이동
    }
    return ans; //리턴
}

int main() {
    int n;

    //입력
    cin >> n; //전체 용액의 수
    vector<int> arr(n, 0); //용액 vector
    for (int i = 0; i < n; i++)
        cin >> arr[i]; //용액의 특성값 입력받음

    //연산
    sort(arr.begin(), arr.end()); //오름차순 정렬
    pair<int, int> ans = liquid(arr, 0, n - 1); //호출
    //특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값

    //출력
    cout << ans.first << ' ' << ans.second; //오름차순형태
}
