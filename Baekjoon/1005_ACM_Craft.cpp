/*
사이트: 백준, 1005번
분류: Dynamic Programming(DP), Depth First Search(DFS)
코멘트
최대한 최적화를 해야 하는 문제였다. dfs 함수에 매개변수로 arr을 보내고 싶었는데 시간 초과가 발생하여 이런 부분을 모두 수정해야 했다. dp를 설계하는 건 꽤 쉬운 편이었으나, 백트래킹 방식과 유사하게 dfs를 구현하는 것이 좋았다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <deque>
#include <cstring>
#include <cstdio>

using namespace std;

const int SIZE = 1000;

int t, n, k;
int cost[SIZE + 1];
int dp[SIZE + 1];
//int arr[SIZE + 1][SIZE + 1]로 선언하면 메모리 초과가 발생한다.
deque<deque<int>> arr(SIZE + 1);

int dfs(int w) {
    int max = cost[w];

    for (int i = 0; i < arr[w].size(); ++i) {

        int from = arr[w][i];
        int result;

        // from의 건물 완성 최소 시간이 이미 구해진 경우 그 값을 사용한다. 아닐 경우 새로 dfs함수를 호출하여 구한다.
        if (dp[from] != -1) {
            result = dp[from] + cost[w];
        }
        else {
            result = dfs(from) + cost[w];
        }

        max = max > result ? max : result;
    }

    return dp[w] = max;
}

int main(void) {

    // cin조차 사용하지 못하였다. :(
    // cin.tie(0); cin >> t;
    scanf("%d", &t);

    while (t--) {

        scanf("%d %d", &n, &k);

        for (int i = 1; i <= n; ++i) {
            scanf("%d", &cost[i]);
        }
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= n; ++i) {
            arr[i].clear();
        }

        for (int i = 0; i < k; ++i) {
            int s, t;

            scanf("%d %d", &s, &t);
            arr[t].push_back(s);
        }

        int w;
        scanf("%d", &w);

        printf("%d\n", dfs(w));
    }

	return 0;
}