package gui;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.io.*;
import java.util.*;
import java.text.*;

public class MainFrame extends JFrame {

    private StudentManager manager;
    private DefaultTableModel tableModel;
    private JTable table;

    public MainFrame(StudentManager manager) {
        this.manager = manager;
        setTitle("Student Management");
        setSize(700, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        tableModel = new DefaultTableModel(new Object[]{"ID", "Name", "Date", "Gender", "GPA",}, 0);
        table = new JTable(tableModel);
        table.setDefaultEditor(Object.class, null);
        loadTable();
        JScrollPane scrollPane = new JScrollPane(table);
        JButton btnAdd = new JButton("Add");
        JButton btnEdit = new JButton("Edit");
        JButton btnDelete = new JButton("Delete");
        JButton btnSearch = new JButton("Search");
        JButton btnSaveFile = new JButton("Save");
        JButton btnOpenFile = new JButton("Open");
        JButton btnExit = new JButton("Exit");
        JPanel panelButtons = new JPanel();
        panelButtons.add(btnAdd);
        panelButtons.add(btnEdit);
        panelButtons.add(btnDelete);
        panelButtons.add(btnSearch);
        panelButtons.add(btnSaveFile);
        panelButtons.add(btnOpenFile);
        panelButtons.add(btnExit);
        add(scrollPane, BorderLayout.CENTER);
        add(panelButtons, BorderLayout.SOUTH);

        btnAdd.addActionListener(e -> {
            try {
                addStudent();
            } catch (ParseException ex) {
                System.getLogger(MainFrame.class.getName()).log(System.Logger.Level.ERROR, (String) null, ex);
            }
        });
        btnEdit.addActionListener(e -> {
            try {
                editStudent();
            } catch (ParseException ex) {
                System.getLogger(MainFrame.class.getName()).log(System.Logger.Level.ERROR, (String) null, ex);
            }
        });
        btnDelete.addActionListener(e -> deleteStudent());
        btnSearch.addActionListener(e -> searchStudent());
        btnExit.addActionListener(e -> System.exit(0));
        btnSaveFile.addActionListener(e -> saveFile());
        btnOpenFile.addActionListener(e -> loadFile());
    }

    private void loadTable() {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        tableModel.setRowCount(0);
        for (Student s : manager.getAll()) {
            tableModel.addRow(new Object[]{s.getID(), s.getFullName(), sdf.format(s.getDate()), s.getGender(), s.getGPA()});
        }
    }

    private void addStudent() throws ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        try {
            String id = JOptionPane.showInputDialog(this, "Enter student ID:");
            String name = JOptionPane.showInputDialog(this, "Enter full name:");
            Date date = sdf.parse(JOptionPane.showInputDialog(this, "Enter date:"));
            String gender = JOptionPane.showInputDialog(this, "Enter gender:");
            String gpaStr = JOptionPane.showInputDialog(this, "Enter GPA:");

            if (id != null && !id.trim().isEmpty() && name != null
                    && !name.trim().isEmpty() && gpaStr != null && gender != null
                    && date != null) {
                double gpa = Double.parseDouble(gpaStr);
                manager.addStudent(new Student(id, name, date, gender, gpa));
                loadTable();
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Invalid GPA input!!", "Error", JOptionPane.ERROR_MESSAGE);
        } catch (ParseException e) {
            JOptionPane.showMessageDialog(this, "Invalid date format! Use dd/MM/yyyy", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void editStudent() throws ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        int row = table.getSelectedRow();
        if (row >= 0) {
            String id = (String) tableModel.getValueAt(row, 0);
            Student s = manager.findStudent(id);
            if (s != null) {
                try {
                    String newName = JOptionPane.showInputDialog(this, "Enter new name:", s.getFullName());
                    String newGpaStr = JOptionPane.showInputDialog(this, "Enter new GPA:", s.getGPA());
                    String newGender = JOptionPane.showInputDialog(this, "Enter new gender:", s.getGender());
                    Date newDate = sdf.parse(JOptionPane.showInputDialog(this, "Enter new date:", sdf.format(s.getDate())));
                    if (newName != null && !newName.trim().isEmpty() && newGpaStr != null) {
                        double newGpa = Double.parseDouble(newGpaStr);
                        s.setFullName(newName);
                        s.setGPA(newGpa);
                        s.setDate(newDate);
                        s.setGender(newGender);
                        loadTable();
                    }
                } catch (NumberFormatException e) {
                    JOptionPane.showMessageDialog(this, "Invalid GPA input!!", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        } else {
            JOptionPane.showMessageDialog(this, "Choose a student to edit");
        }
    }

    private void deleteStudent() {
        int row = table.getSelectedRow();
        if (row >= 0) {
            String id = (String) tableModel.getValueAt(row, 0);
            manager.removeStudent(id);
            loadTable();
        } else {
            JOptionPane.showMessageDialog(this, "Choose a student to delete");
        }
    }

    private void searchStudent() {
        String id = JOptionPane.showInputDialog(this, "Enter student ID to find: ");
        if (id != null && !id.trim().isEmpty()) {
            Student s = manager.findStudent(id);
            if (s != null) {
                JOptionPane.showMessageDialog(this, "Found: " + s);
            } else {
                JOptionPane.showMessageDialog(this, "Student not found");
            }
        }
    }

    private void saveFile() {
        manager.saveToFile();
        JOptionPane.showMessageDialog(this, "Saved successfully!!");
    }

    private void loadFile() {
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setCurrentDirectory(new File("."));

        int res = fileChooser.showOpenDialog(null);
        if (res == JFileChooser.APPROVE_OPTION) {
            File file = fileChooser.getSelectedFile();
            manager.loadFromFile(file.getAbsolutePath());
            loadTable();
            JOptionPane.showMessageDialog(this, "Loaded successfully!");
        }

    }

}
