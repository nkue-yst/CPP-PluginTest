#ifdef __APPLE__

#include "plugin_base.hpp"
#include <dlfcn.h>
#include <iostream>
#include <memory>

typedef std::unique_ptr<PluginBase> PluginCreateFunc();

int main(int argc, char** argv)
{
    const auto pluginA_dl = dlopen("libplugin_a.dylib", RTLD_LAZY);
    auto pluginA_create = (PluginCreateFunc*)(dlsym(pluginA_dl, "create"));

    {
        const auto& plugin = pluginA_create();

        plugin->printMessage("test");
    }

    dlclose(pluginA_dl);
}

#endif
