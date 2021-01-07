#pragma once

class ServiceBase
{

public:

    // will make lookup easier, we control whole engine so 
    // its every service's job to ensure id doesn't clash!
    virtual const int getId() = 0;

    virtual void Initialize() = 0;

    virtual void Update(float time) = 0;

};