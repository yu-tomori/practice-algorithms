#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];

int compare(const void *args1, const void *args2) {
	return(*((int *)args1) - *((int *)args2));
}

int main(void) {
	int i;

	srand((unsigned int)time(NULL));

	printf("ソート準備:\n");
	for(i = 0; i < N; i++){
		/* 配列をランダムに初期化する */
		sort[i] = rand();
		printf("%d ", sort[i]);
	}

	printf("\nソート開始:\n");
	qsort(sort, N, sizeof(sort[0]), compare);

	printf("\nソート終了:\n");

	for(i = 0; i < N; i++){
		printf("%d ", sort[i]);
	}

	return EXIT_SUCCESS;
}
