import java.util.Arrays;
import java.util.List;

public class Month {
    private int numOfDays;
    private List<String> holidays;
    private String birthstone;
    
    public Month() {
        numOfDays = 0;
        holidays = Arrays.asList("");
        birthstone = "";

    }

    public Month(int numOfDays, List<String> holidays, String birthstone) {
        this.numOfDays = numOfDays;
        this.holidays = holidays;
        this.birthstone = birthstone;
    }

    public int getNumOfDays() {
        return numOfDays;
    }
    public void setNumOfDays(int numOfDays) {
        this.numOfDays = numOfDays;
    }
    public List<String> getHolidays() {
        return holidays;
    }
    public void setHolidays(List<String> holidays) {
        this.holidays = holidays;
    }
    public String getBirthstone() {
        return birthstone;
    }
    public void setBirthstone(String birthstone) {
        this.birthstone = birthstone;
    }
}
