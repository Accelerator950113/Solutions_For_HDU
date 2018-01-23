import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[][] f;

    public static void main(String []args) {

        f = new BigInteger[128][4];
        Scanner cin = new Scanner(System.in);
        int n;
        f[1][0] = BigInteger.ONE;
        f[1][1] = BigInteger.ONE;
        f[1][2] = BigInteger.ONE;
        for (n = 2; n <= 100; ++ n) {
            f[n][0] = f[n - 1][1].add(f[n - 1][2]);
            f[n][1] = f[n - 1][0].add(f[n - 1][1]).add(f[n - 1][2]);
            f[n][2] = f[n - 1][0].add(f[n - 1][1]).add(f[n - 1][2]);
        }

        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(f[n][0].add(f[n][1]).add(f[n][2]));
        } 
    }
}