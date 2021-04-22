#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];

void InsertSort(void) {
	int i, sorted, temp, insert;

	/* 最初から最後までソート済みになるまで繰り返す */
	for(sorted = 0; sorted < N-1; sorted++) {
		/* ソート済み領域の値を取り出す */
		insert = sort[sorted + 1];

		/* 挿入する場所を見つける(リニアサーチ) */
		for(i = 0; i <= sorted; i++) {
			if(sort[i] > insert) {
				break;
			}
		}

		/* ソート済み領域後の値を挿入する */
		while(i <= sorted + 1) {
			temp = sort[i];
			sort[i] = insert;
			insert = temp;
			i++;
		}
	}
}

int main(void) {
	int i;

	srand((unsigned int)time(NULL));

	printf("ソート準備:\n");
	for(i = 0; i < N; i++) {
		/* 配列にランダムな値を格納 */
		sort[i] = rand() % 1000;
		printf("%d ", sort[i]);
	}

	printf("\nソート開始:\n");
	InsertSort();

	printf("\nソート終了:\n");

	for(i = 0; i < N; i++) {
		printf("%d ", sort[i]);
	}

	return EXIT_SUCCESS;
}
