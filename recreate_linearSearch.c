#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOT_FOUND (-1)
#define N (10)

int search(int x, int *a, int num) {
	int n = 0, t;

	/* 最後の値をxに入れ替える */
	t = a[num - 1];
	a[num - 1] = x;

	/* 目的の値を探す */
	while(a[n] != x) {
		n++;
	}
	
	a[num - 1] = t; /* 配列最後の値を元に戻す */
	if(n < num - 1) {
		return n; /* 一番最後以外で一致 */
	}
	if(x == t) {
		return n; /* 一番最後が一致 */
	}

	return NOT_FOUND;
}

int main(void) {
	int i, r, array[N];

	srand((unsigned int)time(NULL));

	/* 適当な配列を作る */
	printf("array ");
	for(i = 0; i < N; i++) {
		printf("[%d]:%d ", i, array[i] = rand() % 20);
	}

	printf("\n何を探しますか:");
	scanf("%d", &i);

	r = search(i, array, N);
	if(r == NOT_FOUND) {
		printf("%dは見つかりません\n", i);
	} else {
		printf("%dは%d番目です\n", i, r);
	}

	return EXIT_SUCCESS;
}
