#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node* next;
};

struct Node *head = NULL;

int length() {
	int len = 0;
	struct Node *ptr = head;
	while (ptr != NULL) {
		ptr = ptr->next;
		len++;
	}
	return len;
}

void removeNnodefromlist(int n) {

	if (head == NULL || (head->next == NULL && n == 1)) return ;

	int len = length();

	if (n > len || len - n == 0) head = head->next;

	int go = 1;
	struct Node *ptr = head;

	while (ptr != NULL && go < len - n) {
		ptr = ptr->next;
		go++;
	}

	ptr->next = ptr->next->next;

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
	createLinkedList(6);

	printLinkedList();
	// removeNnodefromlist(1);
	// printLinkedList();
	// removeNnodefromlist(4);
	// printLinkedList();
	removeNnodefromlist(6);
	printLinkedList();

	return 0;
}








