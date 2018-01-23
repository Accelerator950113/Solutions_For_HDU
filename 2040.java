import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static int x, y;
    static String s;

    public static int calc(int x) {
        int i, ts = 1;
        for (i = 2; i*i <= x; ++ i) 
            if (x % i == 0) {
                if (i*i == x) ts += i;
                else {
                    ts += i;
                    ts += (x / i);
                }
            }
        return ts;
    } 

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        x = cin.nextInt();
        while (cin.hasNext()) {
            x = cin.nextInt();
            y = cin.nextInt();
            if ((calc(x) == y) && (calc(y) == x)) System.out.println("YES");
            else System.out.println("NO");
        } 
    }
}