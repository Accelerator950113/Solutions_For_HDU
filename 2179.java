import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigDecimal pi = new BigDecimal("1");
    static BigDecimal er = new BigDecimal("2");
    static BigDecimal aa;
    static BigDecimal bb;
    static String ans;

    public static void main(String []args) {

        int i;
        for (i = 5000; i > 0; -- i) {
            aa = aa.valueOf(i);
            bb = bb.valueOf(2*i+1);
            pi = pi.multiply(aa).divide(bb, 1800, BigDecimal.ROUND_HALF_UP).add(er);
        }
        ans = pi.stripTrailingZeros().toPlainString();

        Scanner cin = new Scanner(System.in);

        int n;
        while (cin.hasNext()) {
            n = cin.nextInt();
            if (n == 0) break;
            System.out.println("3.");
            for (i = 0; i < n; ++ i) {
                System.out.print(" " + ans.substring(5*i+2, 5*i+7));
                if ((i+1) % 10 == 0) System.out.println();
            }
            if (n % 10 != 0) System.out.println();
        }
    }
}