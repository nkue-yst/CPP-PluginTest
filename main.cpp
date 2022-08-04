#include "plugin_base.hpp"

#include <dlfcn.h>
#include <filesystem>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

typedef std::unique_ptr<PluginBase> PluginCreateFunc();

const std::string extention =
    #ifdef __APPLE__
    ".dylib";
    #elif __linux__
    ".so";
    #endif

int main(int argc, char** argv)
{
    std::vector<std::string> plugins;
    auto dirs = std::filesystem::directory_iterator(std::filesystem::path("./"));
    for (auto& dir : dirs)
    {
        std::string path = dir.path().string();
        if (path.find(extention.c_str()) != std::string::npos)
        {
            plugins.push_back(path);
        }
    }

    for (auto plugin : plugins)
    {
        void* plugin_dl = dlopen(plugin.c_str(), RTLD_LAZY);
        auto CreatePlugin = (PluginCreateFunc*)(dlsym(plugin_dl, "create"));

        {
            const auto& plugin_instance = CreatePlugin();

            plugin_instance->printMessage("test");
        }

        dlclose(plugin_dl);
    }
}
