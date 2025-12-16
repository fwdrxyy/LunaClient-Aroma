#pragma once

#include <memory>
#include <string>

#include <utils/Logger.h>
#include <utils/Types.h>
#include <utils/xUtils.h>

#include "LunaModule.h"

class LunaCategory {
public:
    LunaCategory(const std::string &_name) {
        this->name  = _name;
        this->index = 0;
    }

    void addModule(std::unique_ptr<LunaModule> module) {
        std::string moduleName = module->name;
        this->modules.push_back(std::move(module));
        DEBUG_FUNCTION_LINE("Module \"%s\" added to category \"%s\"", moduleName.c_str(), this->name.c_str());
    }

    std::string name;
    int32_t index;
    xVector<std::unique_ptr<LunaModule>> modules;
};
