import java.util.Random;
import java.util.Scanner;

public class RockPaperScissors {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        String[] choices = {"Rock", "Paper", "Scissors"};
        String line = "===================================";

        System.out.println("\033[1;34m" + line);
        System.out.println("        ROCK - PAPER - SCISSORS");
        System.out.println(line + "\033[0m");

        while (true) {
            
            System.out.print("\n\033[1;32m[ Choose: Rock | Paper | Scissors ]\nEnter your choice: \033[0m");
            String userChoice = scanner.nextLine().trim().toLowerCase();

            if (userChoice.equals("exit")) {
                System.out.println("\n\033[1;31mGame Over! Thank you for playing.\033[0m");
                break;
            }

            
            if (!userChoice.equals("rock") && !userChoice.equals("paper") && !userChoice.equals("scissors")) {
                System.out.println("\033[1;31mInvalid choice! Please enter Rock, Paper, or Scissors.\033[0m");
                continue;
            }

            
            int computerIndex = random.nextInt(3);
            String computerChoice = choices[computerIndex];

            
            System.out.println("\n\033[1;34mYou chose: " + capitalize(userChoice));
            System.out.println("Computer chose: " + computerChoice + "\033[0m");

            
            String result = determineWinner(userChoice, computerChoice.toLowerCase());
            System.out.println("\033[1;33m" + result + "\033[0m");

            System.out.println("\n\033[1;35m" + line + "\033[0m"); // Stylish separator
        }

        scanner.close();
    }


    private static String determineWinner(String user, String computer) {
        if (user.equals(computer)) {
            return "It's a Tie!";
        } else if ((user.equals("rock") && computer.equals("scissors")) ||
                   (user.equals("paper") && computer.equals("rock")) ||
                   (user.equals("scissors") && computer.equals("paper"))) {
            return "You Win!";
        } else {
            return "Computer Wins!";
        }
    }


    private static String capitalize(String word) {
        return word.substring(0, 1).toUpperCase() + word.substring(1);
    }
}
