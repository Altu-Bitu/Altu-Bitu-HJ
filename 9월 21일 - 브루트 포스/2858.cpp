//
// Created by user on 2021-09-25.
//

#include <iostream>

using namespace std;

int main(){
    int R,B,total,L,W,len;
    cin >> R >> B;

    total = R+B;

    for(int i=2; i<total/2; i++){
        if(i*(total/i)==total){
            int num = 2*(i+total/i)-4;
            if(num==R||num==B){
                len = i;
                break;
            }
        }
    }

    L = max(len, total/len);
    W = min(len, total/len);

    cout << L << " " << W;
    return 0;
}