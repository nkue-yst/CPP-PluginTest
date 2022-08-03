#include "plugin_a.hpp"

#include <iostream>

PluginA::PluginA()
{
    this->class_name = "PluginA";

    std::cout << "Create PluginA object" << std::endl;
}

PluginA::~PluginA()
{
    std::cout << "Delete PluginA object" << std::endl;
}

void PluginA::printMessage(const char* msg)
{
    std::cout << this->class_name << ": " << msg << std::endl;
}
