import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static double x;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("######0.00");
        String st;

        while (cin.hasNext()) {
            x = cin.nextDouble();
            x = Math.abs(x);
            st = df.format(x);
            System.out.println(st);
        } 
    }
}