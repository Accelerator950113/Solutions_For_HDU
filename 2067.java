import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] num = new BigInteger[128];
    static BigInteger[] f = new BigInteger[128];
    static int i, j, n;

    public static void main(String []args) {

        num[0] =BigInteger.ZERO;
        for (i = 1; i <= 120; ++ i) 
            num[i] = num[i-1].add(BigInteger.ONE);
        f[0] = BigInteger.ONE;
        for (i = 1; i <= 50; ++ i) {
            f[i] = BigInteger.ONE;
            for (j = i+1; j <= 2*i; ++ j) 
                f[i] = f[i].multiply(num[j]);
            for (j = 2; j <= i+1; ++ j)
                f[i] = f[i].divide(num[j]);
        }

        Scanner cin = new Scanner(System.in);

        i = 0;
        while (cin.hasNext()) {
            n = cin.nextInt();
            i = i + 1;
            if (n < 0) break; 
            System.out.println(i + " " + n + " " + f[n].add(f[n]));
        }
    }
}