import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] f = new BigInteger[128];
    static int n;

    public static void main(String []args) {

    	f[1] = BigInteger.ONE;
    	f[2] = new BigInteger("2");
    	for (n = 3; n <= 100; ++ n)
    		f[n] = f[n - 1].add(f[n - 2]);

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(f[n]);
        } 
    }
}