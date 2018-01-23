import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static char[] a = new char[16];
    static String s;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            s = cin.nextLine();
            int l = s.length();
            int i;
            for (i = 0; i < l; ++ i)
                a[i] = s.charAt(i);
            Arrays.sort(a, 0, l);
            System.out.print(a[0]);
            for (i = 1; i < l; ++ i)
                System.out.print(" " + a[i]);
            System.out.println();
        } 
    }
}