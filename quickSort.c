#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define N 10

int sort[N];

void QuickSort(int bottom, int top, int *data) {
	int i, lower, upper, div, temp;
	if(bottom >= top) {
		return;
	}
	/* 先頭の値を[適当な値]とする */
	div = data[bottom];
	for(lower = bottom, upper = top; lower < upper;) {
		while(lower <= upper && data[lower] <= div) {
			lower++;
		}
		while(lower <= upper && data[upper] > div) {
			upper--;
		}
		if(lower < upper) {
			printf("\nlowerIndex=%d", lower);
			printf("\nupperIndex=%d", upper);
			printf("\n入れ替え前: ");
			for(i = 0; i < N; i++) {
				printf("%d ", data[i]);
			}
			temp = data[lower];
			data[lower] = data[upper];
			data[upper] = temp;
			printf("\n入れ替え後: ");
			for(i = 0; i < N; i++) {
				printf("%d ", data[i]);
			}
		}
	}
	/* 最初に選択した値を中央に移動する */
	temp = data[bottom];
	data[bottom] = data[upper];
	data[upper] = temp;
	printf("\n最初に選択した値を中央に移動後:");
	for(i = 0; i < N; i++) {
		printf("%d ", data[i]);
	}

	QuickSort(bottom, upper - 1, data);
	QuickSort(upper + 1, top, data);
}

int main(void) {
	int i;
	srand((unsigned int)time(NULL));

	printf("ソート準備:\n");
	for(i = 0; i< N; i++) {
		/* 配列にランダムな値を格納 */
		sort[i] = rand() % 100;
		printf("%d ", sort[i]);
	}

	printf("\nソート開始:\n");
	QuickSort(0, N - 1, sort);

	printf("\nソート終了:\n");

	for(i = 0; i < N; i++) {
		printf("%d ", sort[i]);
	}

	return EXIT_SUCCESS;
}
