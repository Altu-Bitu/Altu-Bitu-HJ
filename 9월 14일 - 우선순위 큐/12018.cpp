//
// Created by user on 2021-09-18.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<int> my;

    for(int i=0; i< n;i++)
    {
        int p,l;
        cin >> p >> l;

        vector<int> list(p);

        for(int j=0; j<p; j++)
            cin >> list[j];

        if(p<l){
            my.push_back(1);
            continue;
        }
        sort(list.begin(), list.end(), greater<int>());
        my.push_back(list[l-1]);
    }

    sort(my.begin(), my.end());

    int idx = 0;
    while(idx<my.size()&&(m>=my[i])){
        m-=my[i];
        idx++;
    }

    cout << idx << "\n";
    return 0;
}
