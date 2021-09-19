//
// Created by user on 2021-09-18.
//

#include <iostream>
#include <queue>

using namespace std;

//최소값은 작은거부터 더해야 최소값~
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

   while(n--){
        long long num;
        cin >> num;
        pq.push(num);
    }
    while(m--){
        long long sum1 = pq.top(); pq.pop();
        long long sum2 = pq.top(); pq.pop();
        pq.push(sum1+sum2);
        pq.push(sum1+sum2);
    }

    long long res = 0;
    while(!pq.empty()){
        res += pq.top(); pq.pop();
    }
    cout << res;
    return 0;
}
