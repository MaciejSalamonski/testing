#define CATCH_CONFIG_MAIN
#include <vector>

#include "catch.hpp"

int score(int number) {
    return number;
}

SCENARIO("Miss in every game", "[points]") {
    GIVEN("Ten turns of game") {
        std::vector<int> game(20, 0);
        WHEN("Missing in every turn") {
            int gameScore = score(0);
            THEN("Score should be 0 points") {
                REQUIRE(gameScore == 0);
            }
        }
    }
}

SCENARIO("Getting 1 points in every game", "[points]") {
    GIVEN("Ten turns of game") {
        std::vector<int> game;
        for (size_t i = 0; i < 10; i++) {
            game.emplace_back(1);
            game.emplace_back(0);
        }

        WHEN("Missing in every turn") {
            int gameScore = score(20);
            THEN("Score should be 0 points") {
                REQUIRE(gameScore == 20);
            }
        }
    }
}

SCENARIO("Ten strikes - perfect game", "[points]") {
    GIVEN("Ten turns of game") {
        std::vector<int> game(10, 10);
        WHEN("Getting strike in every turn") {
            int gameScore = score(300);
            THEN("Score should be 300 points") {
                REQUIRE(gameScore == 300);
            }
        }
    }
}

SCENARIO("Strike in last turn", "[game]") {
    GIVEN("Ten turns of game") {
        std::vector<int> game(9, 0);
        game.push_back(10);
        auto lengthBeforeRolling = game.size();
        game.push_back(5);
        game.push_back(5);

        WHEN("Getting strike in last turn") {
            int lengthAfterRolling = game.size();
            THEN("Should be 2 more rolls") {
                REQUIRE(lengthBeforeRolling + 2 == lengthAfterRolling);
            }
        }
    }
}

SCENARIO("Spare in last turn", "[game]") {
    GIVEN("Ten turns of game") {
        std::vector<int> game(9, 0);
        game.push_back(10);
        auto lengthBeforeRolling = game.size();
        game.push_back(5);

        WHEN("Getting spare in last turn") {
            int lengthAfterRolling = game.size();
            THEN("Should be 1 more roll") {
                REQUIRE(lengthBeforeRolling + 1 == lengthAfterRolling);
            }
        }
    }
}

SCENARIO("First ball - 9, Second - 0", "[points]") {
    GIVEN("Ten turns of game") {
        std::vector<int> game(10, 9);

        WHEN("9 pins hit with first ball and 0 with second one") {
            auto gameScore = score(90);

            THEN("Score should be equal 90") {
                REQUIRE(gameScore == 90);
            }
        }
    }
}

SCENARIO("Spare every turn", "[points]") {
    GIVEN("Ten turns of game") {
        std::vector<int> game(20, 5);

        WHEN("5 pins hit with the first ball, spare with the second one") {
            auto gameScore = score(150);

            THEN("Score should be equal 150") {
                REQUIRE(gameScore == 150);
            }
        }
    }
}

SCENARIO("Spare", "[points]") {
    GIVEN("Two turns") {
        int firstShot = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9);
        int secondTurn = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9);

        WHEN("first ball - (1-9 pins); second ball - last ones") {
            std::vector<int> game{firstShot, 10 - firstShot, secondTurn, 0};
            auto firstTurnScore = score(10 + secondTurn);

            THEN("Spare") {
                REQUIRE(firstTurnScore == 10 + secondTurn);
            }
        }
    }
}

SCENARIO("Strike", "[points]") {
    GIVEN("Two turns") {
        int secondTurn = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9);

        WHEN("first ball - 10 pins") {
            std::vector<int> game{10, 0, secondTurn, 1};
            auto firstTurnScore = score(10 + secondTurn + 1);

            THEN("Strike") {
                REQUIRE(firstTurnScore == 10 + secondTurn + 1);
            }
        }
    }
}

SCENARIO("Regular game without strike and spare", "[points]") {
    GIVEN("Regular game without strike and spare") {
        std::vector<int> game{5, 3, 4, 3, 7, 2, 5, 1, 8, 0, 6, 2, 4, 4, 3, 3, 7, 1, 4, 2};
        WHEN("Count score for game") {
            auto gameScore = score(167);
            
            THEN("Should be equal to") {
                REQUIRE(gameScore == 167);
            }
        }
    }
}
