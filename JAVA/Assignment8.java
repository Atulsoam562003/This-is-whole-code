import java.util.*;

class User {
    protected String firstName;
    protected String LastName;
    protected String DateOfBirth;
    protected String pin;
    protected String pan;
    protected String email;

    public void validate() {
        boolean flag = true;
        String temp = pan.toUpperCase();;
        if(!temp.equals(pin)) flag = false;
        else if(pin.length() != 6) flag = false;
        int months = Integer.parseInt(DateOfBirth.substring(0, 2));
        int date = Integer.parseInt(DateOfBirth.substring(2, 4));
        String year = DateOfBirth.substring(4);

        if(months > 12 || months < 1 || date > 31 || date < 1 || year.length() != 4) flag = false;

        if(!flag) {
            System.out.println("Please enter the values again you are not following rules : ");
            return;
        }
    }

    public void setDetails() {
        Scanner input = new Scanner(System.in);


        System.out.print("Enter first Name : ");
        String firstName = input.nextLine();

        System.out.print("Enter Last Name : ");
        String lastName = input.nextLine();

        System.out.print("Enter Date of Birth : ");
        String DateOfBirth = input.next();

        System.out.println("Enter the Email");
        String email = input.next();

        System.out.print("Enter pan : ");
        String pan = input.nextLine();

        System.out.print("Enter User-Id : ");
        String pin = input.next();
        this.firstName = firstName;
        this.DateOfBirth = DateOfBirth;
        this.pin = pin;
        this.LastName = lastName;
        this.pan = pan;
        this.email = email;
    }

    public void showDetails(String DateOfBirth) {
        if (this.DateOfBirth == DateOfBirth) {
            System.out.println("\tName : " + firstName);
            System.out.println("\tBirth-date : " + DateOfBirth);
            System.out.println("\tUser-Id : " + pin);
        }
    }
}

class Student extends User {
    private int rollno;
    private int semester;
    private float cpi;

    Student() {}

    Student(String firstName,String lastName, String DateOfBirth,String pan ,String pin, int rollno, int semester, float cpi,String email) {
        this.firstName = firstName;
        this.DateOfBirth = DateOfBirth;
        this.pin = pin;
        this.rollno = rollno;
        this.semester = semester;
        this.cpi = cpi;
        this.LastName = lastName;
        this.pan = pan;
        this.email = email;
    }

    public void setDetails() {
        Scanner input = new Scanner(System.in);
        super.setDetails();

        System.out.print("Enter Roll-No : ");
        int rollno = input.nextInt();
        input.nextLine();

        System.out.print("Enter Semester : ");
        int semester = input.nextInt();
        input.nextLine();

        System.out.print("Enter CPI : ");
        float cpi = input.nextFloat();
        input.nextLine();

        this.rollno = rollno;
        this.semester = semester;
        this.cpi = cpi;
    }

    public void showDetails(String DateOfBirth) {
        if (this.DateOfBirth == DateOfBirth) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(DateOfBirth);
            System.out.println("\tRoll-No : " + rollno);
            System.out.println("\tSemester : " + semester);
            System.out.println("\tCPI : " + cpi);
            System.out.println("--------------------------------------------------------------");

        }

    }

    public void displayDetails(String pin, int rollno, String DateOfBirth) {
        if (this.pin.equals(pin) && this.rollno == rollno && this.DateOfBirth == DateOfBirth) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(DateOfBirth);
            System.out.println("\tRoll-No : " + rollno);
            System.out.println("\tSemester : " + semester);
            System.out.println("\tCPI : " + cpi);
            System.out.println("--------------------------------------------------------------");
        }
    }

}

class Faculty extends User {
    private String employeeId;
    private String departmentName;
    private int noOfPublications;

    Faculty() {

    }

    Faculty(String firstName,String lastName, String DateOfBirth,String pan , String pin, String employeeId, String departmentName, int noOfPublications,String email) {
        this.firstName = firstName;
        this.DateOfBirth = DateOfBirth;
        this.pin = pin;
        this.employeeId = employeeId;
        this.departmentName = departmentName;
        this.noOfPublications = noOfPublications;
        this.LastName = lastName;
        this.pan = pan;
        this.email = email;
    }

    public Boolean checkUserId(String pin) {
        if (this.pin == pin) {
            return false;
        }
        return true;
    }

    public Boolean checkEmployeeId(String employeeId) {
        if (this.employeeId == employeeId) {
            return false;
        }
        return true;
    }

