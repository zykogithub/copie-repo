#include <gtest/gtest.h>
#include "kataTDD.cpp"
#include <unordered_map>
#include <stdexcept>

TEST(helloTest, saysHelloWorld) {
  EXPECT_EQ(hello(),"Hello World!");
}

TEST(RomanToDecimalTest, IMShouldFail) {
  RomanToDecimal romanNumeral("KL");
  EXPECT_NO_FATAL_FAILURE(romanNumeral.getDecimal());
}
// question 4 : est ce que la lettre est bien une lettre romaine est bien dans map