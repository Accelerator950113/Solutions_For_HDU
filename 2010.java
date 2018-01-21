import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

    static boolean[] f;

    public static int sf(int x) {
        return (x * x * x);
    }

    public static boolean check(int x) {
        return ((sf(x / 100) + sf((x % 100) / 10) + sf(x % 10)) == x);
    }

    public static void main(String []args) {

        f = new boolean[1024];
        int n,m,ans,i;
        for (n = 100; n <= 999; ++ n)
            f[n] = check(n);
        Scanner cin = new Scanner(System.in);
        
        while (cin.hasNext()) {
            m = cin.nextInt();
            n = cin.nextInt();
            ans = 0;
            for (i = m; i <= n; ++ i)
                if (f[i]) ans ++;
            if (ans == 0) System.out.println("no");
            else {
                for (i = m; i <= n; ++ i)
                    if (f[i]) {
                        ans --;
                        if (ans == 0) System.out.println(i);
                        else System.out.printf("%d ", i);
                    }
            }
        } 
    }
}