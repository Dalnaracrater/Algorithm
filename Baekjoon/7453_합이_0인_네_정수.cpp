/*
사이트: 백준, 7453번
분류: Binary Search
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define ll long long

#define SIZE 4000

using namespace std;

int main(void) {
    int n;
    int arr[4][SIZE];
    
    vector<int> sum;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &arr[0][i], &arr[1][i], &arr[2][i], &arr[3][i]);
    }
    
    // 다른 사람들은 A, B 배열까지 더하였지만 불필요하기 때문에 구현하지 않음
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum.push_back(arr[2][i] + arr[3][j]);
        }
    }
    sort(sum.begin(), sum.end());
    
    // count 값이 최대 4000^4일 수 있으므로 64바이트 크기의 정수형 변수를 사용
    ll count = 0;
    
    // brute force 탐색은 주어진 시간 복잡도를 만족하지 않으므로 이분 탐색을 이용
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 이분 탐색(lower_bound)을 통해 arr[0][i] + arr[1][j]를 sum에서 찾음
            int lowerIdx = lower_bound(sum.begin(), sum.end(), -(arr[0][i] + arr[1][j])) - sum.begin();
            
            // upper_bound는 sum에서 찾으려는 값 (arr[0][i] + arr[1][j])가 중복될 수 있음
            // lower_bound는 최소 인덱스만을 알려주기 때문에 중복된 개수가 반영되지 않음
            int upperIdx = upper_bound(sum.begin(), sum.end(), -(arr[0][i] + arr[1][j])) - sum.begin();
            
            if (arr[0][i] + arr[1][j] + sum[lowerIdx] == 0) {
                count += (upperIdx - lowerIdx);
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}