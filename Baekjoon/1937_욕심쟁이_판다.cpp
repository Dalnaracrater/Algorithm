/*
사이트: 백준, 1937번
분류: Dynamic Programming(DP), Depth First Search(DFS)
*/

#include <iostream>
#include <cstdio>

const int SIZE = 500;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

using namespace std;

int n;
int forest[SIZE][SIZE];
int dp[SIZE][SIZE];

int dfs(int x, int y){
    // 방문한 지역이면 그 값을 반환, 아니라면 1로 초기화
    if (dp[x][y] == 0) {
        dp[x][y] = 1;
    } else{
        return dp[x][y];
    }
    
    int max = 1;
    for(int i = 0; i < 4; ++i) {
        
        int a = x + dx[i];
        int b = y + dy[i];
        
        if (0 <= a && a < SIZE && 0 <= b && b < SIZE) {
            // 
            if (forest[x][y] < forest[a][b]){
                int temp = dfs(a, b) + 1;
                max = max > temp ? max : temp;
            }
        }
    }
    
    return dp[x][y] = max;
}

int main(void)
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &forest[i][j]);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int temp = dfs(i, j);
            
            ans = ans > temp ? ans : temp;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
