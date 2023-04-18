package org.example;

import java.util.Random;

public class Main {
    public static void main(String[] args) {

        // normal variables
        FirstClass firstClass = new FirstClass();

        System.out.println("=".repeat(50));

        // static variables
        SecondClass secondClass = new SecondClass();

        System.out.println("=".repeat(50));

        // mix { normal variables vs static variables }
        MixClass mix = new MixClass();

        // does static initialization repeat?
        System.out.println("=".repeat(50));
        new MixClass();
        new MixClass();

        System.out.println("=".repeat(50));

        System.out.println(new Student());
        System.out.println(new Student());

        System.out.println("=".repeat(50));
        // =================================================================

        Random r = new Random(2L);
        System.out.println(r.nextInt());
        System.out.println(r.nextInt());
    }
}
