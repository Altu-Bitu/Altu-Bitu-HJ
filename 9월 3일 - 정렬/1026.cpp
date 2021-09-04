//
// Created by user on 2021-09-04.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A;
vector<int> B;

int main() {
    int n;
    //n, A배열, B배열에 각각 입력 받음
    cin >> n;
    A.assign(n,0);
    for (int i=0; i<n;i++)
        cin >> A[i];
    B.assign(n,0);
    for (int i=0; i<n;i++)
        cin >> B[i];

    //두 배열 다 오름차순으로 정렬
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int min =0;
    //하나는 오름차순 그대로, 하나는 오름차순을 거꾸로 거슬러가면서
    //최소값을 만듦
    for (int i=0; i<n; i++)
        min += A[i]*B[n-1-i];

    cout << min;
    return 0;
}
