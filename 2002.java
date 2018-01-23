import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static double r;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#0.000");
        String st;

        while (cin.hasNext()) {
            r = cin.nextDouble();
            st = df.format((4.0 / 3.0) * 3.1415927 * (r * r * r));
            System.out.println(st);
        } 
    }
}