package gui;

import java.io.*;
import java.util.*;
import java.text.*;
import javax.swing.*;

public final class StudentManager {

    private final ArrayList<Student> list = new ArrayList<>();
    private final String FILE_NAME = "students.txt";

    public StudentManager() {
        loadFromDefaultFile();
    }

    public void addStudent(Student s) {
        list.add(s);
        saveFromDefaultFile();
    }

    public void removeStudent(String id) {
        list.removeIf(s -> s.getID().equalsIgnoreCase(id));
        saveFromDefaultFile();
    }

    public Student findStudent(String id) {
        for (Student s : list) {
            if (s.getID().equalsIgnoreCase(id)) {
                return s;
            }
        }
        return null;
    }

    public ArrayList<Student> getAll() {
        return list;
    }

    public void saveToFile(String fileName) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(fileName))) {
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
            for (Student s : list) {
                bw.write(s.getID() + "," + s.getFullName() + ","
                        + sdf.format(s.getDate()) + ","
                        + s.getGender() + "," + s.getGPA() + "\n");
            }
            bw.close();
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Error saving file: " + e.getMessage());
        }
    }

    public void loadFromFile(String fileName) {
        list.clear();
        File file = new File(fileName);
        if (file.exists()) {
            try (BufferedReader br = new BufferedReader(new FileReader(file))) {
                String line;
                SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
                while ((line = br.readLine()) != null) {
                    String[] parts = line.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");
                    if (parts.length == 5) {
                        String id = parts[0];
                        String name = parts[1];
                        Date date = sdf.parse(parts[2]);
                        String gender = parts[3];
                        double gpa = Double.parseDouble(parts[4]);
                        if (findStudent(id) == null) {
                            list.add(new Student(id, name, date, gender, gpa));
                        }
                    }
                }
            } catch (Exception e) {
                JOptionPane.showMessageDialog(null, "Error loading file: " + e.getMessage());
            }
        } else {
            JOptionPane.showMessageDialog(null, "File not found: " + fileName);
        }
    }

    public void loadFromDefaultFile() {
        loadFromFile(FILE_NAME);
    }

    private void saveFromDefaultFile() {
        saveToFile(FILE_NAME);
    }
}
