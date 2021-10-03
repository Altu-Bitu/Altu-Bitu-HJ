//
// Created by user on 2021-10-03.
//

#include <iostream>
#include <deque>

using namespace std;

deque<int> deck[2]; //0이 도도, 1이 수연
deque<int> ground[2];

string cardGame(int m){
    int turn = 0; //도도부터 시작
    while(m--){
        //1. 그라운드 카드 내놓기
        ground[turn].push_front(deck[turn].front());
        deck[turn].pop_front();
        if(deck[turn].empty())
            break;
        //2. 그라운드 카드 빼앗기
        //수연이가 종을 치는 경우 => 그라운드 카드 합이 5, 그라운드 비어있으면 안됨
        if((ground[0].front() + ground[1].front() == 5) && !ground[0].empty() && !ground[1].empty()){
            //그라운드에 있는 것들 수연이가 싹쓸이 해감
            //도도꺼부터
            while (!ground[0].empty())
            {
                deck[1].push_back(ground[0].back());
                ground[0].pop_back();
            }
            //그다음 자기꺼
            while (!ground[1].empty())
            {
                deck[1].push_back(ground[1].back());
                ground[1].pop_back();
            }
        }
        //도도가 종을 치는 경우 => 그라운드에서 가장 위에 있는 카드가 5
        else if((!ground[0].empty() && ground[0].front() == 5) || (!ground[1].empty() && ground[1].front() == 5)){
            while (!ground[1].empty())
            {
                deck[0].push_back(ground[1].back());
                ground[1].pop_back();
            }
            while (!ground[0].empty())
            {
                deck[0].push_back(ground[0].back());
                ground[0].pop_back();
            }
        }
        //3. 턴바꾸기
        if (turn==1) turn = 0;
        else turn = 1;
    }
    // 4. 승패가르기
    if(deck[0].size()>deck[1].size())
        return "do";
    else if (deck[0].size()<deck[1].size())
        return "su";
    return "dosu";
}

int main() {
    int n,m,c1,c2;
    cin >>n >>m;
    while(n--){
        cin >> c1 >> c2;
        deck[0].push_front(c1);
        deck[1].push_front(c2);
    }
    cout << cardGame(m) << "\n";

}