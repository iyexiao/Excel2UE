
#pragma once
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DB_Enemy.generated.h"

USTRUCT(BlueprintType)
struct FEnemy
{
    GENERATED_USTRUCT_BODY()
public:
    FEnemy(){};
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DB")
    int32 id;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DB")
    int32 roleType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DB")
    int32 roleSex;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DB")
    FString roleInfo;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DB")
    bool isLock;

};

UCLASS(Blueprintable)
class GODPROJ_API UDB_Enemy : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:

    UDB_Enemy();
    ~UDB_Enemy(){};
    bool loadData();

    UFUNCTION(BlueprintCallable, Category = "DB")
    static FEnemy getEnemyById(int32 _value);
    UFUNCTION(BlueprintCallable, Category = "DB")
    static TMap<FString,FEnemy> getAllEnemyDB();
};
