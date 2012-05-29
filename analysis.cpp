#include <stdio.h>
#include <vector>
#include <time.h>
#include <stdint.h>

using namespace std;

struct Record {
    int time;
    int meter;
};

vector<Record> days[2];

void make_record(int day, int time, int meter)
{
    Record record;
    record.time = time;
    record.meter = meter;
    days[day].push_back(record);
}

void list_day(int day)
{
    printf("=== Day %d ===\n", day+1);
    auto it = days[day].begin();
    for (; it != days[day].end(); ++it) {
        printf("Time: %02d, meter: %d\n", it->time, it->meter);
    }
}

void analysis()
{
    int day = 0;
    for (uint32_t i = 1; i < days[day].size(); ++i) {
        Record prev = days[day][i-1];
        Record curr = days[day][i];
        printf("ave time: %d, avg meter: %f\n",
               (curr.time+prev.time)/2, (double)(curr.meter-prev.meter)/((curr.time-prev.time)*60));
    }
}

int main()
{
    make_record(0, 8, 5);
    make_record(0, 12, 10);
    make_record(0, 19, 20);
    make_record(0, 22, 25);
    list_day(0);

    analysis();

    return 0;
}
