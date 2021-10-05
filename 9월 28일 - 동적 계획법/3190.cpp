//
// Created by user on 2021-10-03.
//

#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

const int SIZE = 100;

typedef struct {
    int y,x;
}dir;

dir dxy[4] = { {0,1}, {1,0},{0,-1},{-1,0}};
//오른쪽 위쪽 왼쪽 아래쪽
int K, N, L;
bool apple[SIZE][SIZE];
bool visited[SIZE][SIZE];
deque<pair<int,char>> rotation;
deque<pair<int,int>> snake;

int snakeMove(){
    int sec = 0, idx = 0;
    snake.push_back({0,0});
    visited[0][0]=true;

    while(1){
        sec++;
        pair<int,int> before = snake.back();
        pair<int,int> cur = {before.first + dxy[idx].y, before.second+dxy[idx].x};
        if (visited[cur.first][cur.second]||!(0 <= cur.first && cur.first < N && 0 <= cur.second && cur.second < N))
        {
            return sec;
        }
        visited[cur.first][cur.second] = true;
        snake.push_back(cur);

        //사과 검증
        if(apple[cur.first][cur.second]){
            apple[cur.first][cur.second]=false;
        }
        else{
            pair<int,int> tail = snake.front();
            visited[tail.first][tail.second]=false;
            snake.pop_front();
        }

        //방향 전환
        if(rotation.size() && rotation.front().first == sec)
        {
            if(rotation.front().second == 'L')
                idx = (idx+3)%4;
            else
                idx = (idx+1)%4;
            rotation.pop_front();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    cin >> K;
    while(K--){
        int y,x;
        cin >> y >> x;
        apple[y-1][x-1] = true;
    }

    cin >> L;
    while(L--){
        int X;
        char C;
        cin >> X >> C;
        rotation.push_back({X,C});
    }

    int res = snakeMove();
    cout << res << "\n";

}