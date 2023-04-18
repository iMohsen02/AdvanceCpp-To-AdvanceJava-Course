package org.example;

public class FirstClass {
    private Test test = new Test("first Test Initialization");

    {
        this.test = new Test("second Test Initialization");
    }

    public FirstClass() {
        this.test = new Test("third Test Initialization");
    }
}
