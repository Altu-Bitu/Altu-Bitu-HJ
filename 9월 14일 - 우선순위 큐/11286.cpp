//
// Created by user on 2021-09-18.
//

#include<iostream>
#include<queue>

using namespace std;

//cmp 구조체 선언. 비교연산이 true가 되도록
struct cmp {
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
    }
};

priority_queue<int, vector<int>, cmp> pq;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, num;
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> num;
        if (num) {
            pq.push(num);
        }
        else {
            if (pq.empty())
                cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}

