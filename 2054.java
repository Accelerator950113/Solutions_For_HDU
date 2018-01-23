import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        BigDecimal a, b;

        while (cin.hasNext()) {
            a = cin.nextBigDecimal();
            b = cin.nextBigDecimal();
            if (a.compareTo(b) == 0) System.out.println("YES");
            else System.out.println("NO");
        } 
    }
}