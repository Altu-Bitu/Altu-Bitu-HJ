//
// Created by user on 2021-09-04.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//y가 같으면 x가 증가하는 순으로 정렬하는 함수
bool cmp(pair<int,int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    int n,x,y;
    vector<pair<int,int>> v;
    cin >> n;

    //입력받은 두 값을 pair로 묶어주기
    for(int i=0; i<n; i++){
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    //정렬
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << "\n";

    return 0;

}