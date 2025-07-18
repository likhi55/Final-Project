#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../h_files/engine_control.h"

#define MAX_LINE 100

int main() {
    FILE *fcase = fopen("testcases/case_input.csv", "r");
    FILE *flog = fopen("app/output/log.txt", "r");
    FILE *fout = fopen("app/output/output.csv", "w");
    FILE *fcal;

    if (!fcase || !flog || !fout) {
        fprintf(stderr, "Error opening files.\n");
        return 1;
    }

    char headers[MAX_LINE];
    fgets(headers, MAX_LINE, fcase); // skip header

    int log_time = 0, log_ignition = 0, log_engine = 0;
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), flog)) {
        if (strstr(line, "time")) log_time = 1;
        if (strstr(line, "ignition_switch")) log_ignition = 1;
        if (strstr(line, "engine_state")) log_engine = 1;
    }

    int first = 1;
    if (log_time) { fprintf(fout, "%s%s", first ? "" : ",", "time"); first = 0; }
    if (log_ignition) { fprintf(fout, "%s%s", first ? "" : ",", "ignition_switch"); first = 0; }
    if (log_engine) { fprintf(fout, "%s%s", first ? "" : ",", "engine_state"); first = 0; }
    fprintf(fout, "\n");

    double time;
    int ignition_switch, engine_state;

    while (fgets(line, sizeof(line), fcase)) {
        if (sscanf(line, "%lf,%d", &time, &ignition_switch) != 2)
            continue;

        fcal = fopen("app/calibration/calibration.txt", "w");
        if (fcal) {
            fprintf(fcal, "ignition_switch=%d\n", ignition_switch);
            fclose(fcal);
        }

        update_engine_state(ignition_switch, &engine_state);

        first = 1;
        if (log_time) { fprintf(fout, "%s%.1f", first ? "" : ",", time); first = 0; }
        if (log_ignition) { fprintf(fout, "%s%d", first ? "" : ",", ignition_switch); first = 0; }
        if (log_engine) { fprintf(fout, "%s%d", first ? "" : ",", engine_state); first = 0; }
        fprintf(fout, "\n");
    }

    fclose(fcase);
    fclose(flog);
    fclose(fout);
    return 0;
}
