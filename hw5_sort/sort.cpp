#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <limits>
#include <memory>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
using Clock = chrono::steady_clock;

void run_random_int(int n)
{
    vector<int> v1;
    vector<int> v2;

    // Generate vectors of random integers
    random_device generator;
    uniform_int_distribution<int> distribution(0, numeric_limits<int>::max());

    for (int i = 0; i < n; ++i)
    {
        int rando = distribution(generator);
        v1.push_back(rando);
        v2.push_back(rando);
    }

    // for(auto q:v1) cout<<q<<" ";
    // cout<<"\n";

    // Sort
    auto start = Clock::now();
    sort(v1.begin(), v1.end());
    auto end = Clock::now();
    chrono::duration<double> sort_time = end-start;

    // QSort
    start = Clock::now();
    qsort(&v2[0], v2.size(), sizeof(int), [](const void* a, const void* b)
    {
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);

        if(arg1 < arg2) return -1;
        if(arg1 > arg2) return 1;
        return 0;
    });
    end = Clock::now();

    chrono::duration<double> qsort_time = end-start;

    // for (auto q:v1) cout<<q<<" ";
    // cout<<"\n";
    // for (auto q:v2) cout<<q<<" ";
    // cout<<"\n";

    cout<< n << " elements\n Sort Time\tQSort Time\n";
    cout<< sort_time.count()<< "\t" << qsort_time.count() << "\n";
}

void run_random_char(int n)
{
    //vector<unique_ptr<const char*>> v1;
    //vector<unique_ptr<const char*>> v2;

    char v1[n][32];
    char v2[n][32];

    // Generate random word lengths
    random_device word_generator;
    uniform_int_distribution<int> word_dist(2, 4);
    // Generate random letters
    random_device letter_generator;
    uniform_int_distribution<int> letter_dist(65, 122);

    for (int i = 0; i < n; ++i)
    {
        int rando = word_dist(word_generator);
        string s;
        for (int j = 0; j < rando; ++j) {
            auto letter = letter_dist(letter_generator);
            while (!isalpha(letter))
                letter = letter_dist(letter_generator);
            s.push_back(letter);
        }
        strcpy(v1[i], s.data());
        strcpy(v2[i], s.data());
     }

    for(auto q:v1) cout<<q<<" ";
    cout<<"\n";
    // for(auto q:v2) cout<<q<<" ";
    // cout<<"\n";

    // vector<char *> v1 (wo, wo+n);
    // for(auto q:v1) cout<<q<<" ";
    // cout<<"\n";
    // vector<char *> v2 (wo, wo+n);
    // for(auto q:v1) cout<<q<<" ";
    // cout<<"\n";

    // Sort
    auto start = Clock::now();
    //sort(v1, v1+n);
    auto end = Clock::now();
    chrono::duration<double> sort_time = end-start;

    for(auto q:v2) cout<<q<<" ";
    cout<<"\n";
    // // QSort
    // start = Clock::now();
    qsort(v2, n, sizeof(char *), [](const void* a, const void* b)
          {
              const char **arg1 = (const char**)a;
              const char **arg2 = (const char**)b;
          //const char* arg2 = static_cast<const char*>(b);

              return strcmp(*arg1, *arg2);
          });
    // end = Clock::now();

    // chrono::duration<double> qsort_time = end-start;

    for (auto q:v1) cout<<q<<" ";
    cout<<"\n";
    for (auto q:v2) cout<<q<<" ";
    cout<<"\n";

    // cout<< n << " elements\n Sort Time\tQSort Time\n";
    // cout<< sort_time.count()<< "\t" << qsort_time.count() << "\n";
}

void run_random_str(int n)
{
    vector<string> v1;
    vector<string> v2;

    // Generate random word lengths
    random_device word_generator;
    uniform_int_distribution<int> word_dist(2, 7);
    // Generate random letters
    random_device letter_generator;
    uniform_int_distribution<int> letter_dist(65, 122);

    for (int i = 0; i < n; ++i)
    {
        int rando = word_dist(word_generator);
        string s;
        for (int j = 0; j < rando; ++j) {
            auto letter = letter_dist(letter_generator);
            while (!isalpha(letter))
                letter = letter_dist(letter_generator);
            s.push_back(letter);
        }
        //s.resize(32);
        v1.push_back(s);
        v2.push_back(s);
    }

    for(auto q:v1) cout<<q<<" ";
    cout<<"\n";
    for(auto q:v2) cout<<q<<" ";
    cout<<"\n";

    // Sort
    auto start = Clock::now();
    sort(v1.begin(), v1.end());
    auto end = Clock::now();
    chrono::duration<double> sort_time = end-start;

    // QSort
    start = Clock::now();
    qsort(v2.data(), v2.size(), sizeof(char *), [](const void* a, const void* b)
    {
        const char **arg1 = (const char**)a;
        const char **arg2 = (const char**)b;

        return strcmp(*arg1, *arg2);
    });
    end = Clock::now();

    chrono::duration<double> qsort_time = end-start;

    for (auto q:v1) cout<<q<<" ";
    cout<<"\n";
    for (auto q:v2) cout<<q<<" ";
    cout<<"\n";

    // cout<< n << " elements\n Sort Time\tQSort Time\n";
    // cout<< sort_time.count()<< "\t" << qsort_time.count() << "\n";
}

int main()
{
    run_random_int(5000);
    run_random_int(400000);
    run_random_int(800000);
    //run_random_char(5);
}
