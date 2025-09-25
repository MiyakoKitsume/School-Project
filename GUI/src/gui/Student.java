package gui;

import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Student implements Serializable {

    private String ID;
    private String fullName;
    private Date date;
    private String gender;
    private double GPA;

    public Student(String ID, String fullName, Date date, String gender, double GPA) {
        this.ID = ID;
        this.fullName = fullName;
        this.date = date;
        this.gender = gender;
        this.GPA = GPA;
    }

    public String getID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public double getGPA() {
        return GPA;
    }

    public void setGPA(double GPA) {
        this.GPA = GPA;
    }

    public void setFullName(String fullName) {
        this.fullName = fullName;
    }

    public String getFullName() {
        return fullName;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public Date getDate() {
        return date;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getGender() {
        return gender;
    }

    @Override
    public String toString() {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        return String.format("ID: %s | Name: %s | Date: %s | Gender: %s | GPA: %.2f",
                ID, fullName, sdf.format(date), gender, GPA);
    }
}
