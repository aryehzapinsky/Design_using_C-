#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <random>
#include <functional>
#include <fstream>

using namespace std;

template<class Sequence, typename T>
void special_insert(Sequence s, T &container) {
    auto sit = s.begin();
    container.insert(container.begin(), *sit);
    for (sit++; sit != s.end(); sit++) {
        auto cit = container.begin();
        for (; *sit > *cit; cit++);
        container.insert(cit, *sit);
    }
}

template<class Sequence, typename T>
void special_remove(Sequence s, T &container) {
    for (auto i : s) {
        auto cit = container.begin();
        for (int j = 0; j != i; j++, cit++);
        container.erase(cit);
    }
}

void generate_rand_ints(int k, unordered_set<int> &s) {
    random_device r;

    default_random_engine generator(r());
    uniform_int_distribution<int> distribution(0, k*2);
    for (auto get_num = bind(distribution, generator); s.size() != k; )
        s.insert(get_num());
}

void generate_removal_ints(int k, vector<int> &removal) {
    random_device r;

    default_random_engine generator(r());
    for (auto i = 0; i < k; i++) {
        uniform_int_distribution<int> distribution(0, k-i);
        removal.push_back(distribution(generator));
    }

}



int main()
{
    cout<<"Hi";

    // ofstream results{"results.csv"};
    // if (!results) {
    //     cout<<"Error 'opening results.csv'\n";
    //     abort();
    // }
    // for (auto x = 0; x < 10; x++) {
    //     auto sequence = unordered_set<int>();
    //     generate_rand_ints(x*100000, sequence);


    // }
    // auto sequence = unordered_set<int>();
    // generate_rand_ints(100000, sequence);

    auto seq = unordered_set<int>();
    cout<<seq.size();
    generate_rand_ints(10, seq);
    vector<int> removal = {2, 1, 0, 0};

    for (auto i : seq)
        cout<<i;


    auto start = chrono::system_clock::now();
    list<int> l;
    special_insert(seq, l);
    for (auto i : l)
        cout<<i;
    special_remove(removal, l);
    auto end = chrono::system_clock::now();
    auto elapsed_seconds = end-start;

    cout<<"List: " << elapsed_seconds.count() << '\n';

    start = chrono::system_clock::now();
    vector<int> v;
    special_insert(seq, v);
    special_remove(removal, v);
    end = chrono::system_clock::now();
    elapsed_seconds = end-start;

    cout<<"Vector: " << elapsed_seconds.count() << '\n';
}
