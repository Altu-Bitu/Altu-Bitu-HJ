//
// Created by user on 2021-10-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

//이분 탐색
bool binarySearch(int left, int right, int target) {
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 break
        int mid = (left + right) / 2; //중간값
        if (arr[mid] == target) //target을 찾음
            return true; //찾았다고 리턴
        if (arr[mid] > target) //중간값이 target보다 크다면 target은 왼쪽에 있음
            right = mid - 1; //왼쪽에 있으니까 오른쪽을 땡겨줌
        if (arr[mid] < target) //중간값이 target보다 작다면 target은 오른쪽에 있음
            left = mid + 1; //오른쪽에 있으니까 왼쪽을 땡겨줌
    }
    return false; //target을 찾지 못함
}

int main() {
    //속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //n개의 정수, 존재하는지 판별할 m개의 수, 그 m개의 수들 input
    int n, m, input;

    //입력
    cin >> n;
    arr.assign(n, 0); //벡터 생성
    for (int i = 0; i < n; i++)
        cin >> arr[i]; //값 넣어줌

    //연산
    sort(arr.begin(), arr.end()); //이분 탐색을 하기 위해선 반드시 정렬을 해야함

    //입력
    cin >> m;
    while (m--) {
        cin >> input; //찾을 값을 넣어줌

        //연산 & 출력
        cout << binarySearch(0, n - 1, input) << '\n';
        //cout << binary_search(arr.begin(), arr.end(), input) << '\n';
    }
}