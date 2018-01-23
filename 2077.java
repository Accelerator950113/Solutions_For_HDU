import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] f = new BigInteger[128]; //1 -> 3
    static BigInteger[] f1 = new BigInteger[128];
    static BigInteger[] g = new BigInteger[128]; //1 -> 2
    static BigInteger[] h = new BigInteger[128]; //2 -> 3
    static BigInteger er = new BigInteger("2");
    static BigInteger san = new BigInteger("3");
    static int n;

    public static void main(String []args) {

    	f[1] = er;
    	f1[1] = er;
    	g[1] = BigInteger.ONE;
    	h[1] = BigInteger.ONE;
    	for (n = 2; n <= 100; ++ n) {
    		f[n] = g[n - 1].add(h[n - 1]).add(er);
    		f1[n] = f1[n - 1].multiply(san);
    		f1[n] = f1[n].add(er);
    		g[n] = f1[n - 1].add(g[n - 1]).add(BigInteger.ONE);
    		h[n] = h[n - 1].add(f1[n - 1]).add(BigInteger.ONE);
    	}

        Scanner cin = new Scanner(System.in);

        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(f[n]);
        } 
    }
}