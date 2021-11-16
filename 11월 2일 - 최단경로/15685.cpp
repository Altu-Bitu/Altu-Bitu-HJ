//
// Created by user on 2021-11-07.
//

//레퍼런스 : https://jaimemin.tistory.com/1163#recentComments


#include <iostream>
#include <vector>

using namespace std;

int dix[8] = {1,0,-1,0};
int diy[8] = {0,-1,0,1};
//우 상 좌 하
const int MAX = 101;

bool visited[MAX][MAX];

void dragonCurve(int x, int y, int d, int g){
    vector <int> dragon;
    //초기 방향
    dragon.push_back(d);

    //세대별로 어떻게 움직일지 dragon벡터에 저장
    while(g--){
        int size = dragon.size();
        for(int j=size-1; j>=0; j--)
            //90도 돌려서 넣어줌
            dragon.push_back((dragon[j]+1)%4);
    }

    //초기 좌표 체크
    visited[y][x] = true;

    for(int i=0;i<dragon.size();i++){
        y += diy[dragon[i]];
        x += dix[dragon[i]];
        visited[y][x]=true;
    }
}

int checkRetangle(){
    int ans=0;
    for(int i=0; i<MAX-1;i++){
        for(int j=0; j<MAX-1;j++){
            //1*1 정사각형꼭짓점이 다 들어가있는지 판단
            if(visited[i][j]&&visited[i][j+1]&&visited[i+1][j]&&visited[i+1][j+1])
                ans++;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    int n;
    cin >> n;

    while(n--){
        int x,y,d,g;
        cin >> x >> y >> d >> g;

        dragonCurve(x,y,d,g);
    }

    int result = checkRetangle();
    cout << result << "\n";
    return 0;
}
