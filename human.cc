#include "human.h"
#include <vector>
using namespace std;

Human::Human() {}

bool Human::checkValidity(Board boardClass, Move move) {
    return baseCheckValidity(boardClass, move);
}

 