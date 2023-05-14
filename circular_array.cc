#include <vector>
#include <iostream>
#include <array>

class CircularArray {
    public:
        CircularArray(int n) {
            v = new int(n); 
            size = n;
        }

        void push_back(int x) {
            if (!is_full()) {
                v[tail] = x;
                tail = next_index(tail);
            } else
                throw std::runtime_error("xx");
        }

        int pop_front() {
            if (!is_empty()) {                
                int value = v[head];
                head = next_index(head);
                return value;
            } else 
                throw std::runtime_error("xx");
        }

        int pop_back() {
            if (!is_empty()) {                
                int value = v[tail];
                tail = prev_index(tail);
                return value;
            } else
                throw std::runtime_error("xx");
        }

        bool is_empty() {
            return head == tail;
        }

        bool is_full() {
            return next_index(tail) == head;
        }

        void debug() {
            std::cout << head << " " << tail << std::endl;
        }

    private:
        size_t next_index(size_t i) {
            return (i + 1) % size;
        }

        size_t prev_index(size_t i) {
            if (i > 0) return i - 1;
            return size - 1;
        }

        int* v;
        int size;
        size_t head = 0, tail = 0;
};

int main() {
    CircularArray a(5);
    a.push_back(1); 
    a.push_back(2); 
    a.push_back(3); 
    a.push_back(4);

    std::cout<<a.pop_front()<<std::endl;
    a.push_back(5);
    a.debug();
    std::cout<<a.is_full()<<std::endl;
}