public class WrapperClassExample2 {
    public static void main(String[] args) {

        //Unboxing
        //The automatic conversion of wrapper type into its corresponding primitive type is known as unboxing. It is the reverse process of autoboxing. Since Java 5, we do not need
        // to use the intValue() method of wrapper classes to convert the wrapper type into primitives.

        //Converting Integer to int
        Integer a = 3;
        int i = a.intValue();//converting Integer to int explicitly
        int j = a;//unboxing, now compiler will write a.intValue() internally

        System.out.println("a(as an Integer(wrapper class) value): " + a +
                "\ni(as an int(primitive) by converting: " + i +
                "\nj(as an int(primitive) by AutoBoxing: " + j);

    }
}
