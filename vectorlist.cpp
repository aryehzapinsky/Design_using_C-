#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <random>
#include <functional>
#include <fstream>

using namespace std;

template<class Sequence, typename T>
void special_insert(Sequence s, T& container) {
    auto sit = s.begin();
    container.insert(container.begin(), *sit);
    sit++;

    while (sit != s.end()) {
        auto cit = container.begin();
        while((*sit > *cit) && cit!=container.end())
            cit++;
        container.insert(cit, *sit);
        sit++;
    }
}

template<class Sequence, typename T>
void special_remove(Sequence s, T& container) {
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
    for (auto i = k-1; i > 0; i--) {
        uniform_int_distribution<int> distribution(0, i);
        removal.push_back(distribution(generator));
    }
    removal.push_back(0);

}

template<typename T, typename U, typename V>
chrono::duration<double> run_experiment (T &seq, U &removal, V &container) {
    auto start = chrono::system_clock::now();
    special_insert(seq, container);
    special_remove(removal, container);
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;

    return elapsed_seconds;
}

void vector_list_comparision(int start_num) {
    cout << "\tList\tVector\n";
    for (auto x = 0; x < 10; x ++) {
        auto num_elements = start_num + start_num * x;
        for (auto attempt = 0; attempt < 3; attempt++) {
            cout << num_elements << "\t";
            auto seq = unordered_set<int>();
            generate_rand_ints(num_elements, seq);

            vector<int> removal;
            generate_removal_ints(x, removal);

            list<int> l;
            auto elapsed_seconds = run_experiment(seq, removal, l);

            cout<< elapsed_seconds.count() << "\t";

            vector<int> v;
            elapsed_seconds = run_experiment(seq, removal, v);

            cout<< elapsed_seconds.count() << '\n';
        }
    }
}

void run_map_experiment(int start_num) {
    cout << "\tMap\n";
    for (auto x = 0; x < 10; x ++) {
        auto num_elements = start_num + start_num * x;
        for (auto attempt = 0; attempt < 3; attempt++) {
            cout << num_elements << "\t";
            auto seq = unordered_set<int>();
            generate_rand_ints(num_elements, seq);

            vector<int> removal;
            generate_removal_ints(x, removal);


            cout<< elapsed_seconds.count() << "\n";
        }
    }
}

int main()
{
    vector_list_comparision(10);
}
