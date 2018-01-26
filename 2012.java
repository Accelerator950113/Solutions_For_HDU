import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static int x, y;

    public static boolean prime(int x) {
        int i;
        for (i = 2; i*i <= x; ++ i)
            if (x % i == 0) return false;
        return true;
    }

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            x = cin.nextInt();
            y = cin.nextInt();
            if ((x == 0) && (y == 0)) break;
            boolean flag = true;
            int i, n;
            for (i = x; i <= y; ++ i) {
                n = i*i + i + 41;
                if (!prime(n)) {
                    flag = false;
                    break;
                }
            }
            if (flag) System.out.println("OK");
            else System.out.println("Sorry");
        }
    }
}