#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../..//Core/RGNCore.h"
#include "../../Model/Request/BaseMigrationRequestData.h"
#include "VirtualItem.h"
#include "../../Model/ImageSize.h"
#include <string>
#include <functional>
using json = nlohmann::json;
using namespace std;

namespace RGN { namespace Modules { namespace VirtualItems {
    class VirtualItemsModule {
    public:
        static void AddVirtualItemAsync(
            RGN::Modules::VirtualItems::VirtualItem virtualItem,
            const function<void(RGN::Modules::VirtualItems::VirtualItem result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
            };
        static void AddFromCSVAsync(
            string virtualItemName,
            string csvContent,
            string csvDelimiter,
            System::Threading::CancellationToken cancellationToken,
            const function<void(vector<string> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemName"] = virtualItemName;
                requestData["csvFileString"] = csvContent;
                requestData["delimiter"] = csvDelimiter;
                RGNCore::CallAPI("virtualItemsV2-addFromCSV", requestData, complete, fail);
            };
        static void UpdateVirtualItemAsync(
            string itemId,
            RGN::Modules::VirtualItems::VirtualItem virtualItem,
            const function<void(RGN::Modules::VirtualItems::VirtualItem result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
            };
        static void DeleteVirtualItemAsync(
            string itemId,
            const function<void(void)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["itemId"] = itemId;
                RGNCore::CallAPI("virtualItemsV2-deleteVirtualItem", requestData, complete, fail);
            };
        static void GetVirtualItemsAsync(
            const function<void(vector<RGN::Modules::VirtualItems::VirtualItem> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
            };
        static void GetVirtualItemsAsync(
            int32_t limit,
            string startAfter,
            const function<void(vector<RGN::Modules::VirtualItems::VirtualItem> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
            };
        static void GetVirtualItemsByIdsAsync(
            vector<string> virtualItemsIds,
            const function<void(vector<RGN::Modules::VirtualItems::VirtualItem> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
            };
        static void GetByTagsAsync(
            vector<string> tags,
            string appId,
            const function<void(vector<RGN::Modules::VirtualItems::VirtualItem> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["tags"] = tags;
                requestData["optionalAppId"] = appId;
                RGNCore::CallAPI("virtualItemsV2-getByTags", requestData, complete, fail);
            };
        static void GetTagsAsync(
            string virtualItemId,
            const function<void(vector<string> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI("virtualItemsV2-getTags", requestData, complete, fail);
            };
        static void SetTagsAsync(
            string virtualItemId,
            vector<string> tags,
            string appId,
            const function<void(void)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["tags"] = tags;
                requestData["optionalAppId"] = appId;
                RGNCore::CallAPI("virtualItemsV2-setTags", requestData, complete, fail);
            };
        static void SetNameAsync(
            string virtualItemId,
            string name,
            const function<void(void)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["name"] = name;
                RGNCore::CallAPI("virtualItemsV2-setName", requestData, complete, fail);
            };
        static void SetDescriptionAsync(
            string virtualItemId,
            string description,
            const function<void(void)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["description"] = description;
                RGNCore::CallAPI("virtualItemsV2-setDescription", requestData, complete, fail);
            };
        static void GetPropertiesAsync(
            string virtualItemId,
            const function<void(string result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI("virtualItemsV2-getProperties", requestData, complete, fail);
            };
        static void SetPropertiesAsync(
            string virtualItemId,
            string json,
            const function<void(string result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["json"] = json;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI("virtualItemsV2-setProperties", requestData, complete, fail);
            };
        static void UploadImageAsync(
            string virtualItemId,
            vector<byte> thumbnailTextureBytes,
            System::Threading::CancellationToken cancellationToken,
            const function<void(bool result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["base64String"] = base64String;
                RGNCore::CallAPI("virtualItemsV2-uploadThumbnail", requestData, complete, fail);
            };
        static void DownloadImageAsync(
            string virtualItemId,
            RGN::Model::ImageSize size,
            System::Threading::CancellationToken cancellationToken,
            const function<void(vector<byte> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
            };
        static void UploadMaterialTexturesAsync(
            string virtualItemId,
            vector<vector<byte>> materialTexturesBytes,
            System::Threading::CancellationToken cancellationToken,
            const function<void(bool result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["texturesInfos"] = allMaterialTextures;
                RGNCore::CallAPI("virtualItemsV2-uploadTextures", requestData, complete, fail);
            };
        static void DownloadMaterialTexturesAsync(
            string virtualItemId,
            System::Threading::CancellationToken cancellationToken,
            const function<void(vector<vector<byte>> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
            };
    };
}}}