import java.util.Arrays;
import java.util.Stack;

class nearestSmallestElement {
    public static void main(String args[]) {
        int a[] = {4, 5, 2, 10, 8};
        int ans[] = prevSmaller(a);
        for (int x : ans) System.out.print(x + " "); 
        System.out.println();
    }

    public static int[] prevSmaller(int[] a) {
        if (a == null) return new int[]{};
        Stack<Integer> st = new Stack<>();
        int n = a.length;
        int ans[] = new int[n];
        Arrays.fill(ans, -1);
        st.push(0);
        for (int i = 1; i < n; i++) {
            if (a[i - 1] < a[i]) ans[i] = a[i - 1];
            else {
                while (!st.isEmpty()) {
                    if (a[st.peek()] < a[i]) {
                        ans[i] = a[st.peek()];
                        break;
                    }
                    st.pop();
                }
            }
            st.push(i);
        }
        return ans;
    }
}