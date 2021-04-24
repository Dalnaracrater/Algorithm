/*
사이트: SWEA, 10571번
분류: unknown
코멘트:
N/A
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define SIZE 100

int n, m;
int arr[SIZE][SIZE], rows[SIZE], cols[SIZE];

bool cut(int x, int y) {
    // 각 row, col의 최대값 중 작은 값이 arr[x][y] 보다 작은 경우,
    // 잔디 깎기 기계로는 만들어 낼 수 없는 패턴임을 의미함
	return (rows[x] > cols[y] ? cols[y] : rows[x]) > arr[x][y];
}

int main(void) {

	cin.tie(0);
	int N;
	cin >> N;

	for (int t = 1; t <= N; ++t) {
		cin >> n >> m;

		memset(rows, 0, sizeof(rows));
		memset(cols, 0, sizeof(cols));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> arr[i][j];

                // 각 row, col의 최대값 저장
				cols[j] = cols[j] < arr[i][j] ? arr[i][j] : cols[j];
				rows[i] = rows[i] < arr[i][j] ? arr[i][j] : rows[i];
			}
		}

		string ans = "YES";
		for (int i = 0; i < n; ++i) {
			int check = 0;
			for (int j = 0; j < m; ++j) {
				if (cut(i, j)) {
					ans = "NO";
					check = 1;
					break;
				}
			}
			if (check) {
				break;
			}
		}

		cout << "#" << t << " " << ans << endl;
	}

	return 0;
}