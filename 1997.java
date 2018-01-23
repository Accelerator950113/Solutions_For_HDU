import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static int[] a = new int[128];
    static int n, m, x, i;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            m = cin.nextInt();
            for (i = 1; i <= m; ++ i) {
                x = cin.nextInt();
                a[x] = 1;
            }
            m = cin.nextInt();
            for (i = 1; i <= m; ++ i) {
                x = cin.nextInt();
                a[x] = 2;
            }
            m = cin.nextInt();
            for (i = 1; i <= m; ++ i) {
                x = cin.nextInt();
                a[x] = 3;
            }
            int st, mid, ed, tp;
            boolean flag = true;
            st = 1;
            mid = 2;
            ed = 3;
            for (i = n; i > 0; -- i) {
                if (a[i] == mid) {
                    flag = false;
                    break;
                }
                if (a[i] == st) {
                    tp = ed;
                    ed = mid;
                    mid = tp;
                }
                else {
                    tp = st;
                    st = mid;
                    mid = tp;
                }
            }
            System.out.println(flag);
        } 
    }
}