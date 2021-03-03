/*
번호: 백준, 2098
분류: bit mask, dp
*/

#include <iostream>
#include <cstdio>
#include <cstring>

#define SIZE 16
#define INF 10e8+1

using namespace std;

int n;
int mm[SIZE][SIZE], dp[SIZE][1 << SIZE];

int tsp(int cur, int state);

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        for (int j = 0; j < n; j++) {
            scanf("%d", &temp);
            if (temp) {
                mm[i][j] = temp;
            }
            else {
                mm[i][j] = INF;
            }
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << tsp(0, 1) << endl;

    return 0;
}

int tsp(int cur, int state) {
    // 모든 마을을 순회했을 때, 맨 처음 마을로 다시 돌아감
    if (state == (1 << n) - 1) {
        return mm[cur][0];
    }

    // 이미 state 마을들을 순회한 최소 값을 알 때
    // 메모이제이션을 통해 계산 없이 바로 반환
    if (dp[cur][state] != -1) {
        return dp[cur][state];
    }

    // 기존에 방문한 마을을 제외한 모든 마을을 순회
    dp[cur][state] = INF;
    for (int i = 0; i < n; i++) {
        // 길이 있으면서 방문한 적이 없는 경우
        if (mm[cur][i] != INF && (state & 1 << i) == 0) {
            int next = state | 1 << i;
            int temp = mm[cur][i] + tsp(i, next);
            dp[cur][state] = dp[cur][state] > temp ? temp : dp[cur][state];
        }
    }

    return dp[cur][state];
}