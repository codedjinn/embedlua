#pragma once

#include <vector>
#include <string>

namespace Engine
{

struct LookupItem
{
    std::string Key;
    std::string Value;    

    LookupItem(std::string key, std::string value)
    {
        Key = key;
        Value = value;
    }
};

// easier to create custom class than to deal with STL...WTF
class Lookup
{

private:

    std::vector<LookupItem> _items;

public:

    Lookup() {}
    // /Lookup(int capacity) { _items(capacity); }

    bool HasKey(std::string key);
    std::string Get(std::string key);

    void Add(std::string key, std::string value);
    void Remove(std::string key);
    void Clear();

};

}