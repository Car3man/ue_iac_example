#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace RGN { namespace Modules { namespace UserProfile {
    struct UserCustomClaims {
        std::unordered_map<string, string> claims;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(UserCustomClaims, claims)
    };
}}}