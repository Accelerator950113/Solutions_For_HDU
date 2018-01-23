import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static double x1, y1, x2, y2;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#0.00");
        String st;

        while (cin.hasNext()) {
            x1 = cin.nextDouble();
            y1 = cin.nextDouble();
            x2 = cin.nextDouble();
            y2 = cin.nextDouble();
            st = df.format(Math.hypot(x1 - x2, y1 - y2));
            System.out.println(st);
        } 
    }
}