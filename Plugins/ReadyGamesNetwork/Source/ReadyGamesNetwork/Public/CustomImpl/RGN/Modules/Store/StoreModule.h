#pragma once

#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Generated/RGN/Modules/Store/BuyVirtualItemsResponse.h"
#include "../../../../Generated/RGN/Modules/Store/BuyStoreOfferResponse.h"
#include "../../../../Generated/RGN/Modules/Store/GetLootBoxesResponse.h"
#include "../../../../Generated/RGN/Modules/Store/GetStoreOffersResponse.h"
#include "../../../../Generated/RGN/Modules/Store/GetStoreOffersWithVirtualItemsDataResponse.h"
#include "../../../../Generated/RGN/Modules/Store/PurchaseItem.h"
#include "../../../../Generated/RGN/Modules/Store/PurchaseResult.h"
#include "../../../../Generated/RGN/Modules/Store/StoreOffer.h"
#include "../../../../Generated/RGN/Modules/Inventory/InventoryItemData.h"
#include <string>

namespace RGN { namespace Modules { namespace Store {
	class StoreModuleCustomImpl {
	public:
        static void GetLootBoxesForCurrentAppAsync(
            int32_t limit,
            string startAfter,
            const function<void(vector<RGN::Modules::Store::LootBox> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetLootBoxesResponse>(
                    "storeV2-getLootBoxesByAppId",
                    requestData,
                    [complete](RGN::Modules::Store::GetLootBoxesResponse result) {
                        complete(result.lootBoxes);
                    },
                    fail
                );
            };
        static void OpenLootboxAsync(
            string name,
            const function<void(RGN::Modules::Inventory::InventoryItemData result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["name"] = name;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::PurchaseItem>(
                    "storeV2-openLootBox",
                    requestData,
                    [complete](RGN::Modules::Store::PurchaseItem result) {
                        RGN::Modules::Inventory::InventoryItemData inventoryItemData;
                        inventoryItemData.id = result.inventoryItem.id;
                        inventoryItemData.virtualItemId = result.virtualItem.id;
                        inventoryItemData.appIds = result.inventoryItem.appIds;
                        inventoryItemData.tags = result.inventoryItem.tags;
                        inventoryItemData.quantity = result.inventoryItem.quantity;
                        inventoryItemData.status = result.inventoryItem.status;
                        inventoryItemData.itemUpgrades = result.inventoryItem.itemUpgrades;
                        inventoryItemData.properties = result.inventoryItem.properties;
                        inventoryItemData.virtualItem = result.virtualItem;
                        complete(inventoryItemData);
                    },
                fail);
            };
        static void GetForCurrentAppAsync(
            int32_t limit,
            string startAfter,
            bool ignoreTimestamp,
            const function<void(vector<RGN::Modules::Store::StoreOffer> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["appIds"] = { RGNCore::GetAppId() };
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                requestData["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetStoreOffersResponse>(
                    "storeV2-getByAppIds",
                    requestData,
                    [complete](RGN::Modules::Store::GetStoreOffersResponse result) {
                        complete(result.offers);
                    },
                    fail
                );
            };
        static void GetWithVirtualItemsDataForCurrentAppAsync(
            int32_t limit,
            string startAfter,
            bool ignoreTimestamp,
            const function<void(vector<RGN::Modules::Store::StoreOffer> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                GetWithVirtualItemsDataByAppIdsAsync(
                    { RGNCore::GetAppId() },
                    limit,
                    startAfter,
                    ignoreTimestamp,
                    complete,
                    fail
                );
            };
        static void GetWithVirtualItemsDataByAppIdsAsync(
            std::vector<std::string> appIds,
            int32_t limit,
            std::string startAfter,
            bool ignoreTimestamp,
            const std::function<void(std::vector<RGN::Modules::Store::StoreOffer> result)>& complete,
            const std::function<void(int httpCode, std::string error)>& fail) {
                nlohmann::json bodyJson;
                bodyJson["appId"] = RGNCore::GetAppId();
                bodyJson["appIds"] = appIds;
                bodyJson["limit"] = limit;
                bodyJson["startAfter"] = startAfter;
                bodyJson["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetStoreOffersWithVirtualItemsDataResponse>
                ("storeV2-getWithVirtualItemsDataByAppIds", bodyJson,
                    [complete](RGN::Modules::Store::GetStoreOffersWithVirtualItemsDataResponse response) {
                        std::vector<RGN::Modules::Store::StoreOffer> queriedOffers = response.offers;
                        std::vector<RGN::Modules::VirtualItems::VirtualItem> virtualItems = response.virtualItems;
                        for (StoreOffer& storeOffer : queriedOffers) {
                            std::vector<RGN::Modules::VirtualItems::VirtualItem> items;
                            for (std::string& itemId : storeOffer.itemIds) {
                                for (RGN::Modules::VirtualItems::VirtualItem& item : items) {
                                    if (item.id == itemId) {
                                        items.push_back(item);
                                        break;
                                    }
                                }
                            }
                            storeOffer.virtualItems = items;
                        }
                        complete(queriedOffers);
                    },
                    fail
                );
            };
        static void BuyVirtualItemsAsync(
            std::vector<string> itemIds,
            std::vector<string> currencies,
            std::string offerId,
            const std::function<void(RGN::Modules::Store::PurchaseResult result)>& complete,
            const std::function<void(int httpCode, std::string error)>& fail) {
                nlohmann::json bodyJson;
                bodyJson["appId"] = RGNCore::GetAppId();
                bodyJson["itemIds"] = itemIds;
                bodyJson["currencies"] = currencies;
                bodyJson["offerId"] = offerId;
                bodyJson["version"] = 2;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::BuyVirtualItemsResponse>
                    ("storeV2-buyVirtualItems", bodyJson,
                    [offerId, complete](RGN::Modules::Store::BuyVirtualItemsResponse response) {
                        std::vector<RGN::Modules::Inventory::InventoryItemData> inventoryItems;
                        for (RGN::Modules::Store::PurchaseItem& purchaseItem : response.purchasedItems) {
                            RGN::Modules::Inventory::InventoryItemData inventoryItem;
                            inventoryItem.id = purchaseItem.inventoryItem.id;
                            inventoryItem.virtualItemId = purchaseItem.virtualItem.id;
                            inventoryItem.appIds = purchaseItem.inventoryItem.appIds;
                            inventoryItem.tags = purchaseItem.inventoryItem.tags;
                            inventoryItem.quantity = purchaseItem.inventoryItem.quantity;
                            inventoryItem.status = purchaseItem.inventoryItem.status;
                            inventoryItem.itemUpgrades = purchaseItem.inventoryItem.itemUpgrades;
                            inventoryItem.properties = purchaseItem.inventoryItem.properties;
                            inventoryItem.virtualItem = purchaseItem.virtualItem;
                            inventoryItems.push_back(inventoryItem);
                        }
                        RGN::Modules::Store::PurchaseResult purchaseResult;
                        purchaseResult.offerId = offerId;
                        purchaseResult.items = inventoryItems;
                        purchaseResult.updatedCurrencies = response.updatedCurrencies;
                        complete(purchaseResult);
                    },
                fail);
            };
        static void BuyStoreOfferAsync(
            std::string offerId,
            std::vector<std::string> currencies,
            const std::function<void(RGN::Modules::Store::PurchaseResult result)>& complete,
            const std::function<void(int httpCode, std::string error)>& fail) {
                nlohmann::json bodyJson;
                bodyJson["appId"] = RGNCore::GetAppId();
                bodyJson["offerId"] = offerId;
                bodyJson["currencies"] = currencies;
                bodyJson["version"] = 2;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::BuyStoreOfferResponse>
                    ("storeV2-buyStoreOffer", bodyJson,
                    [offerId, complete](RGN::Modules::Store::BuyStoreOfferResponse response) {
                        std::vector<RGN::Modules::Inventory::InventoryItemData> inventoryItems;
                        for (RGN::Modules::Store::PurchaseItem& purchaseItem : response.purchasedItems) {
                            RGN::Modules::Inventory::InventoryItemData inventoryItem;
                            inventoryItem.id = purchaseItem.inventoryItem.id;
                            inventoryItem.virtualItemId = purchaseItem.virtualItem.id;
                            inventoryItem.appIds = purchaseItem.inventoryItem.appIds;
                            inventoryItem.tags = purchaseItem.inventoryItem.tags;
                            inventoryItem.quantity = purchaseItem.inventoryItem.quantity;
                            inventoryItem.status = purchaseItem.inventoryItem.status;
                            inventoryItem.itemUpgrades = purchaseItem.inventoryItem.itemUpgrades;
                            inventoryItem.properties = purchaseItem.inventoryItem.properties;
                            inventoryItem.virtualItem = purchaseItem.virtualItem;
                            inventoryItems.push_back(inventoryItem);
                        }
                        RGN::Modules::Store::PurchaseResult purchaseResult;
                        purchaseResult.offerId = offerId;
                        purchaseResult.items = inventoryItems;
                        purchaseResult.updatedCurrencies = response.updatedCurrencies;
                        complete(purchaseResult);
                    },
                fail);
            };
	};
}}}