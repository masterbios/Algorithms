/*input
11
11 10 9 8 7 6 5 4 3 2 2
*/

// Time complexity O(N + K) N=>input size K=>range of numbers
// Space complexity O(N + K)
// Fastest sorting when range of elements is small

// Create a range array and count occurence of each element
// Do presum of range array at each element
// create another array do 
// index = count[original_array[i]] - 1
// another array[index]

#include<stdio.h>
#include<stdlib.h>

#define MAX 1000001

int* countingSort(int *a, int n){
	
	int occur[MAX];
	static int *ans;
	ans = (int *) malloc (n * sizeof(int));

	for(int i = 0; i < MAX; i++) occur[i] = 0;
	for(int i = 0; i < n; i++) ans[i] = 0;
	for(int i = 0; i < n; i++) occur[a[i]]++;
	for(int i = 1; i < MAX; i++) occur[i] += occur[i - 1];
	for(int i = 0; i < n; i++){
		ans[occur[a[i]] - 1] = a[i];
		occur[a[i]]--;
	}
	return ans;

}

int main(){

	int n;
	scanf("%d", &n);
	int *a = (int *) malloc(n* sizeof(int));
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int *ptr = countingSort(a, n);
	for(int i = 0; i < n; i++){
		printf("%d ", *(ptr + i));
	} printf("\n");

	return 0;
}
