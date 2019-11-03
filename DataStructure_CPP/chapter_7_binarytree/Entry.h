//
// Created by wujinxing on 2019/11/3.
//

#ifndef CPLUS_LEARNING_ENTRY_H
#define CPLUS_LEARNING_ENTRY_H

template<typename K, typename V>
struct Entry {
    K key;
    V value;

    Entry(K k = K(), V v = V()) : key(k), value(v) {}; // 默认构造函数

    Entry(Entry<K, V> const &e) : key(e.key), value(e.value) {}; // 基于克隆的构造函数

    bool operator<(Entry<K, V> const &e) { return key < e.key; }

    bool operator>(Entry<K, V> const &e) { return key > e.key; }

    bool operator==(Entry<K, V> const &e) { return key == e.key; }

    bool operator!=(Entry<K, V> const &e) { return key != e.key; }
};

#endif //CPLUS_LEARNING_ENTRY_H
