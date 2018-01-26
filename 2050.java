import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] area = new BigInteger[16384];
    static BigInteger[] point = new BigInteger[16384];
    static BigInteger[] num = new BigInteger[16384];
    static int n;

    public static void main(String []args) {

        num[0] = BigInteger.ZERO;
        for (n = 1; n <= 10000; ++ n)
            num[n] = num[n-1].add(BigInteger.ONE);

        point[1] = num[1];
        for (n = 2; n <= 10000; ++ n)
            point[n] = point[n-1].add(num[n-1].multiply(num[4])).add(num[1]);
        area[0] = num[1];
        for (n = 1; n <= 10000; ++ n)
            area[n] = point[n].add(num[1]);

        Scanner cin = new Scanner(System.in);

        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(area[n]);
        }
    }
}