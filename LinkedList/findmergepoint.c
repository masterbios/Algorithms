#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node *next;
};

int length(struct Node *node) { 

	int len = 0;

	while (node != NULL) {
		len++;
		node = node->next;
	}

	return len;

}

int findMergePoint(struct Node *A, struct Node *B) {

	if (A == NULL || B == NULL) return -1;

	int a = length(A);
	int b = length(B);

	if (a < b) {
		struct Node *temp = A;
		A = B;
		B = temp;
	}

	int d = a - b;

	for (int i = 0; i < d; i++) {
		A = A->next;
	}

	while (A != NULL && B != NULL) {
		if (A == B) return A->val;
		A = A->next;
		B = B->next;
	}

	return -1;

}

int main(int argc, char const *argv[]) {

	struct Node *A = NULL, *B = NULL;

	struct Node *temp1 = (struct Node *) malloc (sizeof(struct Node));
	struct Node *temp2 = (struct Node *) malloc (sizeof(struct Node));
	struct Node *temp3 = (struct Node *) malloc (sizeof(struct Node));
	struct Node *temp4 = (struct Node *) malloc (sizeof(struct Node));
	struct Node *temp5 = (struct Node *) malloc (sizeof(struct Node));

	temp1->val = 1; temp1->next = NULL;
	temp2->val = 2;	temp2->next = NULL;
	temp3->val = 3;	temp3->next = NULL;
	temp4->val = 9;	temp4->next = NULL;
	temp5->val = 5;	temp5->next = NULL;


 	temp1->next = temp2;
 	temp2->next = temp3;
 	temp3->next = temp4;
 	temp4->next = temp5;
 	temp5->next = NULL;

 	A = temp1;

	struct Node *temp6 = (struct Node *) malloc (sizeof(struct Node));
	struct Node *temp7 = (struct Node *) malloc (sizeof(struct Node));

	temp6->val = 6; temp6->next = NULL;
	temp7->val = 7;	temp7->next = NULL;

 	temp6->next = temp7;
 	temp7->next = temp4; 
 	// temp7->next = NULL;

 	B = temp6;

 	// -1 means no intersection point
	printf("%d\n", findMergePoint(A, B));

	return 0;
}

