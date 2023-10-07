// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../VirtualItems/PriceInfo.h"
using json = nlohmann::json;
using namespace std;

namespace RGN { namespace Modules { namespace Store {
    struct LootBox {
        string id;
        string name;
        string appId;
        int64_t totalQuantity = 0;
        int64_t purchasedQuantity = 0;
        int64_t availableQuantity = 0;
        int64_t createdAt = 0;
        int64_t updatedAt = 0;
        string createdBy;
        string updatedBy;
        vector<RGN::Modules::VirtualItems::PriceInfo> prices;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(LootBox, id, name, appId, totalQuantity, purchasedQuantity, availableQuantity, createdAt, updatedAt, createdBy, updatedBy, prices)
    };
}}}