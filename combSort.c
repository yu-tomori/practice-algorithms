#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];

void CombSort(void) {
	int i, temp, flag, gap;
	gap = N;
	do {
		gap = (gap * 10) / 13;
		/* 収縮率は1.3 */
		if(gap == 0) {
			gap = 1;
		}

		flag = 1;
		/* 先頭から順に見ていって */
		for(i = 0; i < N - gap; i++) {
			/* 距離がgapだけ離れてた要素を比較し、並びがおかしければ */
			if (sort[i] > sort[i+gap]) {
				/* 入れ替える */
				flag = 0;
				temp = sort[i];
				sort[i] = sort[i+gap];
				sort[i+gap] = temp;
			}
		}
	/* 一度も並べ替えをせずに、gap=1で見終わったら終了 */
	} while((gap > 1) || flag != 1);
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
	CombSort();

	printf("\nソート終了:\n");

	for(i = 0; i < N; i++) {
		printf("%d ", sort[i]);
	}

	return EXIT_SUCCESS;
}
