//
// Created by user on 2021-11-01.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dix[8] = {1,1,1,0,0,-1,-1,-1};
int diy[8] = {-1,0,1,-1,1,-1,0,1};
//대각선까지 포함하면 동서남북+4 = 8가지 방향
int w,h;
int map[51][51];
bool visited[51][51];

void init(bool a[51][51]){
    for(int i=0; i<51; i++){
        for(int j=0; j<51; j++){
            a[i][j]=0;
        }
    }
    return;
}
void island(int x,int y){
    //바다거나 이미 방문했으면 안감
    if(!map[y][x] || visited[y][x])
        return;

    visited[y][x]=true;//방문하면 체크

    for (int i=0; i<8; i++){
        //사방팔방으로 이동
        int nx= x+dix[i];
        int ny= y+diy[i];
        if(nx>=0 && nx<w && ny>=0 && ny<h) //정해진 구간 내에서 탐색
            island(nx,ny);
    }
}
int main(){
    ios::sync_with_stdio();
    cin.tie();

    while(1){
        int cnt=0; //섬 개수 세기
        cin >> w >> h;

        if(w==0 && h==0) break; //끝

        for(int i=0; i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }
        }

        //queue<pair<int,int>> q;

        for(int i=0; i<h;i++) {
            for (int j = 0; j < w; j++){
                if(!visited[i][j]&&map[i][j]){
                    island(j,i);
                    cnt++;
                }
            }
        }

        cout << cnt <<"\n";

        //초기화
        init(visited);
    }
}