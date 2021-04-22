#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 /* データの件数 */
int sort[N];

void BubbleSort(void) {
	int i, j, flag;

	do {
		flag = 0;
		for(i = 0; i < N - 1; i++) {
			if(sort[i] > sort[i+1]){
				/* 左右の並びがおかしければ並び変える */
				flag = 1;
				j = sort[i];
				sort[i] = sort[i + 1];
				sort[i + 1] = j;
			}
		}
		/* 一度も並び変えずに見終わったら終了 */
	} while(flag == 1);
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
	BubbleSort();

	printf("\nソート終了:\n");

	for(i = 0; i < N; i++) {
		printf("%d ", sort[i]);
	}

	return EXIT_SUCCESS;
}
