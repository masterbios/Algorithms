import java.util.Stack;

public class IterativePostOrderTraversal {
    public static void main(String[] args) {
        node root = new node(1); 
        root.left = new node(2); 
        root.right = new node(3); 
        root.left.left = new node(4); 
        root.left.right = new node(5); 
        root.right.left = new node(6); 
        root.right.right = new node(7); 
  
        postOrderIterative(root); 
  
    }

    public static void postOrderIterative(node root) {
        if (root == null) System.out.println("null");
        Stack<node> s1 = new Stack<>();
        Stack<node> s2 = new Stack<>();
        s1.push(root);
        while(!s1.isEmpty()) {
            node cur = s1.pop();
            s2.push(cur);
            if (cur.left != null) s1.push(cur.left);
            if (cur.right != null) s1.push(cur.right);
        }
        while(!s2.isEmpty()) {
            System.out.print(s2.pop().val + " ");
        }
        System.out.println();

    }

    static class node {
        int val;
        node right, left;
        public node (int val) { this.val = val;}
    }

}