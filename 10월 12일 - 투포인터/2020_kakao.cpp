//
// Created by user on 2021-11-01.
//


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

//시간복잡도 O(n^2) -> 정확성 O, 효율성 X
vector<int> gemList(vector<string> &gems, int gem_size) {
    int size = gems.size();
    vector<int> ans = {1, size};

    for (int i = 0; i < size; i++) { //i로 시작하는 구간
        map<string, int> m; //구간에 있는 보석
        for (int j = i; j < size; j++) { //j에서 끝나는 구간
            m[gems[j]]++; //보석 추가
            if (m.size() == gem_size) { //모든 종류의 보석이 있음
                if (j - i < ans[1] - ans[0]) //최단 구간 갱신
                    ans = {i + 1, j + 1};
                break; //더이상 구간을 늘릴 필요 없음
            }
        }
    }
    return ans;
}

//시간복잡도 O(n) -> 정확성 O, 효율성 O
vector<int> gemListTwoPointer(vector<string> &gems, int gem_size) {
    //왼쪽 오른족 0에서 시작, 사이즈는 진열대 사이즈
    int left = 0, right = 0, size = gems.size();
    vector<int> ans = {1, size}; //초기화(일단은 제일 긴 첨부터 끝까지)
    map<string, int> m; //구간 나누기 위한 맵
    m[gems[left]]++; //초기 구간

    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    while (left <= right && right < size) {
        if (m.size() == gem_size) { //모든 종류의 보석이 있음
            if (right - left < ans[1] - ans[0]) //최단 구간 갱신
                ans = {left + 1, right + 1}; //진열대니까 1씩 더해줌
            left++; //구간을 짧게하기 위해 left 이동
            m[gems[left - 1]]--; //이동했으니까 빼줌
            if (m[gems[left - 1]] == 0) //더이상 이 보석이 없다면 제거
                m.erase(gems[left - 1]);
        } else if (m.size() < gem_size) { //모든 종류의 보석이 있는게 아니라면
            right++; //구간을 길게하기 위해 right 이동
            if (right == size) //런타임 에러 방지
                break; //사이즈에 도달하면 탈출
            m[gems[right]]++; //이동했으므로 넣어줌
        }
    }
    return ans; //답 리턴
}

vector<int> solution(vector<string> gems) {
    vector<int> answer; //답 벡터

    set<string> unique_gem; //중복없이 저장하는 셋
    for (int i = 0; i < gems.size(); i++)
        unique_gem.insert(gems[i]);//보석 종류 넣어줌
    int gem_size = unique_gem.size(); //보석의 종류

    answer = gemListTwoPointer(gems, gem_size); //보석 쇼핑
    return answer;//답 리턴
}

int main() {
    //입력
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};

    //연산
    vector<int> ans = solution(gems);

    //출력
    cout << ans[0] << ' ' << ans[1];
}