    public void setDetails() {
        Scanner input = new Scanner(System.in);
        super.setDetails();
        System.out.print("Enter Employee-Id : ");
        String employeeId = input.nextLine();

        System.out.print("Enter DepartmentName : ");
        String departmentName = input.nextLine();

        System.out.print("Enter NoOfPublications : ");
        int noOfPublications = input.nextInt();
        input.nextLine();

        this.employeeId = employeeId;
        this.departmentName = departmentName;
        this.noOfPublications = noOfPublications;
    }

    public void showDetails(String DateOfBirth) {
        if (this.DateOfBirth == DateOfBirth) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(DateOfBirth);
            System.out.println("\tEmployee-ID : " + employeeId);
            System.out.println("\tDepartmentName : " + departmentName);
            System.out.println("\tNoOfPublications  : " + noOfPublications);
            System.out.println("--------------------------------------------------------------");

        }

    }

    public void displayDetails(String pin, String employeeId, String DateOfBirth) {
        if (this.pin.equals(pin) && this.employeeId.equals(employeeId) && this.DateOfBirth == DateOfBirth) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(DateOfBirth);
            System.out.println("\tEmployeeID : " + employeeId);
            System.out.println("\tDepartmentName : " + departmentName);
            System.out.println("\tNoOfPublications  : " + noOfPublications);
            System.out.println("--------------------------------------------------------------");
        }
    }

    public String getuserId() {
        return this.pin;
    }

    public void checkDepartment(Faculty f1, Faculty f2) {
        if (f1.departmentName.equals(f2.departmentName)) {
            System.out.println("Same department!");
        } else {
            System.out.println("Different department!");
        }
    }
}

class Staff extends User {
    private String employeeId;
    private String sectionName;
    private String designation;

    Staff() {}

    Staff(String firstName,String lastName, String DateOfBirth,String pan , String pin, String employeeId, String sectionName, String designation,String email) {
        this.firstName = firstName;
        this.pin = pin;
        this.DateOfBirth = DateOfBirth;
        this.employeeId = employeeId;
        this.sectionName = sectionName;
        this.designation = designation;
        this.LastName = lastName;
        this.pan = pan;
        this.email = email;
    }

    public void setDetails() {
        Scanner input = new Scanner(System.in);
        super.setDetails();

        System.out.print("Enter EmployeeId : ");
        String employeeId = input.nextLine();

        System.out.print("Enter SectionName : ");
        String sectionName = input.nextLine();

        System.out.print("Enter Designation : ");
        String designation = input.nextLine();

        this.employeeId = employeeId;
        this.sectionName = sectionName;
        this.designation = designation;
    }

    public void showDetails(String DateOfBirth) {
        if (this.DateOfBirth == DateOfBirth) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(DateOfBirth);
            System.out.println("\tEmployeeID : " + employeeId);
            System.out.println("\tSectionName : " + sectionName);
            System.out.println("\tDesignation  : " + designation);
            System.out.println("--------------------------------------------------------------");
        }
    }

    public void displayDetails(String pin, String employeeId, String DateOfBirth) {
        if (this.pin.equals(pin) && this.employeeId.equals(employeeId) && this.DateOfBirth == DateOfBirth) {
            System.out.println("--------------------------------------------------------------");
            super.showDetails(DateOfBirth);
            System.out.println("\tEmployeeID : " + employeeId);
            System.out.println("\tSectionName : " + sectionName);
            System.out.println("\tDesignation  : " + designation);
            System.out.println("--------------------------------------------------------------");

        }
    }

    public String getuserId() {
        return this.pin;
    }

    public void checkDesignation(Staff s1, Staff s2) {
        if (s1.designation.equals(s2.designation)) {
            System.out.println("Same Designation!");
        } else {
            System.out.println("Different Designation!");
        }
    }

}

public class Assignment8 {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        Student[] student = new Student[100];
        Faculty[] faculty = new Faculty[100];
        Staff[] staff = new Staff[100];
        System.out.println("\t Welcome Sir! to IIITG DataBase");

