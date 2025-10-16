/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>
#include "Sequence.h"

using namespace std;

int main() {
    cout << "Your project is ready to go!" << endl;
    try
    {
        Sequence s(3);
        s[0] = "A";
        s[1] = "B";
        s[2] = "C";
        cout << "after init:       " << s << "  (size=" << s.size() << ")\n";

        s.push_back("D");
        cout << "after push_back:  " << s << "  (size=" << s.size() << ")\n";

        s.erase(1,2);
        cout << "after erase:    " << s << "  (size=" << s.size() << ")\n";

        s.clear();
        cout << "after clear:    " << s << "  (size=" << s.size() << ")\n";
    } catch (const exception& e)
    {
        cout << "exception" << e.what() << "\n";
    }
    return 0;
}