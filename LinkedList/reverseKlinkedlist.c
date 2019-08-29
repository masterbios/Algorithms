#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node* next;
};

struct Node *head = NULL;

struct Node* reverseKlinkedlist(struct Node *ptr, int n) {
	struct Node *prev = NULL, *cur = ptr, *next = NULL;
	int count = 0;
	while (cur != NULL && count < n) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		count++;
	}

	if (next != NULL) ptr->next = reverseKlinkedlist(next, n);

	return prev;
}

void printLinkedList(struct Node *head1) {

	if (head1 == NULL) {
		printf("NULL\n");
		return;
	}

	struct Node *ptr = head1;

	while (ptr != NULL) {
		printf("%d->", ptr-> val);
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

	createLinkedList(1);
	createLinkedList(2);
	createLinkedList(3);
	createLinkedList(4);
	createLinkedList(5);
	createLinkedList(6);
	createLinkedList(7);
	createLinkedList(8);
	createLinkedList(9);
	createLinkedList(10);
	createLinkedList(11);



	printLinkedList(head);
	struct Node *ptr = head;
	struct Node *ans = reverseKlinkedlist(ptr, 3);
	printLinkedList(ans);

	return 0;
}








