#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pneuma.h"

int main(int argc, char **argv) {
    struct ExchAuto engine = {0};
    enum Output output;
    enum TSymbol time;
    enum DSymbol dtime;
    delay_init(&engine);
    output = exch_auto(&engine, time, dtime);
    fprintf(stdout, "%c", ((int)output) + '0');
}
