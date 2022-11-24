#include "Stack.h"
#include "Queue.h"

void TestStack() {
    Stack<int> st(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(5);
    Stack<int> a(st);
    std::cout<<st;
    std::cout<<a;
}

void TestQueue() {
    Queue<int> queue(1);
    queue.Push(2);
    std::cout<<queue;
    queue.Pop();
    std::cout<<queue;
    Queue<int> q2(queue);
    q2.Pop();
    std::cout << "q2 empty: " << q2.IsEmpty();
}

int main() {
    TestStack();
    TestQueue();

}