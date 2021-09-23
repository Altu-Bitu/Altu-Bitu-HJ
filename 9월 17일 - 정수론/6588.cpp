//
// Created by user on 2021-09-22.
//


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;

vector<bool> isPrime()
{
    vector<bool> prime;
    prime.assign(MAX+1, true);
    prime[0] = prime[1] = false; //0,1은 미포함

    //체에 걸러 내기..
    for(int i=2; i <= sqrt(MAX); i++){
        if(!prime[i]) continue;
        for(int j =i*i; j <=MAX; j+=i)
            prime[j]=false;
    }

    return prime;
}

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    vector<bool> prime;
    prime = isPrime(); //소수 셋업

    while(1)
    {
        int n;
        bool flag=false; //적당한 값을 찾지 못한 상태
        cin >>n;
        if(n==0)
            break;

        for(int i=3; i<prime.size()/2; i+=2)
            if(prime[i]&&prime[n-i])
            {
                cout<< n << " = " << i << " + " << n-i << "\n";
                flag = true;
                break;
            }

        if(!flag){
            cout << "Goldbach's conjecture is wrong." << "\n";
            break;
        }
    }
    return 0;
}
