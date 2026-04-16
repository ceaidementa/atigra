#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayHangman(int wrongCount) {
    vector<string> stages = {
        // Stage 0: Empty
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
        
        // Stage 3: Left Arm
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " \\|   |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        // Stage 4: Right Arm
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " \\|/  |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        // Stage 5: Left Leg
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " \\|/  |\n"
        " /    |\n"
        "      |\n"
        "=========",
        
        // Stage 6: Right Leg (DEAD)
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " \\|/  |\n"
        " / \\  |\n"
        "      |\n"
        "========="
    };
    
    cout << stages[wrongCount] << endl;
}

int main() {
    srand(time(0));
    
    // Lista de cuvinte
    vector<string> words = {"programare", "calculator", "C++", "variabila", "functie"};
    
    // Alege un cuvânt aleatoriu
    string secret = words[rand() % words.size()];
    string guessed(secret.length(), '_');
    
    int tries = 6;
    vector<char> wrongGuesses;
    
    cout << "Bine ai venit la Spanzuratoare" << endl;
    cout << "Cuvantul are " << secret.length() << " litere." << endl << endl;
    
    // Jocul principal
    while (tries > 0 && guessed != secret) {
        int wrongCount = 6 - tries;
        displayHangman(wrongCount);
        
        cout << "Cuvant: " << guessed << endl;
        cout << "Incercari ramase: " << tries << endl;
        cout << "Litere gresite: ";
        for (char c : wrongGuesses) {
            cout << c << " ";
        }
        cout << endl << "Ghiceste o litera: ";
        
        char guess;
        cin >> guess;
        
        // Verifică dacă litera e în cuvânt
        bool found = false;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess) {
                guessed[i] = guess;
                found = true;
            }
        }
        
        if (!found) {
            tries--;
            wrongGuesses.push_back(guess);
            cout << "Gresit!" << endl << endl;
        } else {
            cout << "Corect!" << endl << endl;
        }
    }
    
    // Rezultat final
    if (guessed == secret) {
        cout << "🎉 Felicitari! Ai ghicit cuvantul: " << secret << endl;
    } else {
        cout << "😢 Game Over! Cuvantul era: " << secret << endl;
    }
    
    return 0;
}