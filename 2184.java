import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] f = new BigInteger[128]; 
    static BigInteger c;
    static int[][] state = new int[4][128];
    static int n;

    public static void push(int id, int x) {
        state[id][++ state[id][0]] = x;
    }

    public static void solve(int st, int mid, int ed, int num) {
        int flag = c.compareTo(f[num - 1].add(BigInteger.ONE));
        if (flag == 0) {
            push(ed, num);
            int i;
            for (i = num - 1; i > 0; -- i)
                push(mid, i);
            return;
        }
        if (flag > 0) {
            c = c.subtract(f[num - 1].add(BigInteger.ONE));
            push(ed, num);
            solve(mid, st, ed, num - 1);
            return;
        }
        push(st, num);
        solve(st, ed, mid, num - 1);
    }

    public static void main(String []args) {

    	f[0] = BigInteger.ZERO;
        f[1] = BigInteger.ONE;
    	for (n = 2; n <= 100; ++ n) 
            f[n] = f[n - 1].add(f[n - 1]).add(BigInteger.ONE);

        Scanner cin = new Scanner(System.in);

        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            c = cin.nextBigInteger();
            state[1][0] = 0;
            state[2][0] = 0;
            state[3][0] = 0;
            solve(1, 2, 3, n);
            int i, j;
            for (i = 1; i <= 3; ++ i) {
                System.out.printf("%d", state[i][0]);
                for (j = 1; j <= state[i][0]; ++ j)
                    System.out.printf(" %d", state[i][j]);
                System.out.println();
            }
        } 
    }
}