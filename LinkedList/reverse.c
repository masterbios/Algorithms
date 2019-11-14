#include<stdio.h>
#include<stdlib.h>

/*
	Time Complexity : O(N)
	Space Complexity : O(1)
*/

struct Node {
	int val;
	struct Node* next;
};

struct Node *head = NULL;

// Iterative method
void reverseLinkedList() {

	struct Node *cur = head, *prev = NULL, *next = NULL;

	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	head = prev;

}

// Recursive method 
void ReverseLinkedList(struct Node *prev) {

	if (prev->next == NULL) {
		head = prev;
		return;
	}

	ReverseLinkedList(prev->next);

	struct Node *p = prev->next;
	p->next = prev;
	prev->next = NULL;

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

	// iterative
	reverseLinkedList();
	printLinkedList();

	// recursive 
	ReverseLinkedList(head);
	printLinkedList();

	return 0;
}


public static void bfs(int n,int m,int num) 
    { 
        Queue<Integer> q = new LinkedList<Integer> (); 
  
        q.add(num); 
  
        while (!q.isEmpty()) 
        { 
            int stepNum = q.poll(); 
            if (stepNum <= m && stepNum >= n) 
            { 
                System.out.print(stepNum + " "); 
            } 
            if (stepNum == 0 || stepNum > m) 
                continue; 
            int lastDigit = stepNum % 10; 
            int stepNumA = stepNum * 10 + (lastDigit- 1); 
            int stepNumB = stepNum * 10 + (lastDigit + 1); 
            if (lastDigit == 0) 
                q.add(stepNumB); 
            else if (lastDigit == 9) 
                q.add(stepNumA); 
  
            else
            { 
                q.add(stepNumA); 
                q.add(stepNumB); 
            } 
        } 
    } 
    public static void displaySteppingNumbers(int n,int m) 
    { 
        for (int i = 0 ; i <= 9 ; i++) 
            bfs(n, m, i); 
    } 





