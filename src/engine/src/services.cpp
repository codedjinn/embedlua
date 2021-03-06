
#include "services.h"

#include "logger.h"

#include <cassert>

Services::~Services()
{
    LogDebug("Deleting services...");

    for (auto& pair : _services)
    {
        if (pair.second != nullptr)
        {
            delete pair.second;
        }
    }

    LogDebug("DONE");
}

void Services::Add(ServiceBase* service)
{
    if (_services.find(service->getId()) == _services.end())
    {
        _services.insert(std::pair<int,ServiceBase*>(service->getId(), service));
    }
    else
    {
        std::string msg("Service with id '");
        msg.append(std::to_string(service->getId()));
        msg.append("' already added");
        LogError(msg);
    }    
}

void Services::Initialize()
{
    _default = new DefaultService();
    for (auto& service : _services)
    {
        service.second->Initialize();
    }
}

void Services::Update(float time)
{
    for (auto& service : _services)
    {
        service.second->Update(time);
    }
}


void* Services::GetService(ServiceType type)
{
    auto it = _services.find((int)type);
    if (it != _services.end())
    {
        return it->second;
    }
    return nullptr;
}