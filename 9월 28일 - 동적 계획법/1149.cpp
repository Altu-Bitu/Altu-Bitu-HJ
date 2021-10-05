//
// Created by user on 2021-10-03.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int d[1001][3] = { 0, }; //비용의 최솟값
    int cost[1001][3] = { 0, }; //색칠 했을 때의 각각의 비용
    int n = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        //빨강 0 초록 1 파랑 2
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    for (int i = 1; i <= n; ++i)
    {
        //ex)3번째에 빨간색을 칠하고 싶으면 빨간색을 칠하는 비용과
        //2번째에 초록색과 파랑색 중 더 최소 비용인 놈을 더해줌
        d[i][0] = cost[i][0] + min(d[i - 1][1], d[i - 1][2]);
        d[i][1] = cost[i][1] + min(d[i - 1][0], d[i - 1][2]);
        d[i][2] = cost[i][2] + min(d[i - 1][0], d[i - 1][1]);
    }

    cout << min(d[n][0],min(d[n][1], d[n][2]) ) << "\n";

    return 0;

}
