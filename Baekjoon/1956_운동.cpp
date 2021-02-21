/*
사이트: 백준, 1956번
분류: Floyd-warshall, graph
*/

#include <iostream>
#include <cstdio>

#define INF 10e6

int main(void) {

	int v, e;

	scanf("%d %d", &v, &e);

    // row, col에 1씩 더미 공간을 추가시켜 input 값을 따로 처리하지 않도록 함
	int r[401][401] = { 0, };

	for (int i = 0; i <= v; i++) {
		for (int j = 0; j <= v; j++) {
			r[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		r[a][b] = c;
	}

    // Floyd-Warshall algorithm
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (r[i][j] > r[i][k] + r[k][j]) {
					r[i][j] = r[i][k] + r[k][j];
				}
			}
		}
	}

    // i -> j -> i cycle의 최소값 탐색
	int min = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i != j) {
				min = min > r[i][j] + r[j][i] ? r[i][j] + r[j][i] : min;
			}
		}
	}

	if (min == INF)
		std::cout << "-1";
	else
		std::cout << min;

	return 0;
}