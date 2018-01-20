import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

	static int n, hire, salary, fire;
	static int[] a;
	static int ans;

	void dfs(int dep, int num, int cost) {
		if (dep > n) {
			if (cost < ans) ans = cost;
			return;
		}
		if (a[dep] >= num) dfs(dep + 1, a[dep], cost + hire * (a[dep] - num) + salary * a[dep]);
		else {
			dfs(dep + 1, num, cost + salary * num);
			int i;
			for (i = dep; i <= n; ++ i) 
				if ((a[i] >= a[dep]) && (a[i] < num)) dfs(dep + 1, a[i], cost + fire * (num - a[i]) + salary * a[i]);
		}
	}

	public static void main(String []args) {
		Main eg = new Main();
		Scanner cin = new Scanner(System.in);
		a = new int[64];

		do {
			n = cin.nextInt();
			if (n == 0) break;
			hire = cin.nextInt();
			salary = cin.nextInt();
			fire = cin.nextInt();
			int i;
			for (i = 1; i <= n; ++ i)
				a[i] = cin.nextInt();
			ans = 2147483644;
			eg.dfs(2, a[1], a[1] * (hire + salary));
			System.out.println(ans);

		} while (true);
	}
}