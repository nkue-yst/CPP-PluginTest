#pragma once

#include "plugin_base.hpp"
#include <memory>

class PluginA : public PluginBase
{
public:
    PluginA();
    ~PluginA();

    void printMessage(const char* msg) override;
};

extern "C"
{
    std::unique_ptr<PluginBase> create()
    {
        return std::unique_ptr<PluginBase>(new PluginA);
    }
}
