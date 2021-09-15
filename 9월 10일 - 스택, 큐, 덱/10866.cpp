//
// Created by user on 2021-09-14.
//
#include <iostream>
#include <deque>

using namespace std;

int main(){
    int N,M;
    deque<int> dq;
    string op;
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> op;
        if (op == "push_front") {
            cin >> M;
            dq.push_front(M);
        } else if (op == "push_back") {
            cin >> M;
            dq.push_back(M);
        } else if (op == "pop_front") {
            if (dq.empty())
                cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (op == "pop_back") {
            if (dq.empty())
                cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (op == "size") {
            cout << dq.size() << '\n';
        } else if (op == "empty") {
            cout << dq.empty() << '\n';
        } else if (op == "front") {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.front() << '\n';
        } else if (op == "back") {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.back() << '\n';
        }
    }
        return 0;
}