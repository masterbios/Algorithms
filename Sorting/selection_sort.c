/*input
5
5 2 3 6 1
*/

// time O(N^2)
// space complexity O(1)
// It never makes more than N swaps
// Inplace sorting because no extra memory is used

// choose the min element and replace it with its original position

/*-----------------------Selection Sort--------------------------*/

#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *a , int n){
	for(int i = 0; i < n - 1; i++){
		int min = i;
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j]){
				min = j;
			}
		}
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	selectionSort(a, n);
	for(int i = 0; i < n; i++){
		printf("%d ", *(a + i));
	}
	printf("\n");
	return 0;
}
