import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] f = new BigInteger[64];
    static BigInteger er = new BigInteger("2");
    static BigInteger san = new BigInteger("3");

    public static void main(String []args) {

        f[0] = san;
        int n;
        for (n = 1; n <= 50; ++ n)
            f[n] = f[n - 1].add(f[n - 1]).subtract(er);
        Scanner cin = new Scanner(System.in);

        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(f[n]);
        }
    }
}