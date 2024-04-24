/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, single_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zebra");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, four_letter_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZebra");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, thirteen_letter_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZZZZZZZZZZebra12");
	ASSERT_EQ(13, actual);
}

TEST(PasswordTest, number_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("12Zebra");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, character_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("!Zebra");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, character_repeated_later_in_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zebraz");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, capital_then_lowercase_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zzebra");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, both_uppercase_and_lowercase_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Aa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, only_lowercase_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aa");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_uppercase_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AA");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, random_uppercase_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("heLlo");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, full_normal_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Mypassword45!");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, yes_it_is_password)
{
	Password my_password;
	bool actual = my_password.authenticate("ChicoCA-95926");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, no_it_is_not_password)
{
	Password my_password;
	bool actual = my_password.authenticate("ChicoCA");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, authenticate_old_password)
{
	Password my_password;
	my_password.set("HelloThere");
	my_password.set("HelloThere12");
	my_password.set("HelloThere4!");
	my_password.set("HelloThere9.");
	bool actual = my_password.authenticate("HelloThere");
	ASSERT_EQ(false, actual);
} 

TEST(PasswordTest, authenticate_newest_password)
{
	Password my_password;
	my_password.set("HelloThere");
	my_password.set("HelloThere12");
	my_password.set("HelloThere4!");
	my_password.set("HelloThere9.");
	bool actual = my_password.authenticate("HelloThere9.");
	ASSERT_EQ(true, actual);
} 	