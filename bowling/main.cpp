#include <cstring>
#include <iostream>
#include "Game.hpp"

void printHelp() {
    std::cout << "\t******   BOWLING GAME    ******\n";
    std::cout << "Type to execute:\t";
    std::cout << "./bowling DIRECTORY [FILE]\n";
    std::cout << "\tDIRECTORY  \t-directory which contains input files for game\n";
    std::cout << "\t[FILE]  \t-optional file to save results of game\n";
    std::cout << "example of use:  ./bowling inputDirectory results.txt\n";
}

int main(int argc, char* argv[]) {
    std::string inputDirectoryName;
    std::string resultOutputFileName;
    try {
        if ((argc == 2 && strcmp(argv[1], "--help") == 0) || strcmp(argv[1], "-h") == 0) {
            printHelp();
        } else if (argc == 2) {
            inputDirectoryName = argv[1];
            Game game{inputDirectoryName};
            game.printInputData();
            game.printResults();
        } else if (argc == 3) {
            inputDirectoryName = argv[1];
            resultOutputFileName = argv[2];
            std::cout << inputDirectoryName << '\t' << resultOutputFileName << '\n';
            //Game game{inputDirectoryName,resultOutputFileName };
        } else {
            std::cout << "Incorrect use, type --h or -help for help\n";
        }
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
