#include "Stack.h"
#include "Queue.h"

#define endl '\n'

using std::cout;

void TestStack() {
    Stack<int> s1;

    s1.Push(1);
    s1.Push(2);
    s1.Push(3);

    cout << s1 << endl;         // 3->2->1
    cout << s1.Size() << endl;

    Stack<int> s2(s1), s3;

    s1.Pop();
    s1.Push(4);
    s1.Push(5);

    s2.Pop();
    s2.Push(6);

    cout << s1 << endl;         // 5->4->2->1
    cout << s1.Size() << endl;

    cout << s2 << endl;         // 6->2->1
    cout << s2.Size() << endl;

    s3 = s1;

    s1.Pop();
    s1.Push(7);
    s1.Push(8);

    s3.Pop();
    s3.Push(9);

    cout << s1 << endl;         // 8->7->4->2->1
    cout << s1.Size() << endl;

    cout << s2 << endl;         // 6->2->1
    cout << s2.Size() << endl;

    cout << s3 << endl;         // 9->4->2->1
    cout << s3.Size() << endl;
}

void TestQueue() {
    Queue<int> s1;

    s1.Push(1);
    s1.Push(2);
    s1.Push(3);

    cout << s1 << endl;          // 1->2->3
    cout << s1.Size() << endl;

    Queue<int> s2(s1), s3;

    s1.Pop();
    s1.Push(4);
    s1.Push(5);

    s2.Pop();
    s2.Push(6);

    cout << s1 << endl;         // 2->3->4->5
    cout << s1.Size() << endl;

    cout << s2 << endl;         // 2->3->6
    cout << s2.Size() << endl;

    s3 = s1;

    s1.Pop();
    s1.Push(7);
    s1.Push(8);

    s3.Pop();
    s3.Push(9);

    cout << s1 << endl;         // 3->4->5->7->8
    cout << s1.Size() << endl;

    cout << s2 << endl;         // 2->3->6
    cout << s2.Size() << endl;

    cout << s3 << endl;
    cout << s3.Size() << endl;  // 3->4->5->9
}

int main() {
    TestStack();
    TestQueue();

}