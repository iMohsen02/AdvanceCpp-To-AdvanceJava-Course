package org.example;

public class Student {
    public static int IdGenerator = 1000;
    private int id;

    public Student() {
        this.id = IdGenerator++;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                '}';
    }
}
