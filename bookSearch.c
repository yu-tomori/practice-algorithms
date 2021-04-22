#include <stdio.h>
#include <stdlib.h>

#define N 5

/* 蔵書を表すデータ */
typedef struct {
	char *title;
	char *author;
	int bookID;
	int available;
} book;

book *bookarray[N]; /* 蔵書データのポインタの配列 */

/* 蔵書のデータを初期化する */
void initdata(void) {
	int n;
	for(n = 0; n < N; n++) {
		bookarray[n] = (book*)malloc(sizeof(book));
	}

	bookarray[0]->title = "book0";
	bookarray[1]->title = "book1";
	bookarray[2]->title = "book2";
	bookarray[3]->title = "book3";
	bookarray[4]->title = "book4";
	bookarray[0]->author = "author0";
	bookarray[1]->author = "author1";
	bookarray[2]->author = "author2";
	bookarray[3]->author = "author3";
	bookarray[4]->author = "author4";
	bookarray[0]->bookID = 1000;
	bookarray[1]->bookID = 130;
	bookarray[2]->bookID = 23;
	bookarray[3]->bookID = 3394;
	bookarray[4]->bookID = 43;
	bookarray[0]->available = 1;
	bookarray[1]->available = 0;
	bookarray[2]->available = 0;
	bookarray[3]->available = 1;
	bookarray[4]->available = 1;
}

/* 蔵書データのメモリを解放 */
void cleanupdata(void) {
	int n;
	for(n = 0; n < N; n++) {
		free(bookarray[n]);
	}
}

/* 本のデータをbookIDの順に昇順でクイックソートする */
void sortbook(int bottom, int top) {
	int lower, upper, div, i;
	book *temp;

	if(bottom >= top) {
		printf("\n return because bottom >= top: bottom=%d, top=%d", bottom, top);
		return;
	}

	div = bookarray[bottom]->bookID; /* 適当な基準値を選択 */
	for(lower = bottom, upper = top; lower < upper;) {
		while(lower < upper && bookarray[lower]->bookID < div) {
			lower++;
		}
		while(lower < upper && bookarray[upper]->bookID > div) {
		
			upper--;
		}
		if(lower < upper) {
			/* データ(へのポインタ)の順番を入れ替える */
			temp = bookarray[lower];
			bookarray[lower] = bookarray[upper];
			bookarray[upper] = temp;

			printf("\n------------(bottom=%d, top=%d ,lower=%d, upper=%d)", bottom, top, lower, upper);
			printf("\nforの入れ替え後:");
			for(i = 0; i < N; i++) {
				printf(" %d ", bookarray[i]->bookID);
			}
			printf("\n--------------------------------------------------");

			lower++;
			upper--;
		} else {
			printf("\nnot lower < upper : lower=%d, upper=%d", lower, upper);
		}
	}

	printf("\n------------------------------(bottom=%d, top=%d, lower=%d, upper=%d )", bottom, top, lower, upper);
	printf("\nsortbookの入れ替え後:");
	for(i = 0; i < N; i++) {
		printf(" %d ", bookarray[i]->bookID);
	}
	printf("\n---------------------------------------------------------------------");

	sortbook(bottom, upper);
	printf("\n   sortbook(upper, top): upper=%d, top=%d", upper, top);
	sortbook(upper + 1 , top);
}

/* booksのなかからbookIDがkeyと一致するデータをバイナリーサーチで検索して、その添字を返す。見つからなければ-1を返す */
int searchbook(book *books[], int size, int key) {
	int left, mid, right;

	left = 0;
	right = size;
	while(left < right) {
		mid = (left + right) / 2;
		if(books[mid]->bookID < key) {
			/* bookIDの大小を比較 */
			left = mid + 1;
		} else {
			right = mid;
		}
		if(books[left]->bookID == key) {
			return left;
		}

	}
	return -1; /* 見つからなかった場合 */
}

int main(void) {
	int i, key, position;

	initdata();
	sortbook(0, N - 1); /* 最初にソートしておく */
	printf("\nソート後のid順");
	for(i = 0; i < N; i++) {
		printf("%d ", bookarray[i]->bookID);
	}

	/* 検索キーとしてほんの管理番号を入力 */
	while(1) {
		printf("\n検索する本の管理番号を入力してください(0で終了):");
		scanf("%d", &key);
		if(key == 0) {
			break; /* 0が入力されたら終了 */
		}

		/* 検索して結果を表示 */
		position = searchbook(bookarray, N - 1, key);
		if(position != -1) {
			printf("--次の本が見つかりました--\n[タイトル]%s \n[著者]%s \n[管理番号]%d \n",
				bookarray[position]->title,
				bookarray[position]->author,
				bookarray[position]->bookID
			);
			if(bookarray[position]->available != 0) {
				puts("この本は貸出可能です\n");
			} else {
				puts("この本は貸出中です\n");
			}
		} else {
			puts("お探しの本は見つかりませんでした\n");
		}
	}
	
	cleanupdata();
	return 0;
}
