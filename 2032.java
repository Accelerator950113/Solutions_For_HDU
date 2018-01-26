import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static long[][] f = new long[64][64];
    static int n;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        int i, j;
        f[1][1] = 1L;
        for (i = 2; i <= 30; ++ i) {
            f[i][1] = 1L;
            f[i][i] = 1L;
            for (j = 2; j < i; ++ j)
                f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }

        while (cin.hasNext()) {
            n = cin.nextInt();
            for (i = 1; i <= n; ++ i) {
                System.out.printf("%d", f[i][1]);
                for (j = 2; j <= i; ++ j)
                    System.out.printf(" %d", f[i][j]);
                System.out.println();
            }
            System.out.println();
        }
    }
}