import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

	long solve(long m, long n) {
		if (m == 0) return (n + 1);
		else if (n == 0) return (solve(m - 1, 1));
		else if (m == 1) return (n + 2);
		else if (m == 2) return (2*n + 3);
		else if (m == 3) return (solve(m, n - 1) * 2 + 3);
		return -1L;
	}

	public static void main(String []args) {
		Main eg = new Main();
		long m,n,ans;
		Scanner cin = new Scanner(System.in);

		while (cin.hasNext()) {
			m = cin.nextLong();
			n = cin.nextLong();
			ans = eg.solve(m, n);
			System.out.println(ans);
		}
	}
}