import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static double[] f = new double[2048];
    static int n;

    public static void main(String []args) {

        f[1] = 1;
        for (n = 2; n <= 2000; ++ n) 
            if (n % 2 == 0) f[n] = f[n - 1] - (1.0 / n);
            else f[n] = f[n - 1] + (1.0 / n);

        Scanner cin = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#0.00");

        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(df.format(f[n]));
        }
    }
}