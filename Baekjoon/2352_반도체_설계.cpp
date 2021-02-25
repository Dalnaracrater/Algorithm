/*
사이트: 백준, 2352번
분류: Longest Increasing Sequence
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, arr[40000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    int lis[40000], last = 0;
    lis[last] = arr[0];

    // 최장 증가 수열 구성
    for (int i = 1; i < n; i++) {
        if (lis[last] < arr[i]) {
            lis[++last] = arr[i];
        }
        // 새로운 자료가 기존 LIS 범위 안에 있는 경우,
        // 이진탐색 (lower_bound)을 통해 위치를 찾고 해당 위치에 자료를 저장
        else {
            lis[lower_bound(lis, lis + last + 1, arr[i]) - lis] = arr[i];
        }
    }

    cout << last + 1;

    return 0;
}