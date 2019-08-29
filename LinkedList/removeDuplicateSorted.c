#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node* next;
};

struct Node *head = NULL;

void removeDuplicatedFromSorted() {

	if (head == NULL || head->next == NULL) return;
	struct Node *cur = head, *forward = head->next;

	while(forward != NULL) {
		if (cur->val == forward->val) {
			forward = forward->next;
			cur->next = forward;
		} else {
			cur = cur->next;
			forward = forward->next;
		}

	}

}

void printLinkedList() {

	if (head == NULL) {
		printf("NULL\n");
		return;
	}

	struct Node *ptr = head;

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

	createLinkedList(1);
	createLinkedList(1);
	createLinkedList(1);
	createLinkedList(1);
	createLinkedList(1);
	createLinkedList(1);
	createLinkedList(1);
	createLinkedList(1);
	createLinkedList(1);
	createLinkedList(1);
	createLinkedList(2);
	createLinkedList(2);
	createLinkedList(2);
	createLinkedList(3);
	createLinkedList(3);
	createLinkedList(3);
	createLinkedList(4);
	createLinkedList(4);
	createLinkedList(5);
	createLinkedList(6);

	printLinkedList();
	removeDuplicatedFromSorted();
	printLinkedList();

	return 0;
}








