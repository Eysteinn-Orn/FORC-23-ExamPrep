#ifndef KEYEDCONTAINER_H_4457345
#define KEYEDCONTAINER_H_4457345

#include <map>

using namespace std;

template <typename K, typename V>
class KeyedContainer {
public:
    KeyedContainer(){}

    void PutIntoContainer(K key, V data) {
        this->store[key] = data;
    }

    V GetFromContainer(K key) {
        return this->store[key];
    }

protected:
    map<K, V> store;
};

#endif //KEYEDCONTAINER_H_4457345