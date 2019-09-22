import java.util.Stack;

public class IterativeInorderTraversal {
    public static void main(String[] args) {
        node root = new node(1); 
        root.left = new node(2); 
        root.right = new node(3); 
        root.left.left = new node(4); 
        root.left.right = new node(5); 
        root.right.left = new node(6); 
        root.right.right = new node(7); 
  
        inorderIterative(root); 
  
    }

    public static void inorderIterative(node root) {
        if (root == null) System.out.println("null");
        Stack<node> s1 = new Stack<>();
        node cur = root;
        while(!s1.isEmpty() || cur != null) {
            while (cur != null) {
                s1.push(cur);
                cur = cur.left;
            }
            cur = s1.pop();
            System.out.print(cur.val + " ");
            cur = cur.right;
        }
        System.out.println();
    }

    static class node {
        int val;
        node right, left;
        public node (int val) { this.val = val;}
    }

}