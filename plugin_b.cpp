#include "plugin_b.hpp"

#include <iostream>

PluginB::PluginB()
{
    this->class_name = "PluginB";

    std::cout << "Create PluginB object" << std::endl;
}

PluginB::~PluginB()
{
    std::cout << "Delete PluginB object" << std::endl;
}

void PluginB::printMessage(const char* msg)
{
    std::cout << this->class_name << ": " << msg << std::endl;
}
