//
// Created by user on 2021-09-09.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int w, start_i, t, d, intake, a;

    //차례대로 필요한거 입력받음
    cin >> w >> start_i >> t;
    cin >> d >> intake >> a;

    //기초대사량이 변화하지 않는 경우에는 그냥 문제식으로 날짜 곱해서 단순 계산
    int w1 = w + d * (intake - (start_i+a));
    if(w1 <=0) //기초대사 안변하니까 체중이 0으로 내려갈때만 고려
        cout << "Danger Diet\n";
    else
        cout << w1 << " " << start_i << "\n";

    int flag =1; //살아있음을 나타내는 플래그
    int energy; // 일일 에너지 소비량(기초대사량+활동대사량)
    int ing_i = start_i; // 이제 기초대사량이 변화하기 때문에 변수를 따로 받아줌

    //디데이를 줄여가면서 계산
    while(d--){
        energy = ing_i + a;
        w += (intake-energy); //섭취-소비를 통해 빠진 체중(음수)를 기존 체중에 더해줌

        //절대값으로 역치랑 비교해서 크면 기초대사량에 밑처럼 더해줌
        if(abs(intake-energy)>t){
            ing_i += (int)floor((intake-energy)/2.0);
        }
        //체중이 0이하가 되거나 기초대사량이 0이하가 되면 뎀짐
        if( w<=0 || ing_i <= 0){
            cout << "Danger Diet\n";
            flag = 0;
            break;
        }
    }

    //뎀지지 않은 경우
    if (flag){
        cout << w << " " << ing_i << " ";
        if (start_i - ing_i > 0 ) //처음 기초대사량에서 이후 기초대사량을 뺀 게 양수면 요요
            cout << "YOYO\n";
        else
            cout << "NO\n";
    }
    return 0;
}
