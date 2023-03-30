import java.util.Scanner;  // Import the Scanner class

class age {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        double ageDbl=input.nextDouble();
        int ageInt=(int)ageDbl;
        System.out.println("hello my age is "+ageInt);
        //System.out.println(ageInt);
    }
}