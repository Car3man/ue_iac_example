#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "../../Utility/BP_BaseMigrationRequestData.h"
#include "BP_CreateWalletRequestData.generated.h"

USTRUCT(BlueprintType)
struct READYGAMESNETWORK_API FBP_CreateWalletRequestData : public FBP_BaseMigrationRequestData {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "ReadyGamesNetwork | Wallets")
    FString token;
    UPROPERTY(BlueprintReadOnly, Category = "ReadyGamesNetwork | Wallets")
    FString password;
};
