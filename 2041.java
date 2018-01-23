import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] f;

    public static void main(String []args) {

        f = new BigInteger[128];
        Scanner cin = new Scanner(System.in);
        int n;
        f[1] = BigInteger.ONE;
        f[2] = BigInteger.ONE;
        for (n = 3; n <= 100; ++ n) 
            f[n] = f[n - 1].add(f[n - 2]);

        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(f[n]);
        } 
    }
}