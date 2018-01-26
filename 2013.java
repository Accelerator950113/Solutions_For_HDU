import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] f = new BigInteger[64];
    static BigInteger er = new BigInteger("2");

    public static void main(String []args) {

        f[1] = BigInteger.ONE;
        int n;
        for (n = 2; n <= 50; ++ n)
            f[n] = f[n - 1].add(f[n - 1]).add(er);
        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(f[n]);
        }
    }
}