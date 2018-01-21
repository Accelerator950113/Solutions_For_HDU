import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

    public static void main(String []args) {

        int t;
        int as, af, am;
        int bs, bf, bm;
        Scanner cin = new Scanner(System.in);

        t = cin.nextInt();
        while ((t --) > 0) {
            as = cin.nextInt();
            af = cin.nextInt();
            am = cin.nextInt();
            bs = cin.nextInt();
            bf = cin.nextInt();
            bm = cin.nextInt();
            bs += as;
            bf += af;
            bm += am;
            bf += (bm / 60);
            bm %= 60;
            bs += (bf / 60);
            bf %= 60;
            System.out.printf("%d %d %d", bs, bf, bm);
            System.out.println();
        } 
    }
}