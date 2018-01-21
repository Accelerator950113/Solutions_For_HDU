import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

    static long a, b;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        a = cin.nextLong();
        while (cin.hasNext()) {
            a = cin.nextLong();
            b = cin.nextLong();
            if ((a % b) == 0L) System.out.println("YES");
            else System.out.println("NO");
        } 
    }
}