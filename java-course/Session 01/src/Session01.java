import java.util.Locale;
import java.util.Scanner;

public class Session01 {
    public static void main(String[] args) throws Exception {

        int[] array = new int[] {1, 2, 3, 4,5};
        Scanner scanner = new Scanner("Salam \n2\nHello class");
//        Scanner sc = new Scanner(new File("address"));

        System.out.println(scanner.nextLine());
        System.out.println(scanner.nextInt());
        scanner.nextLine();
        System.out.println(scanner.nextLine());

        System.out.println("===============================================================");


        System.out.println("how to clear the screen in java(doesn't work in intelliJ terminal)??");
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor(); // add exceptions: throws IOException, InterruptedException
        System.out.print("\033[H\033[2J");

        // Syntax
        // Following are the syntaxes available for the printf() method:

        // System.out.printf(string);
        // System.out.printf(format, arguments);
        // System.out.printf(locale, format, arguments);


        // Format Specifiers Full Syntax
        // Let’s look at the full syntax of format specifiers with the extended set:
        // % [flags] [width] [.precision] specifier-character


        // What does %n in Java printf mean?
        // When you format a String with Java printf, you can use %n in place of \n to specify a line break.


        // printf flag	Purpose
        // –	        Aligns the formatted printf output to the left
        // +	        The output includes a negative or positive sign
        // (	        Places negative numbers in parentheses
        // 0	        The formatted printf output is zero padded
        // ,	        The formatted output includes grouping separators
        // <space>	    A blank space adds a minus sign for negative numbers and a leading space when positive


        // How do you format an integer with printf in Java?
        // To format a digit or integer with Java printf:

        // - Use %d as the conversion specifier for Base-10 numbers.
        // - Precede the letter d with a comma to group numbers by the thousands.
        // - Add an optional + flag to cause positive numbers to display a positive sign.
        // - Use the 0 flag to zero-pad the number to fill up the space specified by the width.

        int  above = -98765;
        long below =  54321L;
        System.out.printf("%,d %n%d%n", above, below);

        // Pattern	    Data	        Printf output
        // ‘%d’	        123457890	    '123457890'
        // ‘%,15d’	    123457890	    '    123,457,890'
        // ‘%+,15d’	    123457890	    '   +123,457,890'
        // ‘%-+,15d’	123457890	    '+123,457,890   '
        // ‘%0,15d’	    123457890	    '0000123,457,890'
        // ‘%15o’	    123457890	    '      726750542'
        // ‘%15x’	    123457890	    '        75bd162'
        System.out.printf("%n%-+,15d hello %n%n", 123457890);


        // How do you format a Java double with printf?
        // - The conversion specifier for a floating point number is %f, not %d.
        // - Use the precision parameter to truncate decimals.
        System.out.printf("%-,15.2f", 12.4567);



        System.out.printf("--------------------------------%n");
        System.out.printf(" Java's Primitive Types         %n");
        System.out.printf(" (printf table example)         %n");

        System.out.printf("--------------------------------%n");
        System.out.printf("| %-10s | %-8s | %4s |%n", "CATEGORY", "NAME", "BITS");
        System.out.printf("--------------------------------%n");

        System.out.printf("| %-10s | %-8s | %04d |%n", "Floating", "double",  64);
        System.out.printf("| %-10s | %-8s | %04d |%n", "Floating", "float",   32);
        System.out.printf("| %-10s | %-8s | %04d |%n", "Integral", "long",    64);
        System.out.printf("| %-10s | %-8s | %04d |%n", "Integral", "int",     32);
        System.out.printf("| %-10s | %-8s | %04d |%n", "Integral", "char",    16);
        System.out.printf("| %-10s | %-8s | %04d |%n", "Integral", "short",   16);
        System.out.printf("| %-10s | %-8s | %04d |%n", "Integral", "byte",    8);
        System.out.printf("| %-10s | %-8s | %04d |%n%n%n", "Boolean",  "boolean", 1);


        boolean adult = true;
        boolean member = false;
        System.out.printf("%b%n", adult);
        // System.out.printf("%b%n", null);
        System.out.printf("%b%n", "random text");
        System.out.printf("%b%n%n", member);

        System.out.printf("%B%n", adult);
        // System.out.printf("%B%n", null);
        System.out.printf("%B%n", "random text");
        System.out.printf("%B%n%n", member);



        System.out.printf("%s%n", "hello world!");
        System.out.printf("'%S' %n", "hello world!");
        System.out.printf("'%10s' %n", "Hello");
        System.out.printf ("'%-10s' %n%n", "Hello");

        System.out.printf(Locale.US, "%,d %n", 12300);
        System.out.printf(Locale.ITALY, "%,d %n%n", 10000);

        System.out.printf("'%015.13f'%n", 2.4);
        System.out.printf("'%015.10f'%n", 2.4);
        System.out.printf("'%015.7f'%n", 2.4);
        System.out.printf("'%015.3f'%n", 2.4);
        System.out.printf("'%015.2f'%n%n", 2.4);
        // System.out.printf("%-015f%n%n", 2.4);// Error
        System.out.printf("'%15.2f'%n", 2.4);
        System.out.printf("'%-15.2f'%n%n", 2.4);

        System.out.printf("'%5.2E'%n", 5.1473);
        System.out.printf("'%5.2e'%n", 5.1473);
    }
}
