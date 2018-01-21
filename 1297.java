import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

    static BigInteger[][] f;
    static BigInteger[] g;

    public static void main(String []args) {

        f = new BigInteger[1024][4];
        g = new BigInteger[1024];
        int n;
        Scanner cin = new Scanner(System.in);

        f[2][0] = BigInteger.ONE;
        f[2][1] = BigInteger.ZERO;
        f[2][2] = BigInteger.ONE;
        f[2][3] = BigInteger.ONE;
        g[1] = BigInteger.ONE;
        g[2] = g[1].add(g[1]);
        for (n = 3; n <= 1000; ++ n) {
            f[n][0] = f[n - 1][0].add(f[n - 1][1]);
            f[n][1] = f[n - 1][3];
            f[n][2] = f[n - 1][0].add(f[n - 1][1]);
            f[n][3] = f[n - 1][3].add(f[n - 1][2]);
            g[n] = f[n][0].add(f[n][1]).add(f[n][3]);
        }
        
        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(g[n]);
        } 
    }
}