//
// Created by user on 2021-11-07.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string di[8]={"R","L","B","T","RT","LT","RB","LB"};
int dix[8] = {1,-1,0,0,1,-1,1,-1};
int diy[8] = {0,0,-1,1,1,1,-1,-1};
int kx,ky,sx,sy;

bool external(int x,int y){
    if(x>0 && y>0 && x<9 && y<9)
        return false;
    return true;
}

//해당 명령어가 나올때 해당 방향으로 킹이 이동하되(+외부인지 판단),
//돌이 겹칠 경우 돌도 움직일 수 있도록
//함수가 엄청 복잡하게 됐는데 어떻게 해야 간단하게 만들 수 있을지 모르겠네요..
void chase(string input){
    for(int i=0; i<8; i++){
        if(input==di[i]){
            //외부면 바로 탈출
            if(external(kx+dix[i],ky+diy[i])) break;
            if(kx+dix[i] == sx && ky+diy[i] == sy){
                //돌이 움직였을때 외부면 킹도 아예 안움직이므로 바로 탈출
                if(external(sx+dix[i],sx+diy[i])) break;
                sx += dix[i];
                sy += diy[i];
            }
            kx += dix[i];
            ky += diy[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie();

    string king,stone,input;
    int n;
    cin >> king >> stone >> n;

    //킹이랑 돌 초기 위치 설정(열은 알파벳으로 주어지므로 int형으로 바꿈)
    kx = king[0]-'A'+1;
    ky = king[1]-'0';
    sx = stone[0]-'A'+1;
    sy = stone[1]-'0';

    while(n--){
        cin >> input;
        chase(input);
    }

    cout << (char)(kx+'A'-1)<<ky<<"\n"<<(char)(sx+'A'-1) <<sy;

}