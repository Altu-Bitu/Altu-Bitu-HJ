//
// Created by user on 2021-10-05.
//

#include <iostream>

long long dist[100001];
long long oil[100001];
int N;

using namespace std;

long long checkMin(){
    long long min_oil = oil[0];
    long long cost = 0;

    //최소 오일이 갱신되면 주유하러 움직인거니까 코스트에 거리로 곱해줌
    for(int i=0; i<N; i++){
        if(oil[i]<min_oil)
            min_oil = oil[i];
        cost += min_oil * dist[i];
    }
    return cost;
}

int main() {
    cin >> N;

    for(int i=0; i<N-1; i++) //N-1개
        cin >> dist[i];
    dist[N-1]=0; //N-1번쩨 0으로 설정
    for(int i=0; i<N;i++)
        cin >> oil[i];

    cout << checkMin() << "\n";

    return 0;
}