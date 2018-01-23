import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        BigInteger a, b;
        String st;
        char ch, ch2;

        while (cin.hasNext()) {
            a = cin.nextBigInteger(16);
            b = cin.nextBigInteger(16);
            st = a.add(b).toString(16);
            for (ch = 'a', ch2 = 'A'; ch < 'g'; ++ ch, ++ ch2)
                st = st.replace(ch, ch2);
            System.out.println(st);
        } 
    }
}