#include "engine_control.h"

void update_engine_state(int ignition_switch, int *engine_state) {
    if (ignition_switch == 1)
        *engine_state = 1;
    else
        *engine_state = 0;
}
