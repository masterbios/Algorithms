#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node* next;
};

struct Node *head1 = NULL, *head2;

void addTwoNumbersAsLists(int carry) {
	
}


void printLinkedList() {

	if (head == NULL) {
		printf("NULL\n");
		return;
	}

	struct Node *ptr = head;

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

	printLinkedList();
	addTwoNumbersAsLists(0);
	printLinkedList();

	return 0;
}








