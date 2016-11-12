import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
  public static void main(String[] args) {
    Scanner s = null;
    s = new Scanner(System.in);
    int t;
    t = s.nextInt();
    while(t-- > 0){
      BigInteger i = s.nextBigInteger();
      System.out.println(i.bitCount());
    }
  }
}
