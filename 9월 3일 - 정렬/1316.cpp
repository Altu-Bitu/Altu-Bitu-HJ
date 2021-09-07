//
// Created by user on 2021-09-04.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    int count = 0;
    string str;

    //단어개수 입력받기
    cin >> n;
    //단어 입력받기(하나 입력받을때마다 체크하는 형식)
    for (int i =0; i<n; i++){
        cin >> str;
        bool flag = true; //그룹문자인지 확인하는 flag
        int alp[26]={0,}; //알파벳당 인덱스를 부여할 배열
        int len = str.length(); //단어 길이

        for(int j=0; j<len; j++)
        {
            alp[(int)str[j]-97]++; //알파벳 개수 세기. a면 alp[0]++, b면 alp[1]++...

            //1. j가 1보다 크고
            //2. 특정 알파벳이 1번이상 나온 상태이고
            //3. 바로 이전에 나온 알파벳과 다르면
            //그룹 문자가 아니기 때문에 flag를 바꾸고 탈출
            if(j>=1 && alp[(int)str[j]-97]>1 && str[j]!=str[j-1]){
                flag=false;
                break;
            }
        }
        //위의 if문에 걸리지 않고 flag가 그대로 true면 그룹문자 갯수++
        if (flag == true)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}

