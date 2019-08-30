/*input
93 12 22 27 29 38 41 45 75 75 87 99 109 113 142 177 188 191 204 205 228 271 284 286 291 300 308 310 326 327 337 352 364 372 382 384 389 405 427 465 483 496 505 508 508 515 519 524 532 536 555 561 588 588 626 635 662 671 671 674 692 696 698 706 717 732 741 744 753 759 779 786 792 804 811 819 821 835 848 860 860 864 864 868 872 874 880 909 913 915 929 929 958 990
61 7 12 46 66 84 86 93 116 131 132 179 222 230 238 246 253 254 256 290 301 357 372 375 391 395 396 402 424 439 494 508 535 554 592 593 612 629 711 719 721 731 738 746 758 768 769 780 782 831 835 837 873 874 882 907 936 960 970 982 987 990

23 26 33 64 73 101 237 277 321 333 358 383 465 482 488 614 708 713 731 732 805 856 859 967
97 21 23 26 27 47 54 57 57 69 72 92 93 100 103 114 119 164 174 177 184 211 228 246 251 262 276 280 293 305 309 336 357 358 367 375 396 410 412 428 441 463 487 488 490 495 512 514 523 530 539 542 549 566 572 578 586 591 597 605 639 644 655 655 683 692 695 705 710 724 726 732 735 748 750 756 783 787 787 793 798 813 820 822 834 835 845 858 882 886 891 892 910 910 927 954 959 967
*/
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node* next;
};

struct Node *head1 = NULL, *head2 = NULL;

struct Node* mergeSortedList(struct Node *ptr1, struct Node *ptr2) {
	
	struct Node *res = NULL;
	if (ptr1 == NULL) return ptr2;
	if (ptr2 == NULL) return ptr1;

	if (ptr1->val <= ptr2->val) {
		res = ptr1;
		res->next = mergeSortedList(ptr1->next, ptr2);
	} else {
		res = ptr2;
		res->next = mergeSortedList(ptr1, ptr2->next);
	}
	return res;
}

void printLinkedList(struct Node *head) {

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

void createLinkedList(int data, struct Node **head) {

	struct Node *temp = (struct Node*) malloc (sizeof(struct Node));
	
	// create new node of linkedlist
	struct Node *ptr = *head;
	temp->val = data;
	temp->next = NULL;

	if (*head == NULL) {
		*head = temp;
		return;
	}

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = temp;

}


int main(int argc, char const *argv[]) {

	int n, m, *a, *b;

	scanf("%d", &n);
	a = (int *) malloc (n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	scanf("%d", &m);
	b = (int *) malloc (m * sizeof(int));
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);

	for(int i = 0; i < n; i++) createLinkedList(a[i], &head1);
	for(int i = 0; i < m; i++) createLinkedList(b[i], &head2);

	// printLinkedList(head1);

	// createLinkedList(7, &head1);
	// createLinkedList(12, &head1);
	// createLinkedList(22, &head1);
	// createLinkedList(27, &head1);
	// createLinkedList(29, &head1);
	// createLinkedList(38, &head1);
	// createLinkedList(41, &head1);
	// createLinkedList(45, &head1);
	// createLinkedList(75, &head1);
	// createLinkedList(75, &head1);
	// createLinkedList(958, &head1);
	// createLinkedList(990, &head1);

	// createLinkedList(7, &head2);
	// createLinkedList(12, &head2);
	// createLinkedList(46, &head2);
	// createLinkedList(66, &head2);
	// createLinkedList(84, &head2);
	// createLinkedList(86, &head2);
	// createLinkedList(960, &head2);
	// createLinkedList(970, &head2);
	// createLinkedList(987, &head2);
	// createLinkedList(990, &head2);

	struct Node *ans = mergeSortedList(head1, head2);

	printLinkedList(ans);

	return 0;
}








