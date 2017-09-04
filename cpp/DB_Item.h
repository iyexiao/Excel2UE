
#pragma once
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DB_Item.generated.h"

USTRUCT(BlueprintType)
struct FItem
{
    GENERATED_USTRUCT_BODY()
public:
    FItem(){};
    
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
class GODPROJ_API UDB_Item : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:

    UDB_Item();
    ~UDB_Item(){};
    bool loadData();

    UFUNCTION(BlueprintCallable, Category = "DB")
    static FItem getItemById(int32 _value);
    UFUNCTION(BlueprintCallable, Category = "DB")
    static TMap<int32,FItem> getAllItemDB();
};
