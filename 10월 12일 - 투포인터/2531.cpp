//
// Created by user on 2021-11-02.
//

#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(vector<int> &belt, int n, int d, int k, int c) {
    //초밥 가짓수+1로 0벡터만듦
    vector<int> sushi(d + 1, 0);

    //쿠폰으로 먹은 초밥 미리 +1
    int section_sushi = 1;
    sushi[c]++;

    //윈도우 초기화
    for (int i = 0; i < k; i++) {
        sushi[belt[i]]++; //마주치는 초밥 종류마다 늘려줌
        if (sushi[belt[i]] == 1)
            section_sushi++; //고른 스시 ++
    }

    int ans = section_sushi; //답 초기화
    //왼쪽 0, 오른쪽 윈도우-1
    int left = 0, right = k - 1;
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        sushi[belt[left]]--; //옮겨가면서 빼줌
        if (!sushi[belt[left]])
            section_sushi--;//만약 0이면 아예 고른 스시에서 빠지므로 --

        //윈도우의 양 끝 이동
        left = (left + 1) % n;
        right = (right + 1) % n;

        sushi[belt[right]]++; //옮겨가면서 더해줌
        if (sushi[belt[right]] == 1)
            section_sushi++;//1이면 고른 스시 종류에 추가해줌

        ans = max(ans, section_sushi); //최대 가짓수 갱신해주기
    } while (left); //다 돌아가면 종료
    return ans; //답 리턴
}

/**
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 보석 쇼핑 문제처럼 각 종류별 먹은 초밥의 개수를 세어주기
 */
int main() {
    int n, d, k, c;

    //입력
    //접시의 수, 초밥의 종류, 연속해서 먹는 접시 수, 쿠폰번호
    cin >> n >> d >> k >> c;
    //회전초밥트랙을 벡터로
    vector<int> belt(n, 0);
    for (int i = 0; i < n; i++)
        cin >> belt[i]; //초밥의 종류 입력

    //연산 & 출력
    cout << chooseSushi(belt, n, d, k, c);
}