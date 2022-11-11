#include "Stack.h"

int main() {
    Stack<int>stack;
    int n;
    std::cin>>n;
    for (int i = 0; i < n; ++i) {
        std::cin>>stack;
    }
    std::cout<<stack;
}
