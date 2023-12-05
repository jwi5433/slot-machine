#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class SlotMachine {
private:
    std::vector<std::string> symbols; 
    int credits;
    bool isBonusSpin;


public:
    SlotMachine() : credits(1000), isBonusSpin(false) {
        symbols = { "Cherry", "Bell", "Lemon", "Orange", "Star", "Skull" };
    }

    void spin(int bet) {
        if (isBonusSpin) {
            std::cout << "Bonus Spin!" << std::endl;
            bet = 0;
            isBonusSpin = false;
        } else if (bet > credits) {
            std::cout << "Not enough credits." << std::endl;
            return;
        }

        credits -= bet;
        std::string reel1 = symbols[rand() % symbols.size()];
        std::string reel2 = symbols[rand() % symbols.size()];
        std::string reel3 = symbols[rand() % symbols.size()];

        std::cout << reel1 << " - " << reel2 << " - " << reel3 << std::endl;

        if (reel1 == "Star" || reel2 == "Star" || reel3 == "Star") {
            isBonusSpin = true;
        }
        
        if (reel1 == reel2 && reel2 == reel3) {
            std::cout << "Jackpot!" << std::endl;
            credits += bet * 3;
        }
        else if (reel1 == reel2 || reel2 == reel3 || reel3 == reel1) {
            std::cout << "Winner!" << std::endl;
            credits += bet * 2;
        }
        else {
            std::cout << "Try again." << std::endl;
        }
        if (reel1 == "Star" || reel2 == "Star" || reel3 == "Star") {
            isBonusSpin = true;
            std::cout << "You've earned a bonus spin!" << std::endl;
        }

        std::cout << "Credits: " << credits << std::endl;
    }
};
    

int main() {
    srand(time(0));

    SlotMachine mySlotMachine;
    char input;
    int bet;

    do {
        std::cout << "Press 's' to spin or 'q' to quit: ";
        std::cin >> input;

        if (input == 's') {
            std::cout << "Enter bet amount: ";
            std::cin >> bet;
            mySlotMachine.spin(bet);
        }
    } while (input != 'q');

    return 0;
    
}
