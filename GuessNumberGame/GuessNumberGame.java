import java.util.Random;
import java.util.Scanner;

public class GuessNumberGame {
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        String playAgain = "YES";

        System.out.println("\n===========================================");
        System.out.println("        WELCOME TO THE NUMBER GAME         ");
        System.out.println("===========================================\n");

        while (playAgain.equalsIgnoreCase("YES")) {
            Random rand = new Random();
            int randomNumber = rand.nextInt(100) + 1; 
            int guess = -1;
            int attempts = 0;

            System.out.println("I have selected a number between 1 and 100.");
            System.out.println("Try to guess it in the fewest attempts possible.\n");

            while (guess != randomNumber) {
                System.out.print("Enter your guess (1-100): ");

                // Input validation
                if (!reader.hasNextInt()) {
                    System.out.println("ERROR: Please enter a valid number between 1 and 100.\n");
                    reader.next(); 
                    continue;
                }

                guess = reader.nextInt();

                
                if (guess < 1 || guess > 100) {
                    System.out.println("ERROR: Number out of range! Please enter a number between 1 and 100.\n");
                    continue;
                }

                attempts++;

                if (guess < randomNumber) {
                    System.out.println("Too low. Try again.\n");
                } else if (guess > randomNumber) {
                    System.out.println("Too high. Try again.\n");
                } else {
                    System.out.println("\n===========================================");
                    System.out.println("    CONGRATULATIONS! YOU GUESSED RIGHT!    ");
                    System.out.println("===========================================");
                    System.out.println("The correct number was: " + randomNumber);
                    System.out.println("Total attempts: " + attempts);

                    if (attempts <= 5) {
                        System.out.println("Excellent performance! Well done.");
                    } else if (attempts <= 8) {
                        System.out.println("Good job! You have a sharp mind.");
                    } else {
                        System.out.println("You got it! Try to improve next time.");
                    }

                    System.out.println("\n===========================================\n");
                }
            }

            System.out.print("Would you like to play again? (YES/NO): ");
            playAgain = reader.next();
            System.out.println("\n-------------------------------------------\n");
        }

        System.out.println("Thank you for playing. Have a great day!");
        reader.close();
    }
}
