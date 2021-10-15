//
// Created by user on 2021-10-08.
//

/*
 * next_permutation 사용 참고 블로그 : https://sejinik.tistory.com/209
 * is_ground bool 참고 블로그 : https://11001.tistory.com/27
 */

#include<iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<int>> score;
vector<int> order = {0,1,2,3,4,5,6,7,8};
//vector<int> new_order;
int ans=0,player,cnt;
bool is_ground[3];

void moveField(int n){
    //뒤에서부터 필드에 이미 있던거 탐색(뒤를 먼저 비워줘야 계속 밀어내며 나아갈수있으니까..)
    for(int i=2;i >=0;--i){
        //특정 필드에 있으면
        if(is_ground[i])
        {
            if(i+n>=3) ++cnt; //밀어내기 됐을 때 점수++
            else is_ground[i+n]=true; //밀어내진 못했지만 나아가서 어딘가에 안착했을때
            is_ground[i]=false; //기존 필드에 있는거 삭제해줌
        }
    }
    //없으면
    if (n==4) ++cnt; //홈런이면 점수++
    else is_ground[n-1]=true; //아니면 필드 진출
}

int main() {
    int n;
    cin >> n;

    //선수마다 N이닝에 얻는 점수들
    score.assign(n, vector<int>(9));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 9; j++)
            cin >> score[i][j];
    }

    do{
        swap(order[0],order[3]); //가장 첫타자는 항상 4번타자
        cnt = player = 0; //조합별 점수와 타자번호(0부터지만 사실은 1번타자)
        //n번의 이닝을 모두 돌려봄
        for(int i=0; i<n; i++){
            int out=0;
            memset(is_ground, false, sizeof(is_ground)); //이닝 시작시 그라운드 초기화(필드에 아무도 없음)
            //3아웃이 될때까지 한 이닝경기 진행
            while(out !=3){
                int hit = score[i][order[player]];
                if(hit==0) out++; //못쳤으면 아웃
                else moveField(hit); //아니면 진루
                player = (player+1)%9; //다음 주자
            }
        }
        ans=max(ans,cnt); //점수 갱신
        swap(order[3],order[0]); //다시 돌려놔줌
    }while(next_permutation(order.begin()+1, order.end())); //선수조합이 중복되지 않게
    cout <<ans;
    return 0;
}
