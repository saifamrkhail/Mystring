#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <gtest/gtest.h>
#include "Mystring.h"

/*
* =================================================
* Constructors
* =================================================
*/
TEST(MystringTest, default_constructor) {
    Mystring myemptystring = Mystring();
    EXPECT_EQ(0, myemptystring.size());
    ASSERT_STREQ("", myemptystring.c_str());

    using namespace std;
    string emptystring = string();
    EXPECT_EQ(0, emptystring.length());
    ASSERT_STREQ("", emptystring.c_str());
}

TEST(MystringTest, constructor) {
    Mystring myhello("Hello");
    ASSERT_STREQ("Hello", myhello.c_str());

    using namespace std;
    string hello("Hello");
    ASSERT_STREQ("Hello", myhello.c_str());
}

TEST(MystringTest, copy_constructor) {
    Mystring myhello("Hello");
    Mystring myhello_copy(myhello);
    ASSERT_STREQ(myhello.c_str(), myhello_copy.c_str());
    ASSERT_FALSE(myhello == NULL);

    using namespace std;
    string hello("Hello");
    string hello_copy(hello);
    ASSERT_STREQ(hello.c_str(), hello_copy.c_str());
    ASSERT_STREQ("Hello", hello.c_str());
}

TEST(MystringTest, move_constructor) {
    Mystring myhello("Hello");
    Mystring myhello_moved = std::move(myhello);
    ASSERT_STREQ("Hello", myhello_moved.c_str());
    ASSERT_TRUE(myhello == NULL);
    ASSERT_TRUE(myhello == nullptr);

    using namespace std;
    string hello("Hello");
    string hello_moved = std::move(hello);
    ASSERT_STREQ("Hello", hello_moved.c_str());
    ASSERT_TRUE(hello == "");
}

/*
* =================================================
* Operators
* =================================================
*/

TEST(MystringTest, copy_assignment) {

    Mystring myhello("Hello"), myworld("World");
    myhello = myworld;
    ASSERT_STREQ("World", myhello.c_str());
    ASSERT_STREQ("World", myworld.c_str());

    using namespace std;
    string hello("Hello"), world("World");
    hello = world;
    ASSERT_STREQ("World", hello.c_str());
    ASSERT_STREQ("World", world.c_str());
}

TEST(MystringTest, move_assignment) {
    Mystring myhello("Hello"), myworld("World");
    myhello = std::move(myworld);
    ASSERT_STREQ("World", myhello.c_str());
    ASSERT_TRUE(myworld == NULL);

    using namespace std;
    string hello("Hello"), world("World");
    hello = move(world);
    ASSERT_STREQ("World", hello.c_str());
    ASSERT_STREQ("", world.c_str());
}


TEST(MystringTest, plus_operator) {
    Mystring myhello("Hello"), myworld("World");
    myhello = myhello + myworld;
    ASSERT_STREQ("HelloWorld", myhello.c_str());
    ASSERT_STREQ("World", myworld.c_str());

    Mystring myhello2("Hello");
    myhello2 = myhello2 + "World";
    ASSERT_STREQ("HelloWorld", myhello2.c_str());

    using namespace std;
    string hello("Hello"), world("World");
    hello = hello.operator+=(world);
    ASSERT_STREQ("HelloWorld", hello.c_str());
    ASSERT_STREQ("World", world.c_str());
}

TEST(MystringTest, plus_equal_operator) {
    Mystring myhello("Hello"), myworld("World");
    myhello += myworld;
    ASSERT_STREQ("HelloWorld", myhello.c_str());
    ASSERT_STREQ("World", myworld.c_str());

    Mystring myhello2("Hello");
    myhello2 += "World";
    ASSERT_STREQ("HelloWorld", myhello2.c_str());

    using namespace std;
    string hello("Hello"), world("World");
    hello = hello.operator+=(world);
    ASSERT_STREQ("HelloWorld", hello.c_str());
    ASSERT_STREQ("World", world.c_str());
}

TEST(MystringTest, conversion_function) {
    Mystring myhello("Hello");
    ASSERT_EQ(myhello.size() + 1, puts(myhello));
}

TEST(MystringTest, append) {
    Mystring myhello("Hello"), myworld("World");
    myhello.append(myworld);
    ASSERT_STREQ("HelloWorld", myhello.c_str());
    ASSERT_STREQ("World", myworld.c_str());

    Mystring myhello2("Hello");
    myhello2.append("World");
    ASSERT_STREQ("HelloWorld", myhello2.c_str());

    using namespace std;
    string hello("Hello"), world("World");
    hello.append(world);
    ASSERT_STREQ("HelloWorld", hello.c_str());
    ASSERT_STREQ("World", world.c_str());
}

TEST(MystringTest, c_str) {
    Mystring myhello("Hello");
    ASSERT_STREQ("Hello", myhello.c_str());

    using namespace std;
    string hello("Hello");
    ASSERT_STREQ("Hello", hello.c_str());
}

TEST(MystringTest, size) {
    Mystring myhello("Hello");
    ASSERT_EQ(5, myhello.size());

    using namespace std;
    string hello("Hello");
    ASSERT_EQ(5, hello.length());
}

TEST(MystringTest, begin) {
    Mystring myhelloworld("Hello World");

    int i = 0;

    for (Mystring::Myiterator it = myhelloworld.begin(); it != myhelloworld.end(); ++it) {
        ASSERT_TRUE(myhelloworld[i++] == *it);
    }

    ASSERT_EQ(1, (std::find(myhelloworld.begin(), myhelloworld.end(), 'W') != myhelloworld.end()));
}

int main(int argc, char *argv[]) {

    //Teil 1
    Mystring myString("Hello");
    myString.append("World");
    myString.append(myString);
    Mystring otherString(myString);
    Mystring yetAnotherString("AnotherWorld");
    otherString = yetAnotherString;
    std::cout << otherString.c_str();

    // Teil 2
    Mystring s1("Hello");
    const Mystring s2("World");
    s1 += s2;
    Mystring s3 = s1 + s2;
    s3 += "Hello";
    const Mystring s4 = s3 + "World";
    puts(s4);

    //Teil 3
    const Mystring test("Hello World");
    for (Mystring::Myiterator it = test.begin(); it != test.end(); ++it){ std::cout << *it << '\n';}
    std::cout << (std::find(test.begin(), test.end(), 'W') != test.end()) << '\n';

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
