//
// Created by user on 2021-10-08.
//

#include <iostream>

using namespace std;
bool is_switched[101];

int main() {
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> is_switched[i];
    }
    int std_num;
    cin >> std_num;
    while(std_num--){
        int gender, num;
        cin >> gender >> num;

        //남자면 받은 수의 배수들을 반전
        if(gender==1){
            for(int i=num; i<=n; i+=num)
            {
                is_switched[i]= !is_switched[i];
            }
        }
        //여자면 일단 받은 수는 어짜피 반전됨
        //그리고 받은 수 양 옆이 같은지 보고 같으면 받은 수 빼고 반전시켜줌
        //넓혀가도 같으면 또 반전... 반복(구간벗어나기 전까지)
        else{
            is_switched[num]= !is_switched[num];
            for(int i=1; (is_switched[num+i]==is_switched[num-i])&&num+i<=n&&num-i>=1;i++){
                is_switched[num+i] =!is_switched[num+i];
                is_switched[num-i] =!is_switched[num-i];
            }
        }
    }
    for (int i=1; i<=n; i++){
        cout << is_switched[i] << " ";
        if(i%20 ==0) //20개씩
            cout << "\n";
    }
}