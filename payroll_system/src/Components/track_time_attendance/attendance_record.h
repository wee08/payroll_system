#ifndef ATTENDANCE_RECORD_H
#define ATTENDANCE_RECORD_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "../../Model/structure.h"
#include "../../utils/calculate_utils.h"
#include "./update_attendance.h"
#include "../convert_ID.h"

using namespace std;

void attendance_record(Employee *e, string file_name, string target_ID,int attendance_count, int work_hour) {

    target_ID = convert_ID(target_ID);

    ifstream find_ID(file_name);
    if (!find_ID.is_open()) {
        cout << "File not open!" << endl;
        return;
    }

    string content = "";
    string line;
    bool   found = false;

    getline(find_ID, line);
    content += line + "\n";

    while (getline(find_ID, line)) {
        if (line.empty()) continue;

        string ID = line.substr(0, line.find(','));

        if (ID == target_ID) {
            found = true;

            stringstream ss(line);
            string cols[13];
            for (int i = 0; i < 13; i++) getline(ss, cols[i], ',');

            float hourly_paid = stof(cols[6]);

            CalcResult calc = calculate_utils(attendance_count, work_hour, hourly_paid);

            cols[8]  = to_string(calc.overtime);
            cols[9]  = to_string(attendance_count);
            cols[10] = to_string(work_hour);
            cols[11] = to_string(calc.overtime_paid);
            cols[12] = to_string(calc.total_cost);

            Attendance_record* ar = e->head;
            while (ar != nullptr) {
                if (ar->ID == target_ID) {
                    ar->overtime       = cols[8];
                    ar->attendance_count = cols[9];
                    ar->work_hour      = cols[10];
                    ar->overtime_paid  = cols[11];
                    ar->total_cost     = cols[12];
                    break;
                }
                ar = ar->next;
            }

            string updated_row = "";
            for (int i = 0; i < 12; i++) updated_row += cols[i] + ",";
            updated_row += cols[12];

            content += updated_row + "\n";

        } else {
            content += line + "\n";
        }
    }
    find_ID.close();

    if (!found) {
        cout << "Error: ID \"" << target_ID << "\" not found!" << endl;
        return;
    }

    update_attendance(file_name, content);

    cout << "Updated successfully: " << target_ID << endl;
}

#endif