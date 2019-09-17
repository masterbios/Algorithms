/*input
11
10 6 5 4 3 2 -2 -9 8 7 11
*/

// Time complexity O(NlogN) N=>input size
// Space complexity O(N)

// Split array recursively and sort those splitted array and merge that spillited array
// Stable Sorting 

#include<stdio.h>
#include<stdlib.h>

void mergeArray(int *left, int *right, int *a, int nl, int nr, int na) {
	int k = 0, i = 0, j = 0;
	while (i < nl && j < nr) {
		if (left[i] <= right[j]) a[k++] = left[i++];
		else a[k++] = right[j++];
	}
	while (i < nl) a[k++] = left[i++];
	while (j < nr) a[k++] = right[j++];
} 

void mergeSort(int *a, int n){
	if (n < 2) return;
	int mid = n / 2, k = 0;
	int *left = (int *) malloc (mid * sizeof(int));
	int *right = (int *) malloc ((n - mid) * sizeof(int));
	for (int i = 0; i < mid; i++) left[i] = a[k++];
	for (int i = 0; i < (n - mid); i++) right[i] = a[k++];
	mergeSort(left, mid);
	mergeSort(right, n - mid);
	mergeArray(left, right, a, mid, n - mid, n);
	free(left);
	free(right);
}

int main(){

	int n = 0;
	scanf("%d", &n);
	int *a = (int *) malloc(n* sizeof(int));
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	mergeSort(a, n);
	for (int i = 0; i < n; i++){
		printf("%d ", *(a + i));
	} printf("\n");

	return 0;
}
