import java.util.Map;
import java.util.HashMap;

class LRU {

	Map<Integer, ListNode> map;
	ListNode head;
	ListNode tail;
	int maxCapacity;
	int totalItems;

	public LRU(int maxCapacity) {
		this.maxCapacity = maxCapacity;
		totalItems = 0;
		head = new ListNode(-1, -1);
		tail = new ListNode(-1, -1);
		head.next = tail;
		tail.prev = head;
		map = new HashMap<>();
	}

	public int get(int key) {
		ListNode find = map.get(key);
		if (find == null) {
			return -1;
		}
		moveToHead(find);
		return find.value;
	}

	public void put(int key, int value) {
		ListNode node = map.get(key);
		if (node == null) {
			ListNode newnode = new ListNode(key, value);
			map.put(key, newnode);
			addToFront(newnode);
			totalItems++;
			if (totalItems > maxCapacity) {
				removeEntry();
			}
		} else {
			moveToHead(node);
		}
	}

	public ListNode popTail() {
		removeFromList(tail.prev);
		return tail.prev;
	}

	public boolean addToFront(ListNode node) {
		node.prev = head;
		node.next = head.next;
		head.next.prev = node;
		head.next = node;
		return true;
	}

	public boolean moveToHead(ListNode node) {
		removeFromList(node);
		addToFront(node);
		return true;
	}

	public boolean removeFromList(ListNode node) {
		ListNode pprev = node.prev, pnext = node.next;
		pprev.next = pnext;
		pnext.prev = pprev;
		return true;
	}

	public boolean removeEntry() {
		ListNode cur = popTail();
		map.remove(cur.key);
		totalItems--;
		return true;
	}

	static class ListNode {
		
		int key;
		int value;
		ListNode prev;
		ListNode next;

		public ListNode(int key, int value) {
			this.key = key;
			this.value = value;
			prev = next = null;
		}
	}

}