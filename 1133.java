import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

    static BigInteger[] num;
    static BigInteger[] g;

    public static void main(String []args) {
        num = new BigInteger[256];
        g = new BigInteger[256];
        num[0] = BigInteger.ZERO;
        num[1] = BigInteger.ONE;
        int i;
        for (i = 2; i <= 200; ++ i)
            num[i] = num[i - 1].add(BigInteger.ONE);
        g[0] = num[1];
        g[1] = num[1];
        for (i = 2; i <= 200; ++ i)
            g[i] = g[i - 1].multiply(num[i]);
        
        int n, m, cst = 0;
        Scanner cin = new Scanner(System.in);
        
        while (cin.hasNext()) {
            n = cin.nextInt();
            m = cin.nextInt();
            if ((n == 0) && (m == 0)) break;
            cst ++;
            System.out.printf("Test #%d:", cst);
            System.out.println();
            if (m > n) System.out.println("0");
            else System.out.println(g[n + m].multiply(num[n - m + 1]).divide(num[n + 1]));
        } 
    }
}