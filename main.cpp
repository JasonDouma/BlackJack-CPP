#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

long double BetAmount;
long double Winnings;
bool is_in_round = false;
int PlayerAmount = 1;
int HouseAmount;
std::string Option;
std::string Restart_Game_Option;
int randNum = rand() % 11 + 1;

void restart_game() {

    std::time_t currentTime = std::time(nullptr);
    std::srand(static_cast<unsigned int>(currentTime));

    if (PlayerAmount < HouseAmount) {
        std::cout << "You Have Went Bust! Do You Want To Play Again? y/n" << std::endl;
        HouseAmount = rand() % 11 + 1;
        PlayerAmount = 1;
        std::cin >> Restart_Game_Option;
    }
    if (PlayerAmount > HouseAmount) {
        std::cout << "Do You Want To Play Again? y/n" << std::endl;
        HouseAmount = 0;
        PlayerAmount = 1;
        std::cin>> Restart_Game_Option;
    }
    if (PlayerAmount == 21) {
        std::cout << "Do You Want To Play Again? y/n" << std::endl;
        HouseAmount = 0;
        PlayerAmount = 1;
        std::cin >> Restart_Game_Option;
    }

    if (Restart_Game_Option == "y") {
        PlayerAmount = 1;
        is_in_round = true;
    } else {
        is_in_round = false;
    }
}

