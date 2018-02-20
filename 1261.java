import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] num = new BigInteger[512];
    static BigInteger ans;

    public static void main(String[] args) {

    	num[0] = BigInteger.ZERO;
    	num[1] = BigInteger.ONE;
    	int i, j;
    	for (i = 2; i <= 400; ++ i)
    		num[i] = num[i-1].add(num[1]);

        Scanner cin = new Scanner(System.in);
        int n, s;
        int[] a = new int[32];

        while (cin.hasNext()) {
            n = cin.nextInt();
            if (n == 0)
            	break;
            s = 0;
            for (i = 1; i <= n; ++ i) {
            	a[i] = cin.nextInt();
            	s += a[i];
            }
            ans = BigInteger.ONE;
            for (i = 2; i <= s; ++ i)
            	ans = ans.multiply(num[i]);
            for (i = 1; i <= n; ++ i)
            	for (j = 2; j <= a[i]; ++ j)
            		ans = ans.divide(num[j]);
            System.out.println(ans);
        }
    }
}