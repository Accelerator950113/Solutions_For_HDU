import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

	static BigInteger[] f;

	public static void main(String []args) {

		f = new BigInteger[1024];
		int n = 3;
		Scanner cin = new Scanner(System.in);

		f[1] = BigInteger.ONE;
		f[2] = BigInteger.ONE;
		while (n <= 1000) {
			f[n] = f[n - 1].add(f[n - 2]);
			n ++;
		}

		n = cin.nextInt();
		while (cin.hasNext()) {
			n = cin.nextInt();
			System.out.println(f[n]);
		} 
	}
}