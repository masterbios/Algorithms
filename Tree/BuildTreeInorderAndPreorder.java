import java.util.Map;
import java.util.HashMap;

public class BuildTreeInorderAndPreorder {
    
    public static void main(String[] args) {
        int preorder[] = {9, 3, 15, 20, 7};
        int inorder[] = {3, 9, 20, 15, 7};
        TreeNode root = buildTree(preorder, inorder);
        inorderTraversal(root);
        System.out.println();
    }

    static Map<Integer, Integer> map = new HashMap<>();
    static int idx = 0;

    public static TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = inorder.length;
        for (int i = 0; i < n; i++) map.put(inorder[i], i);
        return buildTree(preorder, inorder, 0, n - 1);
    }
    
    public static TreeNode buildTree(int pre[], int in[], int start, int end) {
        if (start > end) return null;
        int node = pre[idx++];
        TreeNode temp = new TreeNode(node);
        if (start == end) return temp;
        int newidx = map.get(node);
        temp.left = buildTree(pre, in, start, newidx - 1);
        temp.right = buildTree(pre, in, newidx + 1, end);
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