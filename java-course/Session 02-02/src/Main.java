import jdk.dynalink.linker.support.CompositeGuardingDynamicLinker;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {

        boolean bool = false; // => Boolean
        char c = 'a'; // Character
        byte b = 22; // Byte
        short s = (short) 36532; // Short
        int i = 2457743; // Integer
        long l = 35406980098L; // Long
        double d = 345.78; // Double
        float f = 34.234f; // Float


//        ArrayList<int> list = new ArrayList<int>(); // error

        Integer integer = 40;
        System.out.println(Integer.MAX_VALUE);
        System.out.println(Integer.MIN_VALUE);

        System.out.println(Integer.SIZE);
        System.out.println(Integer.TYPE);
        System.out.println(Integer.BYTES);

        int x = Integer.parseInt("234");
        System.out.println(++x);


        System.out.println(Integer.toBinaryString(234343464));

        System.out.println(Integer.toHexString(24347));
        System.out.println(Integer.toOctalString(23597));

        System.out.println(Integer.parseInt("01010101110", 2));
        System.out.println(Integer.parseInt("0101", 2, 4, 2));


        String string;
    }
}
