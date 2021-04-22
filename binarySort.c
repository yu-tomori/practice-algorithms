#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];

void BinaryInsertSort(void) {
	int i, sorted, temp, insert;
	int left, mid, right; /* バイナリーサーチ用の追加変数 */

	/* 最初から最後までソート済みになるまで繰り返す */
	for(sorted = 1; sorted < N; sorted++) {
		/* ソート済み領域の直後の値を取り出す */
		insert = sort[sorted];

		/* 挿入する場所を見つける(バイナリーサーチ) */
		left = 0;
		right = sorted;
		while(left < right) {
			mid = (left + right) / 2;

			if(sort[mid] < insert) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		i = left;

		/* ソート済み領域直後の値を挿入する */
		while(i <= sorted) {
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
	BinaryInsertSort();

	printf("\nソート開始:\n");

	for(i = 0; i < N; i++) {
		printf("%d ", sort[i]);
	}

	return EXIT_SUCCESS;
}
