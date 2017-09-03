
#pragma once
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DB_Equip.generated.h"

USTRUCT(BlueprintType)
struct FEquip
{
    GENERATED_USTRUCT_BODY()
public:
    FEquip(){};
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DB")
    int32 id;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DB")
    int32 itemType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DB")
    FString itemName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DB")
    FString itemInfo;

};

UCLASS(Blueprintable)
class GODPROJ_API UDB_Equip : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:

    UDB_Equip();
    ~UDB_Equip(){};
    bool loadData();

    UFUNCTION(BlueprintCallable, Category = "DB")
    static FEquip getEquipById(int32 _value);
    UFUNCTION(BlueprintCallable, Category = "DB")
    static TMap<FString,FEquip> getAllEquipDB();
};
