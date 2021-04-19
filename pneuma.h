#ifndef PNEUMATIC_CYLINDER_PNEUMA_H
#define PNEUMATIC_CYLINDER_PNEUMA_H

#include <stdbool.h>

#if defined(_cplusplus)
extern "C" { }
#endif
//шаг
enum State {
    STATE_ZERO, STATE_ONE, STATE_TWO, STATE_THREE, STATE_FOUR,
    STATE_FIVE, STATE_SIX, STATE_SEVEN, STATE_EIGHT, STATE_NINE
};

//вывод значения пневмоцилиндров
enum Output {
    OUTPUT_ZERO = 0, OUTPUT_ONE = 1, OUTPUT_TWO = 2, OUTPUT_THREE = 3
};

//перечисление отрезков времени,
//за которые пневмоцилиндр меняет свое положение
enum TSymbol {
    T_ONE = 120, T_TWO = 120, T_THREE = 120, T_FOUR = 120, T_FIVE = 200,
    T_SIX = 120, T_SEVEN = 200, T_EIGHT = 120, T_NINE = 200
};

//перечисление отрезков времени, в течение
//которых удерживается положение пневмоцилиндров
enum DSymbol {
    D_ONE = 10, D_TWO = 60, D_THREE = 60, D_FOUR = 10, D_FIVE = 60,
    D_SIX = 60, D_SEVEN = 60, D_EIGHT = 60, D_NINE = 10
};

struct ExchAuto {
    enum State state;
};

#define DEFAULT_STATE STATE_ZERO

bool delay_init(struct ExchAuto *engine); //внутренняя структура автомата

bool delay_reset(struct ExchAuto *engine); //сброс автомата

//вызов автомата на следующем шаге
enum Output exch_auto(struct ExchAuto *engine, double time, double dtime);

#if defined(_cplusplus)
#endif
#endif //PNEUMATIC_CYLINDER_PNEUMA_H
