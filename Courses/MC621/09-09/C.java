// C. Escadas Rolantes

// Should rename class and filename to Main (Main.java) when sending to judge

import java.math.BigInteger;
import java.util.Scanner;

public class Main{
  public static void main(String[] args)
  {
    Scanner scanner = new Scanner(System.in);

    BigInteger s = scanner.nextBigInteger();
    BigInteger d = scanner.nextBigInteger();
    BigInteger two = new BigInteger("2");

    int r = 0;
    while(s.compareTo(BigInteger.ZERO) > 0){
      if(s.remainder(two).compareTo(BigInteger.ZERO) == 0)
        r = 1 - r;
      s = s.divide(d);
    }

    if(r == 0)
      System.out.println("sobe desce");
    else
      System.out.println("desce sobe");

  }
}
