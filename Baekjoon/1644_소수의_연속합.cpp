/*
사이트: 백준, 1644번
분류: 에라토스테네스 체 (Sieve of Eratosthenes)
*/

#include <iostream>
#include <cstdio>
#include <vector>

#define SIZE 4000001

using namespace std;

int main(void) {
    int n;
    int num[SIZE];
    
    vector<int> prime;

    scanf("%d", &n);
    
    num[0] = 1;
    // 2를 제외한 모든 짝수는 합성 수
    for(int i = 2; i * 2 <= n; i++) {
        num[i * 2] = 1;
    }
    // 홀수를 대상으로 실질적인 체 구성
    for(int i = 3; i <= n; i += 2) {
        for(int j = 2; i * j <= n; j++) {
            num[i * j] = 1;
        }
    }
    
    // 소수만을 따로 저장
    // (사실 여기에서 n만 미리 저장하고, i의 초기 값을 i/2로 하면 계산량을 줄일 수 있음)
    for(int i = n; i > 0; i—-) {
        if (num[i] == 0) {
            prime.push_back(i);
        }
    }

    // [i, j] 구간의 소수의 합이 n이 되는지 확인
    int count = 0;

    // i의 초기 값을 1로 해줘도 되는데 그러면 n이 합성수일 때 따로 처리해야 함
    for(int i = 0; i < prime.size(); i++) {
        for(int j = i; j < prime.size(); j++) {
            int sum = 0;
            for(int k = i; k < j; k++) {
                sum += prime[k];
            }
            if (sum == n) {
                count++;
            }
            // 기존 sum에 소수를 추가하지 않아도 되므로 break
            else if (sum > n) {
                break;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}