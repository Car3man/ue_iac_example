#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../Utility/BaseMigrationRequestData.h"
using json = nlohmann::json;
using namespace std;

namespace RGN { namespace Modules { namespace GameProgress {
    template <class T>
    struct AddUserLevelRequestData : public RGN::Utility::BaseMigrationRequestData {
        T playerProgress;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(AddUserLevelRequestData, playerProgress)
    };
}}}