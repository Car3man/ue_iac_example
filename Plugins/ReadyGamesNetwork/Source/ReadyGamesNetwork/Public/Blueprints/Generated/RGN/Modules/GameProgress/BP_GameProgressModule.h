#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../Currency/BP_Currency.h"
#include "BP_OnGameCompleteResult.h"
#include "BP_OnGameCompleteRequestData.h"
#include "BP_GameProgress.h"
#include "../../Model/Request/BP_BaseMigrationRequestData.h"
#include "BP_AddUserLevelRequestData.h"
#include "BP_UpdateUserLevelRequestData.h"
#include "BP_UpdateUserLevelResponseData.h"
#include "BP_GetPlayerLevelResponseData.h"
#include "BP_GameProgressModule.generated.h"

DECLARE_DYNAMIC_DELEGATE_TwoParams(FGameProgressModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FGameProgressModuleOnGameCompleteAsyncResponse, const FBP_OnGameCompleteResult&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGameProgressModuleGetGameProgressAsyncResponse, const FBP_GameProgress&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGameProgressModuleAddUserProgressAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGameProgressModuleUpdateUserProgressAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGameProgressModuleGetUserProgressAsyncResponse, const FString&, response);

UCLASS()
class READYGAMESNETWORK_API UBP_GameProgressModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
};
