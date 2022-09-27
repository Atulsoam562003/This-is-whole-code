import java.util.Scanner;

public class Assignment3 {
    public static class LibManagementSystem {
        private int bookId,totalCopies,yearOfPublication,numberOfAvailableCopies;
        private String bookTitle,authorName,publisherName;

        LibManagementSystem() {}
        LibManagementSystem(int totalCopy) {
            totalCopies = totalCopy;
        }
        public void setDetails(int id,String title,int year,String author,String publisher,int cnt) {
            bookId = id;
            bookTitle = title;
            yearOfPublication = year;
            authorName = author;
            publisherName = publisher;
            totalCopies = numberOfAvailableCopies = cnt;
        }
        public void getDetails() {
            System.out.printf("bookTitle: ");
            System.out.println(bookTitle);
            System.out.printf("year: ");
            System.out.println(yearOfPublication);
            System.out.printf("author: ");
            System.out.println(authorName);
            System.out.printf("publisher: ");
            System.out.println(publisherName);
            System.out.printf("totalCopies: ");
            System.out.println(totalCopies);
            System.out.printf("Number of Copies left: ");
            System.out.println(numberOfAvailableCopies);
        }
        public int Return(LibManagementSystem temp) {
            return this.bookId;
        }
        public int Issue(LibManagementSystem tp) {
            return this.bookId;
        }

    }
    public static void main(String[] args) {
        LibManagementSystem [] arr = new LibManagementSystem[10];
        for (int i = 0; i < arr.length; i++) arr[i] = new LibManagementSystem();
        int temp = 1;
        boolean flag = true;
        int id,year,cnt;
        String title,author,publisher;

        int i = 0;
        Scanner sc = new Scanner(System.in);
        while(flag && i < arr.length) {
            System.out.println("Enter the val of temp");
            temp = sc.nextInt();
            switch (temp) {
                case 1:
                    System.out.println("Enter the id:");
                    id = sc.nextInt();
                    System.out.println("Enter the Title");
                    title = sc.next();
                    System.out.println("Enter the Year:");
                    year = sc.nextInt();
                    System.out.println("Enter the author");
                    author = sc.next();
                    System.out.println("Enter the publisher");
                    publisher = sc.next();
                    System.out.println("Enter the count:");
                    cnt = sc.nextInt();
                    arr[i].setDetails(id, title, year, author, publisher, cnt);
                    i++;
                    break;

                case 0:
                    flag = false;
                    break;
            }
        }
        System.out.println("Give the index of the Book which you want to return");
            int index = sc.nextInt();
            index = arr[index].Return(arr[index]);

            for(int j = 0 ; j < arr.length; j++) {
                if(arr[j].bookId == index) {
                    arr[j].numberOfAvailableCopies++;
                    arr[j].totalCopies++;
                }
            }

            System.out.println("Tell me index of the book you want to issue:");
            index = sc.nextInt();
            index = arr[index].Issue(arr[index]);

            for(int k = 0; k < arr.length; k++) {
                if(arr[k].bookId == index) {
                    arr[k].numberOfAvailableCopies--;
                    arr[k].totalCopies--;
                }
            }
        sc.close();
        for(int k = 0; k < arr.length; k++) {
            arr[i].getDetails();
        }
    }
}
