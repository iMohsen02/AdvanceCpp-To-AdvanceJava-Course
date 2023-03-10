/**
 * <h2>Wrapper classes in Java</h2>
 * <p>The wrapper class in Java provides the mechanism to convert primitive into object and object into primitive.</p>
 * <p>Since J2SE 5.0, autoboxing and unboxing feature convert primitives into objects and objects into primitives automatically. The automatic conversion of primitive into an object is known as autoboxing and vice-versa unboxing.</p>
 * <hr>
 * <h3>Use of Wrapper classes in Java</h3>
 * <p>Java is an object-oriented programming language, so we need to deal with objects many times like in Collections, Serialization, Synchronization, etc. Let us see the different scenarios, where we need to use the wrapper classes.</p><br>
 * <p><b>Change the value in Method: </b><i>Java supports only call by value. So, if we pass a primitive value, it will not change the original value. But, if we convert the primitive value in an object, it will change the original value.</i></p>
 * <p><b>Serialization: </b><i>We need to convert the objects into streams to perform the serialization. If we have a primitive value, we can convert it in objects through the wrapper classes.</i></p>
 * <p><b>Synchronization: </b><i>Java synchronization works with objects in Multithreading.</i></p>
 * <p><b>java.util package: </b><i>The java.util package provides the utility classes to deal with objects.</i></p>
 * <p><b>Collection Framework: </b><i>Java collection framework works with objects only. All classes of the collection framework (ArrayList, LinkedList, Vector, HashSet, LinkedHashSet, TreeSet, PriorityQueue, ArrayDeque, etc.) deal with objects only.</i></p><br>
 *
 * <p>The eight classes of the java.lang package are known as wrapper classes in Java. The list of eight wrapper classes are given below:</p>
 * <pre style="font: Times New Roman"><b>Primitive Type               	Wrapper class</b></pre><hr>
 * <pre style="font: Times New Roman"><i>boolean	                          Boolean</i></pre>
 * <pre style="font: Times New Roman"><i>char	                          Character</i></pre>
 * <pre style="font: Times New Roman"><i>byte                         	Byte</i></pre>
 * <pre style="font: Times New Roman"><i>short                        	Short</i></pre>
 * <pre style="font: Times New Roman"><i>int	                          Integer</i></pre>
 * <pre style="font: Times New Roman"><i>long                         	Long</i></pre>
 * <pre style="font: Times New Roman"><i>float	                          Float</i></pre>
 * <pre style="font: Times New Roman"><i>double	                          Double</i></pre>
 */
public class WrapperClassExample1 {
    public static void main(String[] args) {

        //Autoboxing:
        //The automatic conversion of primitive data type into its corresponding wrapper class is known as autoboxing, for example, byte to Byte, char to Character, int to Integer,
        // long to Long, float to Float, boolean to Boolean, double to Double, and short to Short.

        //Java program to convert primitive into objects
        //Autoboxing example of int to Integer
        int a = 20;
        Integer i = Integer.valueOf(a);//converting int into Integer explicitly
        Integer j = a;//autoboxing, now compiler will write Integer.valueOf(a) internally

        System.out.println("a(as an int(primitive) value): " + a +
                "\ni(as an Integer(wrapper class) by converting: " + i +
                "\nj(as an Integer(wrapper class) by AutoBoxing: " + j);
    }
}
