#pragma once

#include <unordered_map>
#include "service_base.h"

// again, our engine, makes things easier and more readable
enum class ServiceType
{
    Entity = 0,
    Script = 1
};

//
// TODO:
// GetService needs rework, couldn't get it to work with templating like I wanted to
//

class DefaultService : public ServiceBase
{
public:
    void Initialize() override { }
    void Update(float time) override { }
    const int getId() override { return -1; }
};

class Services
{
    
public:

    Services() = default;
    ~Services();

    // still keep this an explicit call so that we can control when 
    void Initialize();

    void Add(ServiceBase* service);

    void Update(float time);

    // void* is ugly, will rework later
    void* GetService(ServiceType type);

private:

    DefaultService* _default;

    std::unordered_map<int, ServiceBase*> _services;

};