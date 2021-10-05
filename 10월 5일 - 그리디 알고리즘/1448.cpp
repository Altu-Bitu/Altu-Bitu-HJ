//
// Created by user on 2021-10-05.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n,0);

    for(int i=0; i<n; i++)
        cin >> v[i];

    //오름차순 정렬
    sort(v.begin(), v.end());

    //뒤에서부터 가므로 적당한 값이 나오면 바로 끝
    for(int i=n-1; i>=2; i--){
        int a=v[i];
        int b=v[i-1];
        int c=v[i-2];
        //빗변의 길이가 나머지 두변의 합보다 작으면 삼각형
        if(a<b+c){
            cout << a+b+c;
            return 0;
        }
    }
    cout << -1;

    return 0;
}