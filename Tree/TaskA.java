/*input
3
3
0 0 1 1 3 2
4
1 0 1 2 6 3 6 4
3
0 0 1 1 1 2
*/

import java.util.*;
import java.io.*;

class TaskA {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while (t-- > 0) {
			int n = in.nextInt();
		long x[] = new long[n];
		long y[] = new long[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextLong();
			y[i] = in.nextLong();
		}
		long ans = 0;
		for(int i = 0; i < n - 1; i++) {
			long ans1 = 0, ans2 = 0;
			ans1 = Math.abs(x[i] - x[i + 1]);
			ans2 = Math.abs(y[i] - y[i + 1]);
			ans += Math.max(ans2, ans1);
		}
		System.out.println(ans);
		}
		
	}

}