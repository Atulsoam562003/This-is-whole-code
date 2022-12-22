import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Scanner;

class Student implements Serializable {

  private String firstName;
  private String lastName;
  private Integer rollNumber;
  private Integer cpi;
  private Integer age;

  Student(
      String firstName,
      String lastName,
      Integer rollNumber,
      Integer cpi,
      Integer age) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.rollNumber = rollNumber;
    this.cpi = cpi;
    this.age = age;
  }

  public String getFirstName() {
    return firstName;
  }

  public String getLastName() {
    return lastName;
  }

  public Integer getRollNumber() {
    return rollNumber;
  }

  public Integer getCPI() {
    return cpi;
  }

  public Integer getAge() {
    return age;
  }
}

class endOfFile implements Serializable {

  /**
   *
   */
  public endOfFile() {
  }
}

public class Assignment10Records {

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    String filename = "Student.ser";
    FileOutputStream file = new FileOutputStream(filename);
    ObjectOutputStream output = new ObjectOutputStream(file);
    // ArrayList<Student> ar1 = new ArrayList<Student>(10);
    Student[] arr = new Student[10];
    try {
      for (int i = 0; i < 10; i++) {
        System.out.println("Student #" + (i + 1) + ":");
        System.out.print("Enter first name: ");
        String fname = sc.next();
        System.out.print("Enter last name: ");
        String lname = sc.next();
        Integer rno = i + 1;
        System.out.print("Enter age: ");
        Integer cpi = sc.nextInt();
        System.out.print("Enter cpi: ");
        Integer age = sc.nextInt();
        arr[i] = new Student(fname, lname, rno, cpi, age);
        output.writeObject(arr[i]);
      }
      output.writeObject(new endOfFile());
      output.close();
      file.close();
      sc.close();
    } catch (IOException e) {
      System.out.println("IO Error detected");
    } catch (Exception e) {
      System.out.println("Error");
    }
    FileInputStream file1 = new FileInputStream(filename);
    ObjectInputStream obj = new ObjectInputStream(file1);
    Object obj1 = null;
    try {
      while ((obj1 = obj.readObject()) instanceof endOfFile == false) {
        {
          System.out.print(((Student) obj1).getRollNumber() + " ");
          System.out.print(((Student) obj1).getFirstName() + " ");
          System.out.print(((Student) obj1).getLastName() + " ");
          System.out.print(((Student) obj1).getAge() + " ");
          System.out.print(((Student) obj1).getCPI() + "\n");
        }
      }
      obj.close();
    } catch (Exception e) {
      System.out.println("Error");
    }
  }
}
