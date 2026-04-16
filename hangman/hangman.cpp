#include <iostream>  // For input/output (cout, cin)
#include <string>    // For working with strings
#include <vector>    // For vectors (dynamic lists)
#include <cstdlib>   // For rand() function (random numbers)
#include <ctime>     // For time() function (random seed)

using namespace std;  // Use std namespace so we don't have to write std:: before every cout/cin

// Function that draws the hangman stage based on the number of wrong guesses
void displayHangman(int wrongCount) {
    // Vector with 7 different hangman drawings, from empty (0) to complete (6)
    vector<string> stages = {
        // Stage 0: Empty gallows only
        "  +---+\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        // Stage 1: Head
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        // Stage 2: Body
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        // Stage 3: Left arm
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " \\|   |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        // Stage 4: Right arm
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " \\|/  |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        // Stage 5: Left leg
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " \\|/  |\n"
        " /    |\n"
        "      |\n"
        "=========",
        
        // Stage 6: Right leg (LOST)
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " \\|/  |\n"
        " / \\  |\n"
        "      |\n"
        "========="
    };
    
    // Display the stage corresponding to the number of wrong guesses
    cout << stages[wrongCount] << endl;
}

int main() {
    srand(time(0));  // Seed for random numbers (using current time)
    
    // List of words to choose the secret from
    vector<string> words = {"programare", "calculator", "C++", "variabila", "functie", 
                            "algoritm", "internet", "software", "hardware", "database",
                            "securitate", "criptografie", "interfata", "monitor", "procesator",
                            "memoria", "tastatura", "mouse", "imprimanta", "scaner",
                            "telefon", "pereche", "carnet", "scaun", "masa", "biblioteka",
                            "dinamica", "structura", "iteratie", "recursie", "compilator",
                            "debug", "eroare", "succes", "integrare", "migrare",
                            "implementare", "documentatie", "testare", "optimizare", "scalabilitate"};
    
    // Choose a random word from the list
    string secret = words[rand() % words.size()];  // rand() % size = random index between 0 and size-1
    string guessed(secret.length(), '_');  // Create a string with underscores (like "_____" for each unknown letter)
    
    int tries = 6;  // The number of attempts the player has
    vector<char> wrongGuesses;  // Vector to store the wrong letters
    
    cout << "Bine ai venit la Spanzuratoare" << endl;  // Welcome message
    cout << "Cuvantul are " << secret.length() << " litere." << endl << endl;  // Show the length of the secret word
    
    // MAIN GAME LOOP - repeats until the player loses or wins
    while (tries > 0 && guessed != secret) {
        int wrongCount = 6 - tries;  // Calculate the hangman stage (0-6)
        displayHangman(wrongCount);  // Draw the hangman
        
        cout << "Cuvant: " << guessed << endl;  // Show the word with guessed letters revealed
        cout << "Incercari ramase: " << tries << endl;  // Show how many attempts are left
        cout << "Litere gresite: ";  // Show the wrong letters so far
        for (char c : wrongGuesses) {  // Loop through the vector of wrong letters
            cout << c << " ";  // Display each wrong letter
        }
        cout << endl << "Ghiceste o litera: ";  // Ask the player for a letter
        
        char guess;  // Variable to store the guessed letter
        cin >> guess;  // Read the letter entered by the player
        
        // Check if the entered letter is in the secret word
        bool found = false;  // Variable to check if the letter is found
        for (size_t i = 0; i < secret.length(); i++) {  // Loop through each letter in the secret word
            if (secret[i] == guess) {  // If the letter from secret matches the guess
                guessed[i] = guess;  // Reveal the letter in the guessed word
                found = true;  // Mark that the letter was found
            }
        }
        
        // Check if the letter was found or not
        if (!found) {  // If the letter was NOT found
            tries--;  // Subtract one attempt
            wrongGuesses.push_back(guess);  // Add the letter to the mistakes list
            cout << "Gresit!" << endl << endl;  // Error message
        } else {  // The letter was found
            cout << "Corect!" << endl << endl;  // Success message
        }
    }
    
    // FINAL RESULT - check if the player won or lost
    if (guessed == secret) {  // If the guessed word is identical to the secret
        cout << "🎉 Felicitari! Ai ghicit cuvantul: " << secret << endl;  // Victory message
    } else {  // Otherwise, the player lost
        cout << "😢 Game Over! Cuvantul era: " << secret << endl;  // Defeat message and correct answer
    }
    
    return 0;  // Close the program successfully
}