//
// Created by user on 2021-09-24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

deque <bool> existence;
deque <int> durability;
int step=0;
int n,k,a;

void rotation(){
    // 1 2 3 4 5
    // 5 4 3 2 1
    // 이렇게 만들어주기
    existence.push_front(existence.back());
    existence.pop_back();

    durability.push_front(durability.back());
    durability.pop_back();

    //여기 있는 로봇은 내려줌
    if (existence[n-1] == true)
        existence[n-1]=false;
}

void movement(){
    for(int i=n-2; i>=0; i--){
        if(!existence[i+1] && durability[i+1]>0 && existence[i]){
            existence[i]=false;
            durability[i+1]--;
            if(i==n-2) //한 칸 넘어가면 로봇을 내려야하는 상황이면 걍 넘어감
                continue;
            existence[i+1]=true;
        }
    }

}

void deployment(){
    if(!existence[0]&&durability[0]>0){
        existence[0]=true;
        durability[0]--;
    }
}

int check() {
    int cnt = 0;
    for(int i=0; i< 2*n; i++){
        if (durability[i]==0)
            cnt++;
    }
    return cnt;
}

//벨트 회전 -> 로봇 이동 -> 로봇 올림
int main(){
    cin >> n >> k;
    for (int i=0; i<2*n; i++){
        cin >> a;
        durability.push_back(a);
        existence.push_back(false);
    }
    while(1){
        if(check()>=k){
            cout << step << "\n";
            break;
        }
        step++;
        rotation();
        movement();
        deployment();
    }
}