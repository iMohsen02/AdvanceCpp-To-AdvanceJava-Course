package org.example;

public class SecondClass {
    private static Test test = new Test("first Static class");

    static {
        test = new Test("second Static class");
    }

    public SecondClass() {
        test = new Test("third Static class");
    }
}
