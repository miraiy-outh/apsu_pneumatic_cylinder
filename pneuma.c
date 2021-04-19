#include "pneuma.h"

enum Output exch_auto(struct ExchAuto *engine, double time, double dtime) {
    switch (engine->state) {
        case STATE_ZERO: {
            if (time <= T_ONE && dtime <= D_ONE) {
                engine->state = STATE_ONE;
                return OUTPUT_ZERO;
            }
            else {
                engine->state = STATE_SIX;
                return OUTPUT_THREE;
            }
        }
        case STATE_ONE: {
            if (time <= T_TWO && dtime <= D_TWO) {
                engine->state = STATE_TWO;
                return OUTPUT_TWO;
            }
            else {
                delay_reset(engine);
                break;
            }
        }
        case STATE_TWO: {
            if (time <= T_THREE && dtime <= D_THREE) {
                engine->state = STATE_THREE;
                return OUTPUT_THREE;
            }
            else {
                delay_reset(engine);
                break;
            }
        }
        case STATE_THREE: {
            if (time <= T_FOUR && dtime <= D_FOUR) {
                engine->state = STATE_FOUR;
                return OUTPUT_ONE;
            }
            else {
                delay_reset(engine);
                break;
            }
        }
        case STATE_FOUR: {
            if (time <= T_FIVE && dtime <= D_FIVE) {
                engine->state = STATE_FIVE;
                return OUTPUT_ONE;
            }
            else {
                delay_reset(engine);
                break;
            }
        }
        case STATE_FIVE: {
            if (time <= T_SIX && dtime <= D_SIX) {
                engine->state = STATE_SIX;
                return OUTPUT_THREE;
            }
            else {
                delay_reset(engine);
                break;
            }
        }
        case STATE_SIX: {
            if (time <= T_SEVEN && dtime <= D_SEVEN) {
                engine->state = STATE_SEVEN;
                return OUTPUT_ONE;
            }
            else {
                delay_reset(engine);
                break;
            }
        }
        case STATE_SEVEN: {
            if (time <= T_EIGHT && dtime <= D_EIGHT) {
                engine->state = STATE_EIGHT;
                return OUTPUT_THREE;
            }
            else {
                delay_reset(engine);
                break;
            }
        }
        case STATE_EIGHT: {
            if (time <= T_NINE && dtime <= D_NINE) {
                engine->state = STATE_NINE;
                return OUTPUT_ONE;
            }
            else {
                delay_reset(engine);
                break;
            }
        }
        case STATE_NINE: {
            if (time <= T_NINE && dtime <= D_NINE) {
                return OUTPUT_ONE;
            }
            else {
                delay_reset(engine);
                break;
            }
        }
    }
    return OUTPUT_THREE;
}

bool delay_init(struct ExchAuto *engine) {
    if (0 == engine)
        return false;
    engine->state = DEFAULT_STATE;
    return true;
}

bool delay_reset(struct ExchAuto *engine) {
    return delay_init(engine);
}