#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node* next;
};

struct Node *head = NULL;

struct Node* merge(struct Node *left, struct Node *right) {
	
	if (left == NULL) return right;
	if (right == NULL) return left;

	struct Node *ans = NULL;

	if (left->val <= right->val) {
		ans = left;
		ans->next = merge(left->next, right);
	} else {
		ans = right;
		ans->next = merge(left, right->next);
	}

	return ans;
}


struct Node* mergeSort(struct Node *ptr) {
	
	if (ptr == NULL || ptr->next == NULL) return ptr;

	struct Node *slow = ptr, *fast = ptr->next;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	struct Node *left = ptr, *right = slow->next;
	slow->next = NULL;

	left = mergeSort(left);
	right = mergeSort(right);

	struct Node *ans = merge(left, right);

	return ans;
}

void printLinkedList(struct Node *head1) {

	if (head1 == NULL) {
		printf("NULL\n");
		return;
	}

	struct Node *ptr = head1;

	while (ptr != NULL) {
		printf("%d->", ptr->val);
		ptr = ptr->next;
	}
	printf("NULL\n");

}

void createLinkedList(int data) {

	struct Node *temp = (struct Node*) malloc (sizeof(struct Node));
	
	// create new node of linkedlist
	struct Node *ptr = head;
	temp->val = data;
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
		return;
	}

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = temp;

}


int main(int argc, char const *argv[]) {
	
	createLinkedList(-2);
	createLinkedList(2);
	createLinkedList(-12);
	createLinkedList(21);
	createLinkedList(2);
	createLinkedList(1);
	
	printLinkedList(head);
	struct Node *ans = mergeSort(head);
	printLinkedList(ans);

	return 0;
}
