import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws Exception {
        System.out.println("");
        Scanner key = new Scanner(System.in);
        System.out.print("Enter a word: ");
        String input = key.nextLine().toLowerCase();
        boolean isPalindrome = true;
        Stack<Character> stack = new Stack<>();
        Queue<Character> queue = new LinkedList<>();

        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            stack.push(c);
            queue.add(c);
        }

        for (int i = 0; i < input.length(); i++) {
            if (stack.peek() != queue.peek()) {
                System.out.println("This is not a palindrome.");
                isPalindrome = false;
                break;
            }
            stack.pop();
            queue.remove();
        }
        if(isPalindrome){
            System.out.println("This is a palindrome!");
        }
        System.out.println("");
        key.close();

    }
}
