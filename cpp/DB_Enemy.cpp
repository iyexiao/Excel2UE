
#include "GodProj.h"
#include "DB_Enemy.h"

static TMap<int32,FEnemy> m_map;

UDB_Role::UDB_Enemy()
{
     loadData();
}
bool UDB_Enemy::loadData()
{
    m_map.Empty();
    FString path = FPaths::GameDir() + "Content/DB/DB_Enemy.txt";
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
        FEnemy dbS;

        dbS.id = FCString::Atoi(*array[0]);

        dbS.roleType = FCString::Atoi(*array[1]);

        dbS.roleSex = FCString::Atoi(*array[2]);

        dbS.roleInfo = *array[3];

        if (FCString::Atoi(*array[4]) == 1)
            dbS.isLock = true;
        else
            dbS.isLock = false;

        m_map.Add(dbS.id, dbS);

    }
    return true;
}

FRole UDB_Enemy::getEnemyById(int32 _value);
{
    return m_map.FindRef(_value);
}
TMap<int32,FEnemy> UDB_Enemy::getAllEnemyDB()()
{
    return m_map
}
