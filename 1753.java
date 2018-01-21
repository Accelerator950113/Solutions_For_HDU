import java.util.*;
import java.math.BigDecimal;

public class Main{ 

	public static void main(String []args) {

		BigDecimal a,b;
		Scanner cin = new Scanner(System.in);

		while (cin.hasNext()) {
			a = cin.nextBigDecimal();
			b = cin.nextBigDecimal();
			System.out.println(a.add(b).stripTrailingZeros().toPlainString());
		} 
	}
}