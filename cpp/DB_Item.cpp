
#include "GodProj.h"
#include "DB_Item.h"

static TMap<FString,FItem> m_map;

UDB_Role::UDB_Item()
{
     loadData();
}
bool UDB_Item::loadData()
{
    m_map.Empty();
    FString path = FPaths::GameDir() + "Content/DB/DB_Item.txt";
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
        FItem dbS;

        dbS.id = *array[0];

        dbS.itemType = FCString::Atoi(*array[1]);

        dbS.itemName = *array[2];

        dbS.itemInfo = *array[3];

        m_map.Add(dbS.id, dbS);

    }
    return true;
}

FRole UDB_Item::getItemById(FString _value);
{
    return m_map.FindRef(_value);
}
TMap<FString,FItem> UDB_Item::getAllItemDB()()
{
    return m_map
}
