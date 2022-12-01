#include "human.h"
#include "player.h"
#include <vector>
using namespace std;

bool Human::checkValidity(Move move) {
    return board->baseCheckValidity(move);
}

 