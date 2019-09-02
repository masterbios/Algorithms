#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node* next;
};

struct Node *head = NULL;

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

void Palindrome() {

	if (head == NULL || head->next == NULL) printf("Palindrome\n");

	struct Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    struct Node *ptr1 = head;
    struct Node *ptr2 = reverse(slow->next);
    slow->next = NULL;
    
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->val != ptr2->val) {
        	printf("Not a Palindrome\n");
        	return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    printf("Palindrome\n");;

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
	createLinkedList(3);
	createLinkedList(2);
	createLinkedList(1);

	printLinkedList();
	Palindrome();
	// printLinkedList();

	return 0;
}
