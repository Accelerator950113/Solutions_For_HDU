import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

    static int n;
    static long x;
    static BigInteger s, b;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        b = new BigInteger("1");

        while (cin.hasNext()) {
            n = cin.nextInt();
            s = BigInteger.ONE;
            while ((n --) > 0) {
                x = cin.nextLong();
                if ((x % 2L) == 1L) {
                    b = b.valueOf(x);
                    s = s.multiply(b);
                }
            }
            System.out.println(s);
        } 
    }
}