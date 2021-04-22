#include <stdio.h>
#include <stdlib.h>

/* リストの要素(ノード)を表す構造体 */
typedef struct tagListNode {
	struct tagListNode *prev;
	struct tagListNode *next;
	int data;
} ListNode;

int main(void) {
	int buf;
	ListNode *firstnode, *lastnode, *newnode, *thisnode, *removenode;

	firstnode = lastnode = NULL;

	do {
		printf("整数を入力してください(0を入力すると終了):");
		scanf("%d", &buf);
		if(buf) {
			/* 新たな入力があったら新しいノードを生成 */
			newnode = (ListNode*)malloc(sizeof(ListNode));
			newnode->data = buf;
			newnode->next = NULL;

			if(lastnode != NULL) {
				/* すでにあるノードに接続する */
				lastnode->next = newnode;
				newnode->prev = lastnode;
				lastnode = newnode;
			} else {
				/* これが最初のノードだった場合 */
				firstnode = lastnode = newnode;
				newnode->prev = NULL;
			}
		}
	} while(buf != 0);

	/* 検索値を入力 */
	do {
		printf("検索する値を入力してください:");
		scanf("%d", &buf);

		if(buf != 0) {
			/* 最初に入力した値のなかから検索し、見つかったら削除 */
			for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next) {
				if(thisnode->data==buf) {
					printf("入力された値の中に%dが見つかりました。ノードを削除します。\n", buf);
					if(thisnode->prev != NULL) {
						thisnode->prev->next = thisnode->next;
					} else {
						firstnode = thisnode->next;
					}

					if(thisnode->next != NULL) {
						thisnode->next->prev = thisnode->prev;
					}

					free(thisnode);
					break;
				}
			}
			if(thisnode == NULL) {
				printf("%dは入力されていないか、あるいはすでに削除されています。\n", buf);
			}
		}
	} while(buf != 0);

	/* 残ったノードを全て削除 */
	for(thisnode = firstnode; thisnode != NULL;) {
		removenode = thisnode;
		thisnode = thisnode->next;
		free(removenode);
	}

	return EXIT_SUCCESS;
}
