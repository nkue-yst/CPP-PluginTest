#pragma once

#include "plugin_base.hpp"
#include <memory>

class PluginB : public PluginBase
{
public:
    PluginB();
    ~PluginB();

    void printMessage(const char* msg) override;
};

extern "C"
{
    std::unique_ptr<PluginBase> create()
    {
        return std::unique_ptr<PluginBase>(new PluginB);
    }
}
