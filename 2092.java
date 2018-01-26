import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static int n, m;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            n = cin.nextInt();
            m = cin.nextInt();
            if ((n == 0) && (m == 0)) break;
            if (m == 0) {
                System.out.println("Yes");
                continue;
            }
            boolean flag = false;
            int i, absm, x, y;
            if (m > 0) absm = m;
            else absm = -m;
            for (i = 1; i*i <= absm; ++ i) 
                if (absm % i == 0) {
                    x = i;
                    y = m / i;
                    if ((x + y == n) || ((-x) + (-y) == n)) {
                        flag = true;
                        break;
                    }
                }
            if (flag) System.out.println("Yes");
            else System.out.println("No");
        }
    }
}