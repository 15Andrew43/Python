#include <iostream>
#include <unordered_map>
#include <list>


class Server {
private:
    std::list<size_t> users_;
    size_t max_sieze_;
    std::unordered_map<size_t, std::list<size_t>::iterator> cash_;
public:
    void SetSizeCash(size_t size) {
        max_sieze_ = size;
        cash_.reserve(max_sieze_);
    }
    void getUser(size_t user) {
        if (cash_.size() < max_sieze_) {
            if (cash_.count(user) == 0) {
                users_.push_back(user);
                cash_[user] = --users_.end();
                std::cout << 1 << ' ';
            } else {
                    users_.erase(cash_[user]);
                    users_.push_back(user);
                    cash_[user] = --users_.end();
                std::cout << 0 << ' ';
            }
        } else if (cash_.size() == max_sieze_) {
            if (cash_.count(user) == 0) {
                cash_.erase(users_.front());
                users_.pop_front();
                users_.push_back(user);
                cash_[user] = --users_.end();
                std::cout << 1 << ' ';
            } else {
                    users_.erase(cash_[user]);
                    users_.push_back(user);
                    cash_[user] = --users_.end();
                std::cout << 0 << ' ';
            }
        }
    }
};


int main() {
    Server server;
    size_t M;
    std::cin >> M;
    server.SetSizeCash(M);
    size_t user;
    while (std::cin >> user) {
        server.getUser(user);
    }
    return 0;
}
