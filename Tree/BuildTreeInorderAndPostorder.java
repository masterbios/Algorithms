import java.util.Map;
import java.util.HashMap;

public class BuildTreeInorderAndPostorder {

    public static void main(String[] args) {
        int inorder[] = {9, 3, 15, 20, 7};
        int postorder[] = {9, 15, 7, 20, 3};
        TreeNode root = buildTree(inorder, postorder);
        inorderTraversal(root);
        System.out.println();
    }

    static Map<Integer, Integer> map = new HashMap<>();
    static int idx = 0;
    
    public static TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        idx = n - 1;
        for (int i = 0; i < n; i++) map.put(inorder[i], i);
        return buildTree(inorder, postorder, 0, n - 1);
    }
    
    public static TreeNode buildTree(int inorder[], int postorder[], int start, int end) {
        if (start > end) return null;
        int node = postorder[idx--];
        TreeNode temp = new TreeNode(node);
        if (start == end) return temp;
        int newidx = map.get(node);
        temp.right = buildTree(inorder, postorder, newidx + 1, end);
        temp.left = buildTree(inorder, postorder, start, newidx - 1);
        return temp;
    }
    public static void inorderTraversal(TreeNode root) {
        if (root == null) return;
        inorderTraversal(root.left);
        System.out.print(root.val + " ");
        inorderTraversal(root.right);
    }

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        public TreeNode(int val) { this.val = val; }
    }
}
