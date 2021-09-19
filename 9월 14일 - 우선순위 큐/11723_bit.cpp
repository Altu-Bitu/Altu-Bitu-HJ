//
// Created by user on 2021-09-19.
//

#include <iostream>

using namespace  std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int bit=0;
    int M;
    cin >> M;

    while(M--)
    {
        int n;
        string s;
        cin >> s;

        // add 1 , add 2라고 가정하면
        // 0 | 1<<1 = 0 | 1 = 1
        // 1 | 1<<2 = 01 | 10 = 11
        // remove 2 라고 가정하면
        // 11 & ~(1<<2) = 11 & 01 = 01
        // 이런식으로 .. ?!
        if(s=="add")
        {
            cin >> n;
            bit |= (1<<n);
        }
        else if(s=="remove")
        {
            cin >> n;
            bit &= ~(1<<n);
        }
        else if(s=="check")
        {
            cin >> n;
            if (bit & (1 << n))    cout << 1 << '\n';
            else    cout << 0 << '\n';
        }
        else if (s=="toggle")
        {
            cin >> n;
            bit ^= (1 << n);
        }
        else if (s=="all")
            bit = (1 << 21) - 1;
        else
            bit = 0;
    }
    return 0;
}