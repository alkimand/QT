#ifndef INTERVAL_MAP_H
#define INTERVAL_MAP_H
#include <iostream>
#include <map>
template<typename K, typename V>
class interval_map {
    friend void IntervalMapTest();


public:
   V m_valBegin;
   std::map< K,V > m_map;
   interval_map(V const& val) : m_valBegin(val){};
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        if (keyBegin < keyEnd) {
            auto left = m_map.upper_bound(keyBegin);
            if (left!= m_map.begin())
               --left;
            V  old_value = left->second;
            auto right = m_map.upper_bound(keyEnd);
            if (left != right) {
                if(left->first < keyBegin)
                    ++left;
                for(auto it = left++; it != right;) {
                        old_value = it->second;
                        it = m_map.erase(it);
                }
            }
            else {
                old_value = m_valBegin;
            }
            m_map.insert_or_assign(keyEnd, old_value);
            m_map.insert_or_assign(keyBegin, val);
        }
    };

    V const& operator[](K const& key) const {
        auto it = m_map.upper_bound(key);

        if(it == m_map.begin()) {
            return m_valBegin;
        } else {
            return (--it)->second;
        }
    };
};















#endif // INTERVAL_MAP_H
