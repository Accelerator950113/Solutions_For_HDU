import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger a, b;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            System.out.println(a.multiply(b).toString());
        }
    }
}