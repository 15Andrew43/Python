#include <iostream>
#include <set>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const size_t kModule = 1000000000;
    size_t n;
    std::cin >> n;
    std::set<size_t> s;
    char operation;
    size_t i;
    size_t res;
    bool flag = false;
    for (size_t j = 0; j < n; ++j) {
        std::cin >> operation >> i;
        if (flag && operation == '+') {
            s.insert((i + res) % kModule);
            flag = false;
        } else if (operation == '+') {
            s.insert(i);
        } else {
            std::set<size_t >::iterator it = s.lower_bound(i);
            if (it != s.end()) {
                res = *it;
                std::cout << res << '\n';
            } else {
                res = 0;
                std::cout << -1 << '\n';
            }
            flag = true;
        }
    }
    return 0;
}