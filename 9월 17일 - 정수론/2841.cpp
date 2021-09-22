//
// Created by user on 2021-09-22.
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

        //특정 줄의 스택이 비어있으면 무조건 추가해줌
        //무조건 움직임
        if(s[play.first].empty())
        {
            cnt++;
            s[play.first].push(play.second);
        }
        else
        {
            //높은 음이면 그냥 바로 덮어써줌(손 안뗌)
            if(play.second > s[play.first].top())
            {
                cnt++;
                s[play.first].push(play.second);
            }
            //같으면 그냥 다음으로 넘어감
            else if (play.second == s[play.first].top())
                continue;
            //낮은음을 치려면 스택안에 있는 높은 음을 다 pop해줘야함(손 뗌)
            else
            {
                while(!s[play.first].empty() && play.second < s[play.first].top())
                {
                    cnt++;
                    s[play.first].pop();
                }
                //다 pop하고 남은게 치려는 음과 같다면 그냥 다음으로 넘어감
                if(!s[play.first].empty() && s[play.first].top()==play.second)
                    continue;
                //아니면 추가해줌
                cnt++;
                s[play.first].push(play.second);
            }
        }
    }
    cout << cnt << "\n";
    return 0;

}
