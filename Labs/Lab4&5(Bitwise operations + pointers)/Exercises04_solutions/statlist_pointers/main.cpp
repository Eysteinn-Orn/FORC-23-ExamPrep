#include <iostream>
#include "statlist.h"

using namespace std;

int main(){
    StatList *list = new StatList();

    list->append(2, 5, 2.3);
    list->append(7, 3, 0.6);
    list->append(27, 8, 1.8);
    list->append(54, 0, 3.1);
    list->append(12, 1, 1.7);

    cout << *list << endl;

    cout << "get_at(3): " << *(list->get_at(3)) << endl;
    cout << "get_at(4): " << *(list->get_at(4)) << endl;
    cout << "get_at(0): " << *(list->get_at(0)) << endl;

    cout << endl;

    cout << "insert(3.3, 3)" << endl;
    list->insert(3, 3, 3.3, 3);
    cout << *list << endl;

    cout << "insert(0.0, 0)" << endl;
    list->insert(0, 0, 0.0, 0);
    cout << *list << endl;

    cout << "insert(7.7, 7)" << endl;
    list->insert(7, 7, 7.7, 7);
    cout << *list << endl;

    cout << "remove(4)" << endl;
    list->remove(4);
    cout << *list << endl;

    cout << "remove(6)" << endl;
    list->remove(6);
    cout << *list << endl;

    cout << "remove(0)" << endl;
    list->remove(0);
    cout << *list << endl;

    delete list;

    cout << "ALL DONE!" << endl;

    return 0;
}