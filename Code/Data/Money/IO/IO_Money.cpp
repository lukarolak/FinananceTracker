#include <Data/Money/IO/IO_Money.h>
#include <Error/Error.h>
std::optional<Money> IO_Money::ReadData(const rapidjson::Value& Data)
{
    if (Data.IsInt() == false)
    {
        AssertNoCrash("Data is of unexpected type");
        return {};
    }

    Money money;
    money.SetMoney(Data.GetInt());
    return money;
}
