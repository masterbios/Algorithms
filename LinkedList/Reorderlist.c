#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node* next;
};

struct Node *head = NULL;

struct Node* reverse (struct Node **ptr) {

	struct Node *prev = NULL, *cur = *ptr, *next = NULL;
	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

struct Node* reorderList() {

	if (head == NULL || 
		head->next == NULL || 
		head->next->next == NULL) return head;

	struct Node *slow = head, *fast = head->next;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	struct Node *head1 = head;
	struct Node *head2 = reverse(&slow->next);
	slow->next = NULL;

	struct Node *ans = (struct Node *) malloc (sizeof(struct Node));
	struct Node *cur = ans;

	while (head1 != NULL || head2 != NULL) {
		if (head1 != NULL) {
			cur->next = head1;
			head1 = head1->next;
			cur = cur->next;
		}	
		if (head2 != NULL) {
			cur->next = head2;
			head2 = head2->next;
			cur = cur->next;
		}
	}

	return ans->next;

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

	createLinkedList(1);
	createLinkedList(2);
	createLinkedList(3);
	createLinkedList(4);
	createLinkedList(5);
	createLinkedList(6);
	createLinkedList(7);


	printLinkedList(head);
	struct Node *ans = reorderList();
	printLinkedList(ans);

	return 0;
}








