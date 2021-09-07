//
// Created by user on 2021-09-06.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main() {
    int n;
    cin >>n;

    v.assign(n,0);
    for(int i=0; i<n; i++)
        cin>>v[i];

    //오름차순으로 정렬
    sort(v.begin(), v.end());

    int result=0;
    //오름차순 1,2,3,4면
    //1
    //1+2
    //1+2+3
    //1+2+3+4 이런식으로 n, n-1, n-2 .. 형태로 곱해진다
    for (int i=0; i<n; i++)
        result += v[i]*(n-i);

    cout <<result;
    return 0;
}
