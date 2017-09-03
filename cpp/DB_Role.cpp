
#include "Godproj.h"
#include "DB_Role.h"

static TMap<FString,FRole> m_map;

UDB_Role::UDB_Role()
{
     loadData();
}
bool UDB_Role::loadData()
{
    m_map.Empty();
    FString path = FPaths::GameDir() + "Content/DB/DB_Role.txt";
    if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*path))
        return false;
    TArray<FString> db;
    FString contentStr;
    FFileHelper::LoadFileToString(contentStr,*path);
    contentStr.ParseIntoArray(db, TEXT("\n"), false);
    for (int i = 0; i < db.Num(); i++)
    {
        FString aString = db[i];
        TArray<FString> array = {};
        aString.ParseIntoArray(array, TEXT(","), false);
        FRole dbS;

        dbS.id = FCString::Atoi(*array[0]);

        dbS.roleType = FCString::Atoi(*array[1]);

        dbS.roleSex = FCString::Atoi(*array[2]);

        dbS.roleInfo = *array[3];

        if (FCString::Atoi(*array[4]) == 1)
            dbS.isLock = true;
        else
            dbS.isLock = false;

        m_map.Add(FString::FromInt(dbS.id), dbS);

    }
    return true;
}

FRole UDB_Role::getRoleById(int32 _value);
{
    return m_map.FindRef(_value);
}
TMap<FString,FRole> UDB_Role::getAllRoleDB()()
{
    return m_map
}
