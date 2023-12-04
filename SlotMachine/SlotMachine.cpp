#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class SlotMachine {
private:
    std::vector<std::string> symbols; 
    int credits;


public:
    SlotMachine() : credits(1000) {
        symbols = { "Cherry", "Bell", "Lemon", "Orange", "Star", "Skull" };
    }

    void spin(int bet) {
        if (bet > credits) {
            std::cout << "Not enough credits." << std::endl;
            return;
        }

        credits -= bet;
        std::string reel1 = symbols[rand() % symbols.size()];
        std::string reel2 = symbols[rand() % symbols.size()];
        std::string reel3 = symbols[rand() % symbols.size()];

        std::cout << reel1 << " - " << reel2 << " - " << reel3 << std::endl;

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
