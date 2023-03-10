import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class WrapperClassExample4 {

    public static void main(String[] args) throws IOException, InterruptedException {


        System.out.println(Integer.MIN_VALUE);
        System.out.println(Integer.MAX_VALUE);
        System.out.println(Integer.SIZE);
        System.out.println(Integer.BYTES);

        String stringFive = "5";
        String stringBinaryFive = "101";

        Integer intToInt = Integer.valueOf(5);
        System.out.println("value of 5:\t" + intToInt);

        int StringToInt = Integer.valueOf(stringFive);
//         int error = Integer.valueOf("5te"); // error
        System.out.println("value of String 5 is:\t" + StringToInt);
//
        int binToInt = Integer.valueOf(stringBinaryFive, 2);
////        int error = Integer.valueOf("11dj", 2);
        System.out.println("binary to int:\t"  + binToInt);
//
//        int five = Integer.parseInt(stringFive);
//        System.out.println(five);
//
//        System.out.println(Integer.parseInt("11", 16));
//        System.out.println(Integer.parseInt("salama 126541 Bye Bye", 7, 13, 16));
//
        System.out.println(Integer.parseUnsignedInt("10"));
//
        int num = 97998;
        System.out.println(Integer.reverse(2567));
//
//        System.out.println(Integer.reverseBytes(1));
//
//        System.out.println("0".repeat(15) + Integer.toBinaryString(num));
//        System.out.println(Integer.toBinaryString(~num));
//
//
        System.out.println(Double.TYPE);
        System.out.println(Double.toHexString(2.4));
        System.out.println(Double.valueOf("0x1.3333333333333p1"));
        System.out.println(Double.isNaN(0.0 / 0.0)); // NaN => not a number
        System.out.println(Double.isFinite(1.0d / 0.0));
//
        System.out.println(Character.isDigit('a'));
        System.out.println(Character.isDigit('2'));
//
//
//

    }
}
