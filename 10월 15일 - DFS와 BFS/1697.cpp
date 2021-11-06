//
// Created by user on 2021-11-01.
//

#include <iostream>
#include <queue>

using namespace std;

bool check[100001];

int bfs_chasing(int n, int k){
    queue<pair<int,int>> q; //pair로 넣는 큐 생성
    //현 위치, 걸린 시간 순

    q.push(make_pair(n,0)); //n의 위치, 0 시간
    check[n]=true;

    while(!q.empty()){
        int x = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(x == k)
            return cost;

        //1. 1초 후 뒤로 한칸
        if(0<=x-1 && !check[x-1]) {
            q.push(make_pair(x - 1, cost + 1));
            check[x - 1] = true;
        }
        //2. 1초 후 앞으로 한칸
        if(x+1<100001 && !check[x+1]) {
            q.push(make_pair(x + 1, cost + 1));
            check[x + 1] = true;
        }
        //3. 1초 후 앞으로 *2칸
        if(x*2<100001 && !check[x*2]) {
            q.push(make_pair(x*2, cost + 1));
            check[x*2] = true;
        }
    }

}
int main(){
    int n,k;
    cin >> n >> k;

    cout << bfs_chasing(n,k) << "\n";

    return 0;
}