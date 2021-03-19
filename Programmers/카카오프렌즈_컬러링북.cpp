/*
사이트: 프로그래머스, 2017 카카오코드 예선, 카카오프렌즈 컬리링북
분류: Depth First Search(DFS)
코멘트
자주 볼 수 있는 dfs 문제였다.
*/

#include <vector>
#include <cstring>

using namespace std;

const int SIZE = 100;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
int visited[SIZE][SIZE];

int dfs(int m, int n, int x, int y, vector<vector<int>> mm, int item){
    int count = 0;
    
    if (0 > x || n <= x || 0 > y || m <= y){
        return 0;
    }
    
    if (mm[y][x] == item && visited[y][x] == 0){
        visited[y][x] = 1;
        count = 1;
    } else{
        return 0;
    }

    for(int i = 0; i < 4; ++i){
        int goX = x + dx[i];
        int goY = y + dy[i];
        count += dfs(m, n, goX, goY, mm, item);
    }
    
    return count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if (picture[i][j] && visited[i][j] == 0){
                ++number_of_area;
                int result = dfs(m, n, j, i, picture, picture[i][j]);
                
                max_size_of_one_area = max_size_of_one_area > result ? max_size_of_one_area : result;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}