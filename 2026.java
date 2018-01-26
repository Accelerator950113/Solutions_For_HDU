import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static String str;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            str = cin.nextLine();
            String[] s = str.split(" ");
            int i;
            for (i = 0; i < s.length; ++ i) {
                if (i != 0) System.out.print(" ");
                System.out.print(s[i].substring(0, 1).toUpperCase() + s[i].substring(1, s[i].length()));
            }
            System.out.println();
        }
    }
}