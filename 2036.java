import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static double[] x = new double[128];
    static double[] y = new double[128];
    static int n;
    static double ans;

    static double cross(double x1, double y1, double x2, double y2) {
        return (x1*y2 - x2*y1);
    }

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#0.0");

        while (cin.hasNext()) {
            n = cin.nextInt();
            if (n == 0) break;
            int i;
            for (i = 0; i < n; ++ i) {
                x[i] = cin.nextDouble();
                y[i] = cin.nextDouble();
            }
            ans = 0;
            for (i = 2; i < n;++ i) 
                ans += cross(x[i-1] - x[0], y[i-1] - y[0], x[i] - x[0], y[i] - y[0]);
            System.out.println(df.format(Math.abs(ans) / 2.0));
        }
    }
}