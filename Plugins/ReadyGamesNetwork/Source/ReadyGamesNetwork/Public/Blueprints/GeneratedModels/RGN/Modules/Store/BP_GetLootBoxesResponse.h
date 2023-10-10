#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "BP_LootBox.h"
#include "BP_GetLootBoxesResponse.generated.h"

USTRUCT(BlueprintType)
struct READYGAMESNETWORK_API FBP_GetLootBoxesResponse {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "ReadyGamesNetwork | Store")
    TArray<FBP_LootBox> lootBoxes;
};