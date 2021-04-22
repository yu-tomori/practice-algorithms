#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int n[MAX];

void mergeSort(int*, int, int);

int main() {
  int argNum;
  scanf("%d ", &argNum);

  for (int i = 0; i < argNum; i++) {
    scanf("%d", &n[i]);
  }
  mergeSort(n, 0,argNum - 1);

  for (int i = 0; i < argNum; i++) {
    fprintf(stdout ,"%d ", n[i]);
  }
}

void mergeSort(int *n, int start, int end) {
  /* printf("input before processing: ");
   * arrayPrinter(&n[start], end - start + 1);
   */

  if (start == end) {
    return;
  }
  if (end - start == 1) {
    if (n[end] < n[start]) {
      int temp = n[start];
      n[start] = n[end]; n[end] = temp;
    } else {
      return;
    }
  }

  int divider = (end + start) / 2;
  mergeSort(n, start, divider);
  mergeSort(n, divider+1, end);

  int leftLen = divider - start + 1; int *left = calloc(leftLen,sizeof(int));
  for (int i = 0; i < leftLen; i++) {
    left[i] = n[start + i];
  }

  int rightLen = end - (divider+1) + 1; int *right = calloc(rightLen, sizeof(int));
  for (int i = 0; i < rightLen; i++) {
    right[i] = n[(divider+1) + i];
  }

  int l = 0,r = 0;
  for (int i = 0; i < end - start + 1; i++) {
    if (leftLen <= l) {
      n[start + i] = right[r++];
      continue;
    }
    if (rightLen <= r) {
      n[start + i] = left[l++];
      continue;
    }

    if (left[l] > right[r]) {
      n[start + i] = right[r++];
    } else {
      n[start + i] = left[l++];
    }
  }
  return;
}
