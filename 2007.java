import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static int x, y, s1, s2;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            x = cin.nextInt();
            y = cin.nextInt();
            s1 = 0;
            s2 = 0;
            int i;
            for (i = Math.min(x, y); i <= Math.max(x, y); ++ i)
                if (i % 2 == 0) s1 += (i*i);
                else s2 += (i*i*i);
            System.out.println(s1 + " " + s2);
        }
    }
}