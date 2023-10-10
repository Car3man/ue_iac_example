#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "../../Utility/BP_BaseMigrationRequestData.h"
#include "BP_GetUserProfileRequestData.generated.h"

USTRUCT(BlueprintType)
struct READYGAMESNETWORK_API FBP_GetUserProfileRequestData : public FBP_BaseMigrationRequestData {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "ReadyGamesNetwork | UserProfile")
    FString userId;
};