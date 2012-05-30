#include <stdio.h>
#include <vector>
#include <time.h>
#include <stdint.h>

using namespace std;

struct Record {
    int time;
    int meter;
};

vector<Record> days[3];

void make_record(int day, int time, int meter)
{
    Record record;
    record.time = time;
    record.meter = meter;
    days[day].push_back(record);
}

void list_day(int day)
{
    printf("\n=== Day %d ===\n", day+1);
    vector<Record>::iterator it = days[day].begin();
    for (; it != days[day].end(); ++it) {
        printf("Time: %02d, meter: %d\n", it->time, it->meter);
    }
}

void show_avg(Record &prev, Record &curr)
{
    printf("ave time: %.1f, avg meter: %f\n",
           (double)(curr.time+prev.time)/2, (double)(curr.meter-prev.meter)/((curr.time-prev.time)*60));
}

void analysize_1day(int day)
{
    Record prev, curr;
    for (uint32_t i = 1; i < days[day].size(); ++i) {
        prev = days[day][i-1];
        curr = days[day][i];
        show_avg(prev, curr);
    }
}

void analysis()
{
    int day = 0;
    double ave_time;
    double last_point;

    Record prev, curr;
    Record next;

    printf("\nAnalysis Day %d\n\n", day+1);
    analysize_1day(day);

    curr = days[day].back();
    next = days[day+1].front();
    double a = (double)(24 - curr.time) / (24 - curr.time + next.time);
    double b = (double)(next.meter - curr.meter);
    double c = (double)((24 - curr.time) * 60.0);
    last_point = a * b / c;
    printf("last:     %.1f, avg meter: %f\n", 24.0, last_point);

    for (day = 1; day < 3; ++day) {
        printf("\nAnalysis Day %d\n\n", day+1);

        prev = days[day-1].back();
        curr = days[day][0];
        ave_time = (24+curr.time+prev.time)/2.0;
        if (ave_time > 24)
            ave_time -= 24;
        printf("ave time: %.1f, avg meter: %f\n",
               ave_time, (double)(curr.meter-prev.meter)/(ave_time*60));
        analysize_1day(day);
    }
}

int main()
{
    make_record(0, 8, 5);
    make_record(0, 12, 10);
    make_record(0, 19, 20);
    make_record(0, 22, 25);
    list_day(0);

    make_record(1, 7, 30);
    make_record(1, 9, 35);
    make_record(1, 13, 45);
    make_record(1, 20, 60);
    make_record(1, 23, 65);
    list_day(1);

    make_record(2, 4, 70);
    make_record(2, 17, 80);
    make_record(2, 23, 95);
    list_day(2);

    printf("\n\n");

    analysis();

    return 0;
}
