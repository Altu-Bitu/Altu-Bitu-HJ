//
// Created by user on 2021-09-06.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int testcase;
    cin >> testcase;

    //테스트 케이스 갯수만큼 for문(순위로 합격자정하는)돌리기
    for (int i=0; i<testcase; i++)
    {
        int n;
        cin >> n;

        pair <int,int> applyer[100001];
        for(int i=0; i<n; i++)
            cin >> applyer[i].first >> applyer[i].second;

        //pair중 첫번째(서류)로 오름차순 정렬
        sort(applyer, applyer+n);

        int approved = 1; //서류 일등은 다른 지원자보다 무조건 하나는 높으므로 합격자는 한명에서 시작
        int min = applyer[0].second; //일등의 인터뷰순위

        for (int i=1; i<n; i++)
        {
            //서류 일등(나중엔 갱신됨)보다 인터뷰 순위가 떨어지는 애들은 합격못함
            if(applyer[i].second < min)
            {
                //인터뷰순위가 높으면 approved되고, 순위를 업뎃함
                approved++;
                min = applyer[i].second;
            }
        }
        cout << approved << "\n";
    }
    return 0;
}
