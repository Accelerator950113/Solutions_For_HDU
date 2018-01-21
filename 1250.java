import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

    static BigInteger[] f;

    public static void main(String []args) {

        f = new BigInteger[8192];
        int n = 5;
        Scanner cin = new Scanner(System.in);

        f[1] = BigInteger.ONE;
        f[2] = BigInteger.ONE;
        f[3] = BigInteger.ONE;
        f[4] = BigInteger.ONE;
        while (n <= 8000) {
            f[n] = f[n - 1].add(f[n - 2]).add(f[n - 3]).add(f[n - 4]);
            n ++;
        }
        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(f[n]);
        } 
    }
}