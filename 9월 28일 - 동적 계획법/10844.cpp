//
// Created by user on 2021-10-03.
//

#include <iostream>
#define mod 1000000000
using namespace std;

int dp[101][10];

int main(){
    int n;
    cin >> n;

    //1자리
    for(int i=1; i<=9; i++)
        dp[1][i]=1;

    //i는 수의 길이. j는 숫자
    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j+1] % mod; // 0일땐 1만
            } else if(j == 9){
                dp[i][j] = dp[i-1][j-1] % mod; // 9일땐 8만
            } else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod; //나머지는 자릿수 안바뀌므로 앞뒤 다가능
            }
        }
    }

    int sum = 0;

    for(int i=0; i<=9; i++){
        sum = (sum + dp[n][i]) % mod;
    }

    cout << sum << "\n";

    return 0;
}