        int i = 0, k = 0, l = 0;
        while (true) {
            System.out.println("--------------------------------------------------------------");
            System.out.println("\t\t1 - Faculty");
            System.out.println("\t\t2 - Student");
            System.out.println("\t\t3 - Staff");
            System.out.println("\t\t4 - Exit");
            System.out.println("--------------------------------------------------------------");
            System.out.print("Enter Your Choice : ");
            int choice = input.nextInt();
            input.nextLine();

            if (choice == 1) {
                System.out.println("--------------------------------------------------------------");
                System.out.println("\t\t0 - setvaluesByConstructor()");
                System.out.println("\t\t1 - setDetails()");
                System.out.println("\t\t2 - ShowDetails()");
                System.out.println("\t\t3 - displayDetails()");
                System.out.println("\t\t4 - compareDepartment()");
                System.out.println("--------------------------------------------------------------");

                System.out.print("Enter Your Choice : ");
                int choice1 = input.nextInt();
                input.nextLine();
                if (choice1 == 0) {
                    System.out.print("Enter First Name : ");
                    String firstName = input.nextLine();

                    System.out.print("Enter Last Name : ");
                    String lastName = input.nextLine();

                    System.out.print("Enter pan : ");
                    String pan = input.nextLine();

                    System.out.print("Enter Birth-Date : ");
                    String DateOfBirth = input.next();
                    input.nextLine();

                    System.out.println("Enter the Email: ");
                    String Email = input.next();

                    System.out.print("Enter User-Id : ");
                    String pin = input.nextLine();

                    System.out.print("Enter EmployeeId : ");
                    String employeeId = input.nextLine();

                    System.out.print("Enter DepartmentName : ");
                    String departmentName = input.nextLine();

                    System.out.print("Enter NoOfPublications : ");
                    int noOfPublications = input.nextInt();
                    input.nextLine();
                    Faculty object = new Faculty(firstName,lastName,DateOfBirth,pan,pin, employeeId, departmentName, noOfPublications,Email);
                    faculty[k] = object;
                    k++;
                } else if (choice1 == 1) {
                    Faculty object = new Faculty();
                    faculty[k] = object;
                    faculty[k].setDetails();
                    k++;
                } else if (choice1 == 2) {
                    System.out.print("Enter the Birth-date to get the details : ");
                    String year = input.next();
                    input.nextLine();

                    for (int j = 0; j < k; j++) {
                        faculty[j].showDetails(year);
                    }

                } else if (choice1 == 3) {
                    System.out.println("Enter User-Id,Employee-Id,Birth-date to display the detials");
                    String pin = input.nextLine();
                    String employeeId = input.nextLine();
                    String DateOfBirth = input.next();
                    input.nextLine();
                    for (int j = 0; j < k; j++) {
                        faculty[j].displayDetails(pin, employeeId, DateOfBirth);
                    }
                } else if (choice1 == 4) {
                    System.out.print("Enter User-Id of User 1 : ");
                    String id1 = input.nextLine();
                    System.out.print("Enter User-Id of User 2 : ");
                    String id2 = input.nextLine();

                    Faculty f1 = null, f2 = null;

                    for (int j = 0; j < k; j++) {
                        if (faculty[j] == null) {
                            continue;
                        }
                        if (id1.equals(faculty[j].getuserId())) {
                            f1 = faculty[j];
                        }
                    }
                    for (int j = 0; j < k; j++) {
                        if (faculty[j] == null) {
                            continue;
                        }

                        if (id2.equals(faculty[j].getuserId())) {
                            f2 = faculty[j];
                        }
                    }
                    if (f1 != null && f2 != null) {
                        f1.checkDepartment(f1, f2);
                    }

                } else {
                    System.out.println("Invalid Choice!");
                }

            } else if (choice == 2) {
                System.out.println("--------------------------------------------------------------");
                System.out.println("\t\t0 - setvaluesByConstructor()");
                System.out.println("\t\t1 - setDetails()");
                System.out.println("\t\t2 - showDetails()");
                System.out.println("\t\t3 - displayDetails()");
                System.out.println("--------------------------------------------------------------");

                System.out.print("Enter Your Choice : ");
                int choice1 = input.nextInt();
                input.nextLine();
                if (choice1 == 0) {


                    System.out.print("Enter first Name : ");
                    String firstName = input.nextLine();

                    System.out.print("Enter Last Name : ");
                    String lastName = input.nextLine();

                    System.out.print("Enter pan : ");
                    String pan = input.nextLine();

                    System.out.print("Enter Date of Birth : ");
                    String DateOfBirth = input.next();

                    System.out.print("Enter User-Id : ");
                    String pin = input.nextLine();

                    System.out.print("Enter Roll-No : ");
                    int rollno = input.nextInt();
                    input.nextLine();

                    System.out.println("Enter the Email: ");
                    String email = input.next();

                    System.out.print("Enter Semester : ");
                    int semester = input.nextInt();
                    input.nextLine();

                    System.out.print("Enter CPI : ");
                    float cpi = input.nextFloat();
                    input.nextLine();
                    Student object = new Student(firstName,lastName,DateOfBirth,pan, pin, rollno, semester, cpi,email);
                    student[i] = object;
                    i++;
                } else if (choice1 == 1) {
                    Student object = new Student();
                    student[i] = object;
                    student[i].setDetails();

                    i++;
                } else if (choice1 == 2) {
                    System.out.print("Enter the Birth-date to get the details : ");
                    String year = input.next();
                    for (int j = 0; j < i; j++) {
                        student[j].showDetails(year);
                    }

                } else if (choice1 == 3) {
                    System.out.println("Enter User-Id,Roll-No,Birth-date to display the detials");
                    String pin = input.nextLine();
                    int rollno = input.nextInt();
                    String DateOfBirth = input.next();
                    input.nextLine();
                    for (int j = 0; j < i; j++) {
                        student[j].displayDetails(pin, rollno, DateOfBirth);
                    }
                } else {
                    System.out.println("Invalid Choice!");
                }

            } else if (choice == 3) {
                System.out.println("--------------------------------------------------------------");
                System.out.println("\t\t0 - setvaluesByConstructor()");
                System.out.println("\t\t1 - setDetails()");
                System.out.println("\t\t2 - ShowDetails()");
                System.out.println("\t\t3 - displayDetails()");
                System.out.println("\t\t4 - compareDesignation()");
                System.out.println("--------------------------------------------------------------");

                System.out.print("Enter Your Choice : ");
                int choice1 = input.nextInt();
                input.nextLine();
                if (choice1 == 0) {
                    System.out.print("Enter first Name : ");
                    String firstName = input.nextLine();

                    System.out.print("Enter Last Name : ");
                    String lastName = input.nextLine();

                    System.out.print("Enter Date of Birth : ");
                    String DateOfBirth = input.next();
                    input.nextLine();


                    System.out.println("Enter the Email: ");
                    String email = input.next();

                    System.out.print("Enter pan : ");
                    String pan = input.nextLine();

                    System.out.print("Enter User-Id : ");
                    String pin = input.nextLine();

                    System.out.print("Enter Employee-Id : ");
                    String employeeId = input.nextLine();

                    System.out.print("Enter SectionName : ");
                    String sectionName = input.nextLine();

                    System.out.print("Enter Designation : ");
                    String designation = input.nextLine();

                    Staff object = new Staff(firstName,lastName,DateOfBirth,pan, pin, employeeId, sectionName, designation,email);
                    staff[l] = object;
                    l++;
                } else if (choice1 == 1) {
                    Staff object = new Staff();

                    staff[l] = object;
                    staff[l].setDetails();
                    l++;
                } else if (choice1 == 2) {
                    System.out.print("Enter the Birth-date to get the details : ");
                    String year = input.next();
                    input.nextLine();
                    for (int j = 0; j < l; j++) {
                        staff[j].showDetails(year);
                    }
                } else if (choice1 == 3) {
                    System.out.println("Enter User-Id,Employee-Id,Birth-date to display the detials");
                    String pin = input.nextLine();
                    String employeeId = input.nextLine();
                    String DateOfBirth = input.next();
                    input.nextLine();
                    for (int j = 0; j < l; j++) {
                        staff[j].displayDetails(pin, employeeId, DateOfBirth);
                    }
                } else if (choice1 == 4) {
                    System.out.print("Enter UserId of user 1 : ");
                    String id1 = input.nextLine();
                    System.out.print("Enter UserId of user 2 : ");
                    String id2 = input.nextLine();
                    Staff s1 = null, s2 = null;

                    for (int j = 0; j < l; j++) {
                        if (staff[j] == null) {
                            continue;
                        }
                        if (id1.equals(staff[j].getuserId())) {
                            s1 = staff[j];
                        }
                    }
                    for (int j = 0; j < l; j++) {
                        if (staff[j] == null) {
                            continue;
                        }

                        if (id2.equals(staff[j].getuserId())) {
                            s2 = staff[j];
                        }
                    }
                    if (s1 != null && s2 != null) {
                        s1.checkDesignation(s1, s2);
                    }
                }
                else {
                    System.out.println("Invalid Choice!");
                }
            }

            else if (choice == 4) {
                break;
            } else {
                System.out.println("Invalid Choice!");
            }
        }
        input.close();
    }
}