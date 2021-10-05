//
// Created by user on 2021-10-03.
//

#include <iostream>
using namespace std;

int main() {
    int dp[10001]={0,};
    int n, k, coin[101];
    int i,j;

    cin >>n >>k;

    //초기화
    for(i=1;i<=k;i++){
        dp[i]=10001;
    }

    //ex) 15원을 원래 만들 수 있던 동전개수와
    //15에서 자기 자신을 뺀 상태의 동전개수에 자기를 더해서 나오는 동전개수 비교
    for(i=1; i <= n; i++){
        cin >> coin[i];
        for(j=coin[i];j<=k;j++){
            dp[j]=min(dp[j],dp[j-coin[i]]+1);
        }
    }
    if(dp[k]==10001) cout <<-1<<"\n";
    else cout << dp[k] << "\n";

    return 0;
}