import java.util.*;
// import java.util.Scanner;

public class Assignment6 {
    public class user {
        Scanner sc = new Scanner(System.in);
        user(){}
        protected String name;
        protected int dateOfBirth;
        protected int userID;
        user(String name,int dateOfBirth,int userID) {
            this.name = name;
            this.dateOfBirth = dateOfBirth;
            this.userID = userID;
        }
        // @Override
        void setDetails() {
            // super.setDetails(name, dateOfBirth, userID);
            System.out.println("Enter the Name:\n");
            String name = sc.next();
            System.out.println("Enter the Date Of Birth :\n");
            int dateOfBirth = sc.nextInt();
            System.out.println("Enter UserID:\n");
            int userID = sc.nextInt();
            this.name = name;
            this.dateOfBirth = dateOfBirth;
            this.userID = userID;
        }
    }
    public class student extends user {
        protected String rollNo;
        protected int semester;
        protected int CPI;
        student() {}
        student(String rollNo,int semester,int CPI) {
            this.rollNo = rollNo;
            this.semester = semester;
            this.CPI = CPI;
        }
        @Override
        void setDetails() {
            super.setDetails();
            System.out.println("Enter the Roll no:\n");
            String rollNo = sc.next();
            System.out.println("Enter the Semester :\n");
            int semester = sc.nextInt();
            System.out.println("Enter CPI:\n");
            int CPI = sc.nextInt();
            this.rollNo = rollNo;
            this.semester = semester;
            this.CPI = CPI;
        }
    }
    public class staff extends user {
        protected String employeeID;
        protected int sectionName;
        protected int designation;
        staff() {}
        staff(String employeeID,int sectionName,int designation) {
            this.employeeID = employeeID;
            this.sectionName = sectionName;
            this.designation = designation;
        }
        boolean checkDesignation(staff s1,staff s2) {
            return s1.designation == s2.designation;
        }
        @Override
        void setDetails() {
            super.setDetails();
            System.out.println("Enter the Employee ID\n");
            String employeeID = sc.next();
            System.out.println("Enter the Section Name\n");
            int sectionName = sc.nextInt();
            System.out.println("Enter the no of designation");
            int designation = sc.nextInt();
            this.employeeID = employeeID;
            this.sectionName = sectionName;
            this.designation = designation;
        }
    }
    public class faculty extends user {
        protected int employeeId;
        protected String departmentName;
        protected int noOfPublications;
        faculty() {}
        faculty(int employeeId,String departmentName,int noOfPublications) {
            this.employeeId = employeeId;
            this.departmentName = departmentName;
            this.noOfPublications = noOfPublications;
        }
        boolean checkDepartment(faculty f1,faculty f2) {
            return f1.departmentName == f2.departmentName;
        }
        @Override
        void setDetails() {
            super.setDetails();
            System.out.println("Enter the department name\n");
            String departmentName = sc.next();
            System.out.println("Enter the employee ID\n");
            int employeeId = sc.nextInt();
            System.out.println("Enter the no of publications");
            int noOfPublications = sc.nextInt();
            this.employeeId = employeeId;
            this.departmentName = departmentName;
            this.noOfPublications = noOfPublications;
        }
    }
    public static void main(String[] args) {

    }
}
