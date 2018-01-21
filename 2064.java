import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

    static BigInteger[] f;
    static BigInteger san;

    public static void main(String []args) {
        
        f = new BigInteger[128];
        f[0] = BigInteger.ZERO;
        f[1] = BigInteger.ONE;
        f[1] = f[1].add(f[1]);
        san = f[1].add(BigInteger.ONE);
        int n;
        for (n = 2; n <= 50; ++ n) {
            f[n] = f[n - 1].multiply(san);
            f[n] = f[n].add(f[1]);
        }

        Scanner cin = new Scanner(System.in);
        
        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(f[n]);
        } 
    }
}