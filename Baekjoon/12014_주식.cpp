/*
사이트: 백준, 12014번
분류: Longest Increasing Sequence
*/

#include <iostream>
#include <cstdio>

#define SIZE 10001

using namespace std;

int main(void)
{
    int testcase;
    int n, k;
    int stock[SIZE], lis[SIZE], last = 0;
    
    scanf("%d", &testcase);
    
    for (int t = 1; t <= testcase; t++) {
        last = 0;
        scanf("%d %d", &n, &k);
        
        for(int i = 0; i < n; i++) {
            scanf("%d", stock + i);
        }

        // LIS 알고리즘 구현
        lis[0] = stock[0];
        for(int i = 1; i < n; i++) {
            if (lis[last] < stock[i]) {
                lis[++last] = stock[i];

                // LIS 배열의 크기는 곧 증가 수열의 길이가 됨
                // LIS 배열이 K보다 크거나 같다면 문제에서 제시한 조건을 만족한다는 의미
                // 더 이상 LIS 배열을 구성하지 않고 break하여 계산을 줄임
                if (last >= k) {
                    break;
                }
            } else {
                lis[lower_bound(lis, lis + last + 1, stock[i]) - lis] = stock[i];
            }
        }
        
        cout << "Case #" << t << endl;
        if (last + 1 >= k) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    
    return 0;
}