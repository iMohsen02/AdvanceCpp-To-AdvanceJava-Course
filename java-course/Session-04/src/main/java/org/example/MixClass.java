package org.example;

public class MixClass {
    private static Test test = new Test("first static Test");
    private Test test2 = new Test("first Test");

    static {
        test = new Test("second static Test");
    }

    {
        this.test2 = new Test("second Test");
    }

    public MixClass() {

        this.test2 = new Test("third Test");
        test = new Test("third static Test");
    }
}
