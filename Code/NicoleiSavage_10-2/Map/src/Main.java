import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) throws Exception {
        Map<String, Month> monthMap = new HashMap<>();

        monthMap.put("January", new Month(31, Arrays.asList("New Year's Day"), "Garnet"));
        monthMap.put("February", new Month(28, Arrays.asList("Valentine's Day"), "Amethyst"));
        monthMap.put("March", new Month(31, Arrays.asList("St. Patrick's Day"), "Aquamarine"));
        monthMap.put("April", new Month(30, Arrays.asList("April Fool's Day"), "Diamond"));
        monthMap.put("May", new Month(31, Arrays.asList("May Day"), "Emerald"));
        monthMap.put("June", new Month(30, Arrays.asList("Father's Day"), "Pearl"));
        monthMap.put("July", new Month(31, Arrays.asList("Independence Day"), "Ruby"));
        monthMap.put("August", new Month(31, Arrays.asList("null"), "Peridot"));
        monthMap.put("September", new Month(30, Arrays.asList("Labor Day"), "Sapphire"));
        monthMap.put("October", new Month(31, Arrays.asList("Halloween"), "Opal"));
        monthMap.put("November", new Month(30, Arrays.asList("Thanksgiving"), "Topaz"));
        monthMap.put("Decemeber", new Month(31, Arrays.asList("Christmas"), "Zircon"));

        Scanner input = new Scanner(System.in);
        System.out.println("Select a month: ");
        String inputKey = input.nextLine();

        Month monthData = monthMap.get(inputKey);
        System.out.println("");
        System.out.println("Number of Days -> " + monthData.getNumOfDays());
        System.out.println("A holiday in th month -> " + monthData.getHolidays());
        System.out.println("Month birthstone -> " + monthData.getBirthstone());

        input.close();


    }
}
