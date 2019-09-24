
public class LowestCommonAncestor {
	
	static boolean foundp = false;
	static boolean foundq = false;

	public static void main(String[] args) {
		TreeNode root = new TreeNode(1);

		TreeNode a1 = new TreeNode(2);
		TreeNode a2 = new TreeNode(3);
		
		TreeNode b1 = new TreeNode(4);
		TreeNode b2 = new TreeNode(5);
		TreeNode b3 = new TreeNode(6);
		TreeNode b4 = new TreeNode(7);

		root.left = a1;
		root.right = a2;

		a1.left = b1;
		a1.right = b2;
		a2.left = b3;
		a2.right = b4;

		// uncomment only one check condition at a time

		// b2.left = c1;
		// b2.right = c2;
		// TreeNode y1 = lowestCommonAncestor(root, b1, b2);
		// TreeNode y2 = lowestCommonAncestor(root, b1, b3);
		// TreeNode y3 = lowestCommonAncestor(root, b1, a2);
		// TreeNode y4 = lowestCommonAncestor(root, a1, b1);
		TreeNode y5 = lowestCommonAncestor(root, new TreeNode(10), root);
		
		// if (foundp && foundq) {
		// 	System.out.println(y1.val);
		// } else {
		// 	System.out.println("LCA not present");
		// } 
		// if (foundp && foundq) {
		// 	System.out.println(y2.val);
		// } else {
		// 	System.out.println("LCA not present");
		// } 
		// if (foundp && foundq) {
		// 	System.out.println(y3.val);
		// } else {
		// 	System.out.println("LCA not present");
		// } 
		// if (foundp && foundq) {
		// 	System.out.println(y4.val);
		// } else {
		// 	System.out.println("LCA not present");
		// } 
		if (foundp && foundq) {
			System.out.println(y5.val);
		} else {
			System.out.println("LCA not present");
		} 
		
	}

	public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    	if (root == null || p == null || q == null) return null;
    	TreeNode ans = findlowestCommonAncestor(root, p, q);
		return ans;
    }

    public static TreeNode findlowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    	if (root == null || p == null || q == null) return null;

		if (root == p) {
			foundp = true;
			return root;
		}
		if (root == q) {
			foundq = true;
			return root;
		}

		TreeNode searchLeft = lowestCommonAncestor(root.left, p, q);
		TreeNode searchRight = lowestCommonAncestor(root.right, p, q);
		
		if (searchLeft != null && searchRight != null) return root;

		return (searchLeft != null ? searchLeft : searchRight);
    }

    static class TreeNode {
    	int val;
     	TreeNode left;
      	TreeNode right;
      	TreeNode(int val) { 
      		this.val = val; 
      	}
    }

}