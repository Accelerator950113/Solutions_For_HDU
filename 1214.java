import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

	public static long f(long x) {
		return ((x * (x - 1)) / 2);
	}

	public static void main(String []args) {
		long n;
		long a, b;
		long ans;
		Scanner cin = new Scanner(System.in);

		while (cin.hasNext()) {
			n = cin.nextLong();
			a = n / 2L;
			b = n - a;
			ans = f(a) + f(b);
			System.out.println(ans);
		} 
	}
}