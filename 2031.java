import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger x;
    static int y;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        String st;
        char ch1, ch2;

        while (cin.hasNext()) {
            x = cin.nextBigInteger();
            y = cin.nextInt();
            st = x.toString(y);
            for (ch1 = 'a', ch2 = 'A'; ch1 < 'g'; ++ ch1, ++ ch2)
                st = st.replace(ch1, ch2);
            System.out.println(st);
        }
    }
}