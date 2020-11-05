#include "Lookup.h"

#include "Logger.h"

namespace Engine
{

bool Lookup::HasKey(std::string key)
{
    for (auto cur : _items)
    {
        if (cur.Key.compare(key) == 0)
        {
            return true;
        }
    }
    return false;
}

std::string Lookup::Get(std::string key)
{
    for (auto cur : _items)
    {
        if (cur.Key.compare(key) == 0)
        {
            return cur.Value;
        }
    }
    return std::string();
}

void Lookup::Add(std::string key, std::string value)
{
    if (key.empty())
    {
        LogError("Lookup::Add, can't add empty key!");
        throw;
    }

    if (this->HasKey(key))
    {
        LogError("Lookup::Add, key already added. " + key);
        throw;
    }
    _items.push_back(LookupItem(key,value));
}

void Lookup::Remove(std::string key)
{
    for (auto it = _items.begin(); it != _items.end(); it++)
    {
        if (it->Key.compare(key) == 0)
        {
            _items.erase(it);
            return;
        }
    }

    LogDebug("No item with key found to delete. " + key);
}

void Lookup::Clear()
{
    _items.clear();
}

}