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

struct Node* reverse(struct Node *head1) {

	struct Node *cur = head1, *prev = NULL, *next = NULL;

	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;

}

// Iterative method
void reverseRange(int m, int n) {

	if (head == NULL) return;

	int len = length();

	if (m > n || n > len || m == n) return;

	int go = 1;
	struct Node *chead = NULL, *ctail = NULL, *start = NULL, *end = NULL, *ptr = head;

	while (ptr != NULL && go <= n) {
		if (go < m) chead = ptr;
		if (go == m) start = ptr;
		if (go == n) {
			end = ptr;
			ctail = ptr->next;
		}
		ptr = ptr->next;
		go++;
	}
	end->next = NULL;

	end = reverse(start);

	if (chead == NULL) head = end;
	else chead->next = end;

	start->next = ctail;

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
	reverseRange(4, 6);
	printLinkedList();

	return 0;
}
