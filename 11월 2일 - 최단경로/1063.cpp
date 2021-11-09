//
// Created by user on 2021-11-07.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

map <string,int> di={{"R",0},{"L",1},{"B",2},{"T",3},{"RT",4},{"LT",5},{"RB",6},{"LB",7}};
int dix[8] = {1,-1,0,0,1,-1,1,-1};
int diy[8] = {0,0,-1,1,1,1,-1,-1};
int kx,ky,sx,sy;

string pointToString(int x, int y) {
    string ans;
    ans = (x + 'A'-1);
    ans += (y + '0');
    return ans;
}

bool isExternal(int x,int y){
    if(x>0 && y>0 && x<9 && y<9)
        return false;
    return true;
}

void moveKing(string input){
    int i = di[input];
    //외부면 바로 탈출
    if(isExternal(kx+dix[i],ky+diy[i]))
        return;
    if(kx+dix[i] == sx && ky+diy[i] == sy){
        //돌이 움직였을때 외부면 킹도 아예 안움직이므로 바로 탈출
        if(isExternal(sx+dix[i],sy+diy[i]))
            return;
        sx += dix[i];
        sy += diy[i];
    }
    kx += dix[i];
    ky += diy[i];
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
        moveKing(input);
    }

    cout << pointToString(kx,ky)<< "\n" << pointToString(sx,sy)<<"\n";
    //cout << (char)(kx+'A'-1)<<ky<<"\n"<<(char)(sx+'A'-1) <<sy;
    return 0;
}