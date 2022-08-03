#ifdef __APPLE__

#include "plugin_base.hpp"
#include <dlfcn.h>
#include <iostream>

int main(int argc, char** argv)
{
    const auto plugin_a_dl = dlopen("libplugin_a.dylib", RTLD_LAZY);
    auto plugin_a = (CreatePluginFunc*)(dlsym(plugin_a_dl, "create"));

    {
        const auto& plugin = plugin_a();
        plugin->printMessage("test");
    }

    dlclose(plugin_a_dl);
}

#endif
