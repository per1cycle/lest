#include "internal/lest-internal.h"

namespace lest
{
namespace testing
{
UnitTest* UnitTest::GetAllInstance()
{
    static UnitTest instance;
    return &instance;
}


}
}
