#include "../src/account.h"

#include <gtest/gtest.h>

using namespace CppSwift;

TEST(AccountTest, BasicTest) {
    EXPECT_EQ(true, static_cast<bool>(Account::login()));
}
