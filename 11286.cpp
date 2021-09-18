//
// Created by user on 2021-09-18.
//

#include<iostream>
#include<queue>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, num;
    cin >> N;

    //{절댓값,진짜값} + 작은 게 가장 먼저
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i = 0;i < N;i++) {
        cin >> num;
        if (num) {
            pq.push({ abs(num), num });
        }
        else {
            if (pq.empty())
                cout << 0 << "\n";
            else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}

