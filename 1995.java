import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

    static BigInteger[][] f;
    static BigInteger er;
    static int n,m;

    public static void main(String []args) {
    
        er = new BigInteger("2");
        f = new BigInteger[128][128];
        f[1][1] = BigInteger.ONE;
        for (n = 2; n <= 100; ++ n) {
            f[n][n] = BigInteger.ONE;
            for (m = 1; m < n; ++ m)
                f[n][m] = f[n - 1][m].multiply(er);
        }

        Scanner cin = new Scanner(System.in);
        
        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            m = cin.nextInt();
            System.out.println(f[n][m]);
        } 
    }
}