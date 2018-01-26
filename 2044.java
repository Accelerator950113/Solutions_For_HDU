import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] f = new BigInteger[128];
    static int a, b;

    public static void main(String []args) {

        f[0] = BigInteger.ONE;
        f[1] = BigInteger.ONE;
        for (a = 2; a <= 100; ++ a)
            f[a] = f[a - 1].add(f[a - 2]);
        Scanner cin = new Scanner(System.in);

        a = cin.nextInt();
        while (cin.hasNext()) {
            a = cin.nextInt();
            b = cin.nextInt();
            System.out.println(f[Math.abs(b - a)]);
        }
    }
}