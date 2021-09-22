//
// Created by user on 2021-09-22.
//


#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000001;
int visited[MAX];
vector<int> prime;

void isOddPrime()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    visited[0] = visited[1] = -1; //0,1은 미포함
    for(int i=2; i<MAX; i++)
        visited[i] = i;

    //체에 걸러 내기..
    for(int i=2; i*i<MAX; i++)
        if(visited[i]==i)
            for(int j =i*i; j <MAX; j+=i)
                if(visited[j]==j)
                    visited[j]=i;

    //홀수 소수
    for(int i=3;i<MAX;i++)
        if(visited[i]==i)
            prime.push_back(i);
}

int main(){
    isOddPrime(); //홀수인 소수 셋업

    while(1)
    {
        int n;
        bool flag=false; //적당한 값을 찾지 못한 상태
        cin >>n;
        if(n==0)
            break;

        for(int i=0; i<prime.size(); i++)
            if(visited[n-prime[i]]==n-prime[i]) //n-prime[i]인 소수 찾기
            {
                cout<< n << " = " << prime[i] << " + " << n-prime[i] << "\n";
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
