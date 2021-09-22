//
// Created by user on 2021-09-22.
//

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a%b == 0) return b;
    return gcd(b, a%b);
}

//찾아야 되는 두 수를 A, B라고 하면
//A=aG , B= bG (a와 b는 서로소)
//L=abG
//L/G=a*b
//즉, L/G의 약수 중에 서로소인 것을 찾으면 됨

int main() {
    int G,L;
    int x;
    long long res1 = 1, res2=1;

    cin >> G >> L;

    L = L/G;

    for(int i=1; i*i <=L; i++){
        //두 수의 최대 공약수가 1인지 확인(서로소 확인)
        if(L%i==0 && gcd(i, L/i)==1){
            x=i;
            break;
        }
    }

    res1 = G * x;
    res2 = G * (L/x);

    cout << res1 << " " << res2;
    return 0;
}