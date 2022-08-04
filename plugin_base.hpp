#pragma once

#include <string>

class PluginBase
{
public:
    virtual ~PluginBase() = default;

    virtual void printMessage(const char* msg) = 0;

    const std::string getClass() { return this->class_name; }

protected:
    std::string class_name = "PluginBase";
};
