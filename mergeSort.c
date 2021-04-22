#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];
int buffer[N];

void MergeSort(int n, int x[]) {
	int i, j, k, m;
	if(n <= 1) {
		printf("\nリターンしました");
		return;
	}
	m = n / 2;

	printf("\nnのサイズは%dです\n", n);
	printf("mのサイズは%dです\n", m);
	for(i = 0; i < N; i++) {
		printf("%d ", x[i]);
	}

	/* ブロックを前半と後半に分ける */
	MergeSort(m, x);
	MergeSort(n - m, x + m);

	printf("\nn=%dです。", n);
	printf("m=%d\n", m);

	/* 併合(マージ操作) */
	for(i = 0; i < m; i++) {
		buffer[i] = x[i];
	}
	j = m;
	i = k = 0;
	while(i < m && j < n) {
		if(buffer[i] <= x[j]) {
			x[k++] = buffer[i++];
		} else {
			x[k++] = x[j++];
		}
	}
	while(i < m) {
		x[k++] = buffer[i++];
	}
	
	printf("\nマージしました");
	for(i = 0; i < N; i++) {
		printf("%d ", x[i]);
	}
}

int main(void) {
	int i;

	srand((unsigned int)time(NULL));

	printf("ソート準備:\n");
	for(i = 0; i < N; i++) {
		/* 配列にランダムな値を格納 */
		sort[i] = rand();
		printf("%d ", sort[i]);
	}

	printf("\nソート開始:\n");
	MergeSort(N, sort);

	printf("\nソート終了:\n");

	for(i = 0; i < N; i++) {
		printf("%d ", sort[i]);
	}

	return EXIT_SUCCESS;
}
