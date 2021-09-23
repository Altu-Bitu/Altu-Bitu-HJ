//
// Created by user on 2021-09-23.
//
#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n,p;
    cin >> n >> p;

    stack<int> s[7]; //줄 개수 만큼 스택 배열
    int cnt=0;

    while(n--){
        pair<int, int> play;
        cin >> play.first >> play.second;
        bool now_push = false;

        if(s[play.first].empty())
        {
            cnt++;
            s[play.first].push(play.second);
        }
        else {
            while(!s[play.first].empty())
            {
                //같은 음이면 탈출
                if(play.second == s[play.first].top()){
                    now_push = true;
                    break;
                }
                //높은 음이면 넣어줌
                else if(play.second > s[play.first].top()){
                    cnt++;
                    s[play.first].push(play.second);
                    now_push = true;
                    break;
                }
                //낮은 음이면 빼줌
                cnt++;
                s[play.first].pop();
            }
            //빼기만 하고 안넣어줬으면 넣어줌
            if(!now_push)
            {
                cnt++;
                s[play.first].push(play.second);
            }
        }
    }
    cout << cnt << "\n";
    return 0;

}

