
#include "Godproj.h"
#include "DB_Equip.h"

static TMap<FString,FEquip> m_map;

UDB_Role::UDB_Equip()
{
     loadData();
}
bool UDB_Equip::loadData()
{
    m_map.Empty();
    FString path = FPaths::GameDir() + "Content/DB/DB_Equip.txt";
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
        FEquip dbS;

        dbS.id = FCString::Atoi(*array[0]);

        dbS.itemType = FCString::Atoi(*array[1]);

        dbS.itemName = *array[2];

        dbS.itemInfo = *array[3];

        m_map.Add(FString::FromInt(dbS.id), dbS);

    }
    return true;
}

FRole UDB_Equip::getEquipById(int32 _value);
{
    return m_map.FindRef(_value);
}
TMap<FString,FEquip> UDB_Equip::getAllEquipDB()()
{
    return m_map
}
