#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node* next;
};

struct Node *head = NULL;

// remove nth node from last in single pass
// we will assume n will always be valid

void removeNthnodefromlast(int n) {
    if (head == NULL || n == 0) return;

	struct Node *dummy = (struct Node *) malloc (sizeof(struct Node));
    dummy->val = 0;
    dummy->next = head;

    struct Node *first = dummy, *second = dummy;

    for (int i = 1; i <= n + 1; i++) second = second->next;

    while (second != NULL) {
        first = first->next;
        second = second->next;
    }

    first->next = first->next->next;
    head = dummy->next;

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
	createLinkedList(2);
	createLinkedList(3);
	createLinkedList(4);
	createLinkedList(5);
	printLinkedList();
	removeNthnodefromlast(5);
	printLinkedList();

	return 0;
}








