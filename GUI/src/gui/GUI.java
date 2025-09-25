package gui;

public class GUI {

    public static void main(String[] args) {
        StudentManager manager = new StudentManager();
        MainFrame mainFrame = new MainFrame(manager);
        mainFrame.setVisible(true);
    }

}
