#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <limits>

using namespace std;


class Timer {
    using Clock = chrono::system_clock;
    chrono::time_point<Clock> start;
    chrono::time_point<Clock> end;
public:
    void start_timer() {start=Clock::now();}
    void end_timer() {end=Clock::now();}
    chrono::duration<double> record_duration() {return end-start;}
};

void fill_random_ints(int n, vector<int> &v1, vector<int> &v2)
{
    random_device generator;
    uniform_int_distribution<int> distribution(0, numeric_limits<int>::max());
    for (int i = 0; i < n; ++i)
    {
        int rando = distribution(generator);
        v1.push_back(rando);
        v2.push_back(rando);
    }
    //for (auto i : v2) cout<<i<< " ";
}

void fill_random_c_strings(int n, vector<char *> &v1, vector<char *> &v2) {
    char myString[] = "string";
    for (int i = 0; i < n; ++i)
    {
        v1.push_back(myString);
        v2.push_back(myString);
    }
}
void run_random_ints(int n)
{
    Timer recorder;
    vector<int> v1;
    vector<int> v2;

    fill_random_ints(n, v1, v2);
    recorder.start_timer();
    sort(v1.begin(), v1.end());
    recorder.end_timer();
    auto sort_time = recorder.record_duration().count();

    recorder.start_timer();
    qsort(&v2[0], v2.size(), sizeof(int), [](const void* a, const void* b)
          {
              int arg1 = *static_cast<const int*>(a);
              int arg2 = *static_cast<const int*>(b);

              if(arg1 < arg2) return -1;
              if(arg1 > arg2) return 1;
              return 0;
          });
    recorder.end_timer();
    auto qsort_time = recorder.record_duration().count();
    cout<< n << "elements\tSort Time\tQSort Time\n\t" << sort_time << "\t" << qsort_time;
}

int main()
{
    run_random_ints(5);
    vector<char *> v1;
    vector<char *> v2;
    fill_random_c_strings(3, v1, v2);
    for (auto i:v1) cout<<i<<" ";
}
