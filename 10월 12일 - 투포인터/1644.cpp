//
// Created by user on 2021-11-01.
//


#include <iostream>
#include <vector>

using namespace std;

//에라토스테네스의 체로 n 이하인 모든 소수 구하기
vector<bool> isPrime(int n) {
    vector<bool> is_prime(n + 1, true); //소수 여부 저장

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) { //i가 소수라면
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false; //i의 배수 제거
        }
    }
    return is_prime; //소수여부 판단한 벡터 리턴
}

//n 이하의 모든 소수
vector<int> primeList(vector<bool> &is_prime) {
    vector<int> prime_list;//소수 리스트

    for (int i = 2; i <= is_prime.size(); i++) {
        if (is_prime[i])//소수면
            prime_list.push_back(i);//넣어줌
    }
    return prime_list; //소수 리스트 리턴
}

//같은 위치에서 시작하여 같은 방향으로 이동하는 투 포인터
int findSum(vector<int> &prime_list, int target) {
    int ans = 0; //답 초기화
    //사이즈는 소수 리스트 사이즈, 왼쪽 오른쪽은 둘다 0으로 초기화
    int size = prime_list.size(), left = 0, right = 0;
    int sum = prime_list[left]; //초기 구간

    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    //right는 항상 size보다 작은 값이어야 함
    while (left <= right && right < size) {
//        if (sum == target) { //구간의 합이 target과 같을 때
//            ans++; left++; right++; //모든 포인터 이동
//            if (right == size)
//                break;
//            sum -= prime_list[left - 1]; //이번 구간에 제외되는 값
//            sum += prime_list[right]; //이번 구간에 추가되는 값
//        } else if (sum > target) { //구간의 합이 target보다 클 때
//            left++; //합을 작게하기 위해 left 이동
//            sum -= prime_list[left - 1];
//        } else if (sum < target) { //구간의 합이 target보다 작을 때
//            right++; //합을 크게하기 위해 right 이동
//            if (right == size)
//                break;
//            sum += prime_list[right];
//        }
        if (sum >= target) { //구간의 합이 target보다 크거나 같다면
            if (sum == target) //같다면
                ans++;
            left++; //합을 작게하기 위해 left 이동
            sum -= prime_list[left - 1]; //이동했으므로 left이전꺼는 빼줌
        } else if (sum < target) { //구간의 합이 target보다 작을 때
            right++; //합을 크게하기 위해 right 이동
            if (right == size) //사이즈에 도달하면
                break; //탈출
            sum += prime_list[right]; //이동했으므로 right꺼 더해줌
        }
    }
    return ans; //경우의 수 리턴
}

int main() {
    int n;

    //입력
    cin >> n;

    //연산
    vector<bool> is_prime = isPrime(n); //n이하의 수들이 소수인지 판단하여 저장
    vector<int> prime_list = primeList(is_prime); //소수인 수들을 벡터로 저장
    int ans = findSum(prime_list, n);
    //연속된 소수의 합으로 나타낼 수 있는지 판단하는 함수 호출

    //출력
    cout << ans;
}
