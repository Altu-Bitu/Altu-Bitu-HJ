//
// Created by user on 2021-09-04.
//

#include <iostream>

using namespace std;

char arr[401][401];

void star(int dep, int idx){
    //인자로 받은 depth로 한변의 길이 갱신
    int len = 4 * (dep - 1) + 1;
    //만약 depth가 1이면 인자로받은 idx에 별 하나 찍고 넘어감
    if(dep == 1){
        arr[idx][idx] = '*';
        return;
    }

    //맨위 맨 아래줄
    for(int i=idx;i<len+idx;i++){
        arr[idx][i] = '*';
        arr[idx + len - 1][i] = '*';
    }

    //양 옆 높이
    for(int i=idx;i<len+idx;i++){
        arr[i][idx] = '*';
        arr[i][idx + len - 1] = '*';
    }

    //재귀로 호출, 큰박스안에 작은 박스를 반복해서 쌓아가는 느낌
    //이때 작은 박스는 위옆 모두 idx+2지점에서 시작
    star(dep-1, idx+2);
    return;
}

int main(){
    int n;
    cin >> n;

    //한변의 길이
    int len = 4 *(n-1) + 1;

    //일단 공백으로 박스 만들기
    for (int i=0; i<len; i++)
        for (int j=0; j<len; j++)
            arr[i][j] = ' ';

    //별그리기
    star(n,0);

    //그린 별 출력
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}
