import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger n;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            n = cin.nextBigInteger();
            System.out.println(n.toString(2));
        } 
    }
}