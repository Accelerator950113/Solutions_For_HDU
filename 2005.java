import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static int[][] a = {{0,31,28,31,30,31,30,31,31,30,31,30,31}, {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    static int yy, mm, dd;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        String str;

        while (cin.hasNext()) {
            str = cin.nextLine();
            String[] s = str.split("/");
            yy = Integer.valueOf(s[0]);
            mm = Integer.valueOf(s[1]);
            dd = Integer.valueOf(s[2]);
            int run = 0;
            if ((yy % 400 == 0) || ((yy % 4 == 0) && (yy % 100 != 0))) run = 1;
            int ts = 0, i;
            for (i = 1; i < mm; ++ i)
                ts += a[run][i];
            ts += dd;
            System.out.println(ts);
        }
    }
}