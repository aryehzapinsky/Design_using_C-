#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

string fill_word (int min_length, int max_length)
{
    // Generate random word lengths
    random_device word_generator;
    uniform_int_distribution<int> word_dist(min_length, max_length);
    // Generate random letters
    random_device letter_generator;
    uniform_int_distribution<int> letter_dist(65, 122);

    string s;

    int rando = word_dist(word_generator);
    for (int j = 0; j < rando; ++j) {
        auto letter = letter_dist(letter_generator);
        while (!isalpha(letter))
            letter = letter_dist(letter_generator);
        s.push_back(letter);
    }
    return s;
}

int main()
{
    auto n = 5;
    const char *v1[n];
    const char *v2[n];
    vector<string> holder;

    for (int i = 0; i < n; ++i)
    {
        string s = fill_word(2, 7);
        //fill_word(s);
        holder.push_back(s);
    }

    for (int i = 0; i < n; ++i)
    {
        v1[i] = holder[i].c_str();
        v2[i] = holder[i].c_str();
    }
    for (auto k : holder) cout<<k<<" ";
    cout<<"\n";

    sort(v1, v1+n, [](const char *a, const char *b)
         {
             return 0 > strcmp(a, b);
         });
    for (int i = 0; i < n; ++i)
    {
        cout<<v1[i];
        cout<<" ";
    }
    cout<<"\n";

    qsort(v2, n, sizeof(char *), [](const void *a, const void *b)
          {
              const char *arg1 = *(const char **)(a);
              const char *arg2 = *(const char **)(b);
              return strcmp(arg1, arg2);
          }
        );
    for (int i = 0; i < n; ++i)
    {
        cout<<v2[i];
        cout<<" ";
    }
}
