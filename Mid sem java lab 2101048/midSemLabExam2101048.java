import java.util.*;

class user {
    protected String userID;
    protected String Name;
    protected String dateOfBirth;
    protected String Address;
    protected String PAN;
    user() {}
    user(String userID,String Name,String dateOfBirth,String Address,String PAN) {
        this.userID = userID;
        this.Name = Name;
        this.dateOfBirth = dateOfBirth;
        this.Address = Address;
        this.PAN = PAN;
    }
}

class Admin extends user {
    protected String dateOfJoining;
    protected String salary;
    protected String permissibleOperations;

    Admin(String dateOfJoining , String salary,String permissibleOperations) {
        this.dateOfJoining = dateOfJoining;
        this.salary = salary;
        this.permissibleOperations = permissibleOperations;
    }
}
class General extends user {
    protected String dateOfJoining;
    protected String salary;
    protected String dutyHoursPerDay;

    General(String dateOfJoining , String salary,String dutyHoursPerDay) {
        this.dateOfJoining = dateOfJoining;
        this.salary = salary;
        this.dutyHoursPerDay = dutyHoursPerDay;
    }
}

class Item {
    protected String ItemCode;
    protected int price;
    protected int AvailableQty;
    Item() {}
    Item(String ItemCode,int price,int AvailableQty) {
        this.ItemCode = ItemCode;
        this.price = price;
        this.AvailableQty = AvailableQty;
    }
    public void addNewStock(Item it) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Item Code You want to add.:");
        ItemCode = sc.nextLine();
        System.out.println("Enter the Price of that Item: ");
        price = sc.nextInt();
        System.out.println("Enter the Available Quantity of Item:");
        AvailableQty = sc.nextInt();
    }
    // this should be called when quantity becomes zero.
    public void deleteStock(Item it) {
        it.ItemCode = null;
        it.AvailableQty = 0;
        it.price = 0;
    }
    public void modifyStock(Item it) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Item Code of the item");
        it.ItemCode = sc.nextLine();
        System.out.println("Enter the available Qty of the Item");
        it.AvailableQty = sc.nextInt();
        System.out.println("Enter the price of teh Item");
        it.price = sc.nextInt();
    }
    void display() {
        System.out.println("Price of the Item is: "+ price);
        System.out.println("Available Quantity of the Item is: " + AvailableQty);
        System.out.println("Code of the Item is: " + ItemCode);
    }
}
class FoodItem extends Item {
    protected String dateOfExpiry;
    FoodItem(String dateOfExpiry) {
        this.dateOfExpiry = dateOfExpiry;
    }
}
class NonFoodItem extends Item {
    protected String returnCount;
    NonFoodItem(String returnCount) {
        this.returnCount = returnCount;
    }
}

class Sell extends Item{
    protected String dateOfSell;
    protected String itemCode;
    protected int quantity;
    protected int totalAmount;

    Sell(String dateOfSell,String itemCode,int quantity , int totalAmount) {
        this.dateOfSell = dateOfSell;
        this.itemCode = itemCode;
        this.quantity = quantity;
        this.totalAmount = totalAmount;
    }
    public void sellItem(Item it,String ItemCode,int quantity) {
        if(this.quantity - quantity >= 0) {
            this.quantity -= quantity;
            if(this.quantity == 0) deleteStock(it);
        }
        else {
            System.out.println("WE don't have this much of quantity please reenter the quantity you want");
            return;
        }
    }
    public void displaySell(String startDate,String EndDate) {
        if(Integer.parseInt(this.dateOfSell) <= Integer.parseInt(EndDate) && Integer.parseInt(this.dateOfSell) >= Integer.parseInt(startDate)) {
            display();
        }
    }
}
class Return extends Item{
    protected String dateOfReturn;
    protected String itemCode;
    protected String quantity;
    protected String returnAmount;

    Return(String dateOfReturn,String itemCode,String quantity,String returnAmount) {
        this.returnAmount = returnAmount;
        this.itemCode = itemCode;
        this.quantity = quantity;
        this.returnAmount = returnAmount;
    }
    public void returnItem(Item it,String itemCode,int quantity) {
        it.AvailableQty += quantity;
    }
}

public class midSemLabExam2101048 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Item> Item_arr = new ArrayList<Item>();
        String temp = "Admin";
        if(temp.equals("Admin")) {
            ArrayList<Admin> arr = new ArrayList<Admin>();
            boolean isTrue = true;
            while(isTrue) {

                System.out.println("Enter the date of joining: ");
                String date = sc.nextLine();
                System.out.println("Enter the Salary of the Admin: ");
                String sal = sc.nextLine();
                System.out.println("Enter the permissible Operations: ");
                String ope = sc.nextLine();
                Admin ad = new Admin(date, sal, ope);
                arr.add(ad);

                System.out.println("Enter 1 to add Admins OR 0 to break");
                int choice = sc.nextInt();

                if(choice == 1) {
                    System.out.println("--------------------------------------------------------------");
                    System.out.println("\t\t1 - addNewStock");
                    System.out.println("\t\t2 - deleteStock");
                    System.out.println("\t\t3 - modifyStock");
                    System.out.println("\t\t4 - Exit");
                    System.out.println("--------------------------------------------------------------");
                    int choice1 = sc.nextInt();
                    if(choice1 == 1) {
                        Item it = new Item();
                        it.addNewStock(it);
                        Item_arr.add(it);
                    }
                    else if(choice1 == 2) {
                        System.out.println("Enter the itemCode of the Item");
                        String code = sc.nextLine();
                        for(int i = 0; i < Item_arr.size(); i++) {
                            if(Item_arr.get(i).ItemCode.equals(code)) {
                                Item_arr.get(i).deleteStock(Item_arr.get(i));
                            }
                        }
                    }
                    else if(choice == 3) {
                        System.out.println("Enter the itemCode of the Item");
                        String code = sc.nextLine();
                        for(int i = 0; i < Item_arr.size(); i++) {
                            if(Item_arr.get(i).ItemCode.equals(code)) {
                                Item_arr.get(i).modifyStock((Item_arr.get(i)));
                            }
                        }
                    }

                } else
                    break;
            }
        } else {
            ArrayList<General> arr = new ArrayList<General>();
            boolean isTrue = true;
            while(isTrue) {
                System.out.println("Enter 1 to add Admins OR 0 to break");
                int choice = sc.nextInt();

                if(choice == 1) {
                    System.out.println("Enter the date of joining: ");
                    String date = sc.nextLine();
                    System.out.println("Enter the Salary of the Admin: ");
                    String sal = sc.nextLine();
                    System.out.println("Enter the permissible Operations: ");
                    String ope = sc.nextLine();
                    General ad = new General(date, sal, ope);
                    arr.add(ad);
                } else
                    break;
            }
        }
    }
}
