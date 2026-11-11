#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

// ==================== 1. Poperednie ogoloshennia (prototypy) ====================
template <typename T> T Sqr(T x);
template <typename T> vector<T> Sqr(const vector<T>& v);
template <typename K, typename V> map<K, V> Sqr(const map<K, V>& m);
template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& p);

// ==================== 2. Oznachennia shablonnykh funktsii ====================

// Bazovyi Sqr dlia chysel
template <typename T>
T Sqr(T x) {
    return x * x;
}

// Sqr dlia vector
template <typename T>
vector<T> Sqr(const vector<T>& v) {
    vector<T> result;
    result.reserve(v.size());
    for (const auto& item : v) {
        result.push_back(Sqr(item)); // Vyklyk Sqr dlia kozhnoho elementa
    }
    return result;
}

// Sqr dlia map (pidnosymo do kvadratu tilky znachennia value, key ne chipaiemo)
template <typename K, typename V>
map<K, V> Sqr(const map<K, V>& m) {
    map<K, V> result;
    for (const auto& item : m) {
        result[item.first] = Sqr(item.second);
    }
    return result;
}

// Sqr dlia pair (pidnosymo do kvadratu obydva elementy pary)
template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p) {
    return {Sqr(p.first), Sqr(p.second)};
}

// ==================== 3. Perevirochna funktsiia main z laboratornoi ====================
int main() {
    // Test 1: vector
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    // Test 2: map of pairs
    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };

    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}
