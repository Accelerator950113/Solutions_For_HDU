import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        BigDecimal a, b, c;
        int t;

        t = cin.nextInt();
        while ((t --) > 0) {
            a = cin.nextBigDecimal();
            b = cin.nextBigDecimal();
            c = cin.nextBigDecimal();
            if ((a.compareTo(b.add(c)) < 0) && (b.compareTo(a.add(c)) < 0) && (c.compareTo(b.add(a)) < 0)) System.out.println("YES");
            else System.out.println("NO");
        } 
    }
}