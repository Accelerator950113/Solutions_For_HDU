import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static double s, now;
    static int n, m;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#0.00");

        while (cin.hasNext()) {
            n = cin.nextInt();
            m = cin.nextInt();
            s = n;
            now = Math.sqrt(s);
            int i;
            for (i = 1; i < m; ++ i) {
                s += now;
                now = Math.sqrt(now);
            }
            System.out.println(df.format(s));
        }
    }
}