
#pragma once
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DB_Role.generated.h"

USTRUCT(BlueprintType)
struct FRole
{
    GENERATED_USTRUCT_BODY()
public:
    FRole(){};
    
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
class GODPROJ_API UDB_Role : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:

    UDB_Role();
    ~UDB_Role(){};
    bool loadData();

    UFUNCTION(BlueprintCallable, Category = "DB")
    static FRole getRoleById(int32 _value);
    UFUNCTION(BlueprintCallable, Category = "DB")
    static TMap<int32,FRole> getAllRoleDB();
};
