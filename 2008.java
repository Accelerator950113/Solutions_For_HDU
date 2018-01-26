import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static int n;
    static double x;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            n = cin.nextInt();
            if (n == 0) break;
            int z = 0, f = 0, l = 0;
            int i;
            for (i = 0; i < n; ++ i) {
                x = cin.nextDouble();
                if (x > 0) z ++;
                else if (x < 0) f ++;
                else l ++;
            }

            System.out.println(f + " " + l + " " + z);
        }
    }
}