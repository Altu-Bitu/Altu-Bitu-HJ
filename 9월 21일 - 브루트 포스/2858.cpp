//
// Created by user on 2021-09-25.
//

#include <iostream>

using namespace std;

int main(){
    int R,B;
    cin >> R >> B;

    //빨간색 타일이 갈색 타일을 다 덮어야만 하므로 빨간색 타일 수 기준
    //최소 3*3부터(빨간색이 8, 갈색이 1이므로)
    for(int W=3;W<5000;W++){
        for(int L=3; L<5000; L++){
            if((2*(W-2)+(2*(L-2))+4)==R){
                if(L*W == (R+B) && L >= W){
                    cout << L << ' ' << W << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}