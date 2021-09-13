//
// Created by user on 2021-09-09.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace  std;

int main() {
    int t,n;
    cin >> t;

    while (t--)
    {
        vector<int> v;
        map<string,int> m;
        cin >> n;

        //옷 종류에 따라 map에 저장
        while (n--){
            string cloth, kind;
            cin >> cloth >> kind;
            m[kind]++;
        }

        int ans =1;
        map<string,int>::iterator iter;

        //map을 순회하면서 (종류내의 옷 개수+1)을 곱해줌
        //ex) 상의가 빨간티 하얀티 2개라면 빨간티를 입는것, 하얀티를 입는것, 티를 입지 않는 것 해서 *(2+1)을 해주는 것
        for (iter = m.begin(); iter != m.end(); iter++)
            ans *=(iter->second+1);
        cout << ans-1 << "\n"; //전부다 입지 않음으로써 알몸이 되는 경우 한번을 빼줌

    }
    return 0;
}
