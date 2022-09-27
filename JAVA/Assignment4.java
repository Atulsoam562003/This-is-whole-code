import java.util.Scanner;

public class Assignment4 {
    public static class account {
        private int accountNumber,customerID,totalAccountCreated;
        private float minimumBalance,availableBalance;
        private String accountType,serviceBranchIFSC,customerName;
        account() {
            accountNumber = 0;
            customerID = 0;
            minimumBalance = 0;
            availableBalance = 0;
            accountType = null;
            serviceBranchIFSC = null;
            customerName = null;
        }
        public void setDetails(int accountNumber,int customerID,float minimumBalance,float availableBalance,String accountType,String serviceBranchIFSC,String customerName) {
            this.accountNumber = accountNumber;
            this.customerID = customerID;
            this.totalAccountCreated++;
            this.minimumBalance = minimumBalance;
            this.availableBalance = availableBalance;
            this.accountType = accountType;
            this.serviceBranchIFSC = serviceBranchIFSC;
            this.customerName = customerName;
        }
        public String getDetails(int accountNumber) {
            String temp = Integer.toString(this.accountNumber);
            return temp;
        }
        public void updateDetails(int accountNumber) {
            this.accountNumber = accountNumber;
        }
        public void deposit(int accountNumber,int amount) {
            this.accountNumber = accountNumber;
            availableBalance += amount;
        }
        public float withdraw(int accountNumber,float amount) {
            if(availableBalance - amount < minimumBalance) {
                System.out.println("YOU can not withdraw the money");
                return -1;
            }
            availableBalance -= amount;
            System.out.println("now money left is:");
            System.out.println(availableBalance);
            return availableBalance;
        }
        public int totalAccount() {
            return totalAccountCreated;
        }
        public void display(account Ac1) {
            System.out.printf("account No: ");
            System.out.println(accountNumber);
            System.out.printf("customerID ");
            System.out.println(customerID);
            System.out.printf("minimum Balance: ");
            System.out.println(minimumBalance);
            System.out.printf("account Type: ");
            System.out.println(accountType);
            System.out.printf("serviceBranch IFSC: ");
            System.out.println(serviceBranchIFSC);
            System.out.printf("customer Name: ");
            System.out.println(customerName);
        }
        public void getBalance(account ac) {
            System.out.println(ac.availableBalance);
        }

        public void compare(account Ac1,account Ac2) {
            if(Ac1.availableBalance > Ac2.availableBalance) display(Ac1);
            else display(Ac2);
        }

    }

    public static void main(String[] args) {
        // ArrayList<Integer> arr = new ArrayList<Integer>(10);
        account [] arr = new account [10];
        for (int i = 0; i < arr.length; i++) arr[i] = new account();

        int temp = 1;
        boolean flag = true;
        int accountNumber,customerID;
        float minimumBalance,availableBalance;
        String accountType,serviceIFSC,customerName;
        int i = 0;

        Scanner sc = new Scanner(System.in);
        int index = 0;
        while(flag && i < arr.length) {
            System.out.println("Enter the 1 to enter values or 0 to break");
            temp = sc.nextInt();
            switch (temp) {
                case 1:
                    System.out.println("Enter the AccountNO:");
                    accountNumber = sc.nextInt();
                    System.out.println("Enter the customerID:");
                    customerID = sc.nextInt();
                    System.out.println("Enter the accountType:");
                    accountType = sc.next();
                    System.out.println("Enter the service branch");
                    serviceIFSC = sc.next();
                    System.out.println("Enter the customerName");
                    customerName = sc.next();
                    System.out.println("Enter the minimum balance:");
                    minimumBalance = sc.nextFloat();
                    System.out.println("Enter the minimum total balance:");
                    availableBalance = sc.nextFloat();
                    arr[i].setDetails(accountNumber,customerID,minimumBalance,availableBalance,accountType,serviceIFSC,customerName);
                    i++;
                    break;

                case 0:
                    flag = false;
                    index = i;
                    break;
            }
        }

        for(int j = 0; j <= index; j++) {
            arr[0].display(arr[i]);
            System.out.println();
        }
        System.out.println("If you want to deposit please tell the index of object");
        int ind = 0;
        ind = sc.nextInt();
        System.out.println("Enter the amount");
        int price = 0;
        price = sc.nextInt();
        arr[ind].deposit(13144241, price);
        // System.out.println("tell the index of object you want to update the details");
        // ind = sc.nextInt();
        // int accType = 0,accountN = 0;
        // String customerN;
        // System.out.println("enter the account type");
        // accType = sc.nextInt();
        // System.out.println("enter the account N");
        // accountN = sc.nextInt();
        // System.out.println("enter the custotmer");
        // customerID = sc.next();
        // arr[ind].updateDetails(accountN,accType,customerID);
        // System.out.println("tell the index of object you want to getDetails");
        // ind = sc.nextInt();
        // arr[ind].display(arr[ind]);
        // System.out.println("tell the index of object you want to getBalance");
        // ind = sc.nextInt();
        // arr[ind].getBalance(arr[ind]);

        // System.out.println("tell the index of object you want to withdraw");
        // ind = sc.nextInt();
        // arr[ind].withdraw(131414, 12);
        // System.out.println("TOTAL no of account created");
        // System.out.println(arr[0].totalAccountCreated);

        int i1 = 0,i2 = 1;
        System.out.println("Enter the index of the 2 object you want to compare");
        i1 = sc.nextInt();
        i2 = sc.nextInt();
        arr[0].compare(arr[i1], arr[i2]);
        sc.close();
    }
}