void main_Game() {
    is_in_round = true;

    while (is_in_round) {
        Sleep(2);

        std::cout << "\n";
        std::cout << "======" << std::endl;
        std::cout << "\n";
        std::cout << "Player: " << PlayerAmount << std::endl;
        std::cout << "House: " << HouseAmount << std::endl;
        std::cout << "\n";
        std::cout << "====== \n";
        std::cout << "\n";
        std::cout << "You Have: " << PlayerAmount << " And The House Has: " << HouseAmount << "!" << std::endl;
        std::cout << "Options: Hit, Stand, Double" << std::endl;
        std::cout << "h, s, d" << std::endl;
        std::cout << "\n";
        std::cout << "====== \n";
        std::cout << "\n";
        std::cin >> Option;

        if (Option == "h") {
            int randNum = rand() % 11 + 1;
            PlayerAmount += randNum;
            std::cout << "You Now Have: " << PlayerAmount << "!" << std::endl;

            if (PlayerAmount > 21) {
                std::cout << "\n";
                std::cout << "====== \n";
                std::cout << "\n";
                std::cout << "You Got " << PlayerAmount << " You Went Bust!" << std::endl;
                restart_game();
            } else if (PlayerAmount == 21) {
                std::cout << "You Got BlackJack!!!" << std::endl;
                std::cout << "\n";
                std::cout << "======\n";
                std::cout << "\n";
                restart_game();
            }
        } else if (Option == "s") {
            std::cout << "\n";
            std::cout << "======\n";
            std::cout << "\n";
            std::cout << "You Have Stood At " << PlayerAmount << "!" << std::endl;
            std::cout << "The Dealer Is Now Playing..." << std::endl;
            std::cout << "\n";
            std::cout << "======\n";
            std::cout << "\n";
            while (HouseAmount < 17) {
                randNum = rand() % 11 + 1;
                HouseAmount += randNum;
                std::cout << "The Dealer Is Now At: " << HouseAmount << "!" << std::endl;
                if (HouseAmount > 17) {
                    break;
                }
            }
            if (HouseAmount > 21) {
                std::cout << "\n";
                std::cout << "======\n";
                std::cout << "\n";
                Winnings = BetAmount * 2;
                std::cout << "The Dealer Went Bust At " << HouseAmount << "!" << std::endl;
                std::cout << "You Won: $" << Winnings << "!" << std::endl;
                std::cout << "\n";
                std::cout << "======\n";
                std::cout << "\n";
                break;
            }
            if (HouseAmount > PlayerAmount){
                if (HouseAmount < 21){
                    std::cout << "\n";
                    std::cout << "======\n";
                    std::cout << "\n";
                    std::cout << "The Dealer Got More Than You!" << std::endl;
                    std::cout << "You Lose!" << std::endl;
                    std::cout << "You: " << PlayerAmount << "\nHouse: " << HouseAmount << std::endl;
                    std::cout << "\n";
                    std::cout << "======\n";
                    std::cout << "\n";
                    restart_game();
                    }
                }
            if (HouseAmount == PlayerAmount) {
                std::cout << "\n";
                std::cout << "======\n";
                std::cout << "\n";
                std::cout << "You And The Dealer Got A Push!" << std::endl;
                std::cout << "You: " << PlayerAmount << "\nHouse: " << HouseAmount << "!" << std::endl;
                std::cout << "\n";
                std::cout << "======\n";
                std::cout << "\n";
                restart_game();
                }
            if (PlayerAmount > HouseAmount) {
                std::cout << "\n";
                std::cout << "======\n";
                std::cout << "\n";
                std::cout << "You Won!" << std::endl;
                std::cout << "You Got: " << PlayerAmount << "\nDealer Got: " << HouseAmount << std::endl;
                Winnings = BetAmount *2;
                std::cout << "You Have Won: $" << Winnings << "!" << std::endl;
                restart_game();
            }
        } else if (Option == "d") {
            randNum = rand() % 10 + 1;
            PlayerAmount += randNum;
            std::cout << "You Doubled Down And Got: " << PlayerAmount << "!" << std::endl;
            if (PlayerAmount == 21) {
                std::cout << "You Got Blackjack!" << std::endl;
                restart_game();
            }
            if (PlayerAmount > 21) {
                std::cout << "You Doubled Down And Lost With: " << PlayerAmount << "!" << std::endl;
                restart_game();
            }
            randNum = rand() % 11 + 1;
            HouseAmount += randNum;
            std::cout << "\n";
            std::cout << "======\n";
            std::cout << "\n";
            std::cout << "The Dealer Is Now Playing!" << std::endl;
            std::cout << "The Dealer Is Now At: " << HouseAmount << "!" << std::endl;
            while (HouseAmount < 17) {
                randNum = rand() % 11 + 1;
                HouseAmount += randNum;
                std::cout << "The Dealer Is Now At: " << HouseAmount << "!" << std::endl;
                if (HouseAmount > 17) {
                    break;
                }
            }
            if (HouseAmount > 21) {
                std::cout << "Dealer Went Bust You Win!" << std::endl;
                Winnings = BetAmount*2;
                std::cout << "You Have Won: $" << Winnings << "!" << std::endl;
                restart_game();
            }
            if (HouseAmount > PlayerAmount) {
                std::cout << "Dealer Wins You Lost!" << std::endl;
                std::cout << "Dealer Got: " << HouseAmount << "\nYou Got: " << PlayerAmount<< std::endl;
                restart_game();
            }
            if (PlayerAmount > HouseAmount) {
                std::cout << "You Got More Than The Dealer You Win!" << std::endl;
                std::cout << "Dealer Got: "<< HouseAmount << "\nYou Got: " << PlayerAmount << "!" << std::endl;
                restart_game();
            }
            std::cout << "\n";
            std::cout << "======\n";
            std::cout << "\n";
            restart_game();
        }
    }
}

int main() {
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 2);
    std::cout << "\n";
    std::cout << "====== \n";
    std::cout << "\n";
    std::cout << "Welcome To Blackjack - V1" << std::endl;
    std::cout << "\n";
    std::cout << "======" << std::endl;
    std::cout << "\n";
    std::cout << "RULES: \n";
    std::cout << "\n";
    std::cout << "Single Player \n";
    std::cout << "One Deck \n";
    std::cout << "Reshuffle Every Round \n";
    std::cout << "House Hits Below 17 \n";
    std::cout << "21 Is Blackjack \n";
    std::cout << "No Specialized Rules " << std::endl;
    std::cout << "No Splitting Just Doubling \n";
    std::cout << "You Always Start At 1\n";
    std::cout << "\n";
    std::cout << "======" << std::endl;
    std::cout << "\n";

    std::cout << "How Much Would You Like To Bet This Round: " << std::endl;
    std::cin >> BetAmount;

    while (PlayerAmount == 0) {
        restart_game();
    }

    main_Game();

    return 0;
}
