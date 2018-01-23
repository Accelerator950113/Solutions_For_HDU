import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] f = new BigInteger[128]; 
    static BigInteger c;
    static int n;

    public static int solve(int st, int mid, int ed, int num) {
        int flag = c.compareTo(f[num - 1].add(BigInteger.ONE));
        if (flag == 0) return num;
        if (flag > 0) {
            c = c.subtract(f[num - 1].add(BigInteger.ONE));
            return solve(mid, st, ed, num - 1);
        }
        return solve(st, ed, mid, num - 1);
    }

    public static void main(String []args) {

    	f[0] = BigInteger.ZERO;
        f[1] = BigInteger.ONE;
    	for (n = 2; n <= 100; ++ n) 
            f[n] = f[n - 1].add(f[n - 1]).add(BigInteger.ONE);

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            n = cin.nextInt();
            if (n == 0) break;
            c = cin.nextBigInteger();
            System.out.println(solve(1, 2, 3, n));
        } 
    }
}