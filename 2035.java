import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

    static BigInteger a;
    static int b;
    static BigInteger yiqian;

    public static void main(String []args) {
    
        yiqian = BigInteger.TEN;
        yiqian = yiqian.multiply(BigInteger.TEN).multiply(BigInteger.TEN);

        Scanner cin = new Scanner(System.in);
        
        while (cin.hasNext()) {
            a = cin.nextBigInteger();
            b = cin.nextInt();
            if (b == 0) break;
            System.out.println(a.pow(b).mod(yiqian));
        } 
    }
}