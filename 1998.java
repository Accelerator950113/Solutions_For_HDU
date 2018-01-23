import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static int[][] a = new int[128][128];
    static int n, x, y, nx, ny, i, j;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            x = 1;
            y = (n + 1) / 2;
            for (i = 1; i <= n; ++ i)
                for (j = 1; j <= n; ++ j)
                    a[i][j] = 0;
            a[x][y] = 1;
            for (i = 2; i <= n*n; ++ i) {
                nx = x - 1;
                ny = y + 1;
                if (nx == 0) nx = n;
                if (ny > n) ny = 1;
                if (a[nx][ny] != 0) {
                    nx = x + 1;
                    ny = y;
                } 
                a[nx][ny] = i;
                x = nx;
                y = ny;
            }
            for (i = 1; i <= n; ++ i) {
                for (j = 1; j <= n; ++ j)
                    System.out.printf("%4d", a[i][j]);
                System.out.println();
            }
        } 
    }
}