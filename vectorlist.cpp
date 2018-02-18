#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<class Sequence, typename T>
T special_insert(Sequence s, T container) {
    auto sit = s.begin();
    container.insert(container.begin(), *sit);
    for (sit++; sit != s.end(); sit++) {
        auto cit = container.begin();
        for (; *sit > *cit; cit++);
        container.insert(cit, *sit);
    }
    return container;
}

int main()
{
    vector<int> initial = {5, 1, 4, 2};

    auto v = special_insert(initial, vector<int>());

    for (auto i : v)
        cout << i;
    cout << '\n';

    auto l = special_insert(initial, list<int>());

    for (auto i : l)
        cout << i;
    cout << '\n';
}
