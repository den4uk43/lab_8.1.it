#define _CRT_SECURE_NO_WARNINGS 

#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>
#pragma warning(push)
#pragma warning(disable: 4996)
#include "/ap_labs/lab8/lab8/lab8it.cpp"
#pragma warning(pop)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCountFunction)
        {
            // Тестові рядки з різною кількістю груп "***"
            char str1[] = "abc***def";       // 1 група
            char str2[] = "a***b***c***d";   // 3 групи
            char str3[] = "no stars here!";  // 0 груп
            char str4[] = "**";              // занадто короткий (< 3 символів)

            Assert::AreEqual(1, Count(str1));
            Assert::AreEqual(3, Count(str2));
            Assert::AreEqual(0, Count(str3));
            Assert::AreEqual(0, Count(str4));
        }

        // Тест для перевірки функції Change (заміна "***" на "!!")
        TEST_METHOD(TestChangeFunction)
        {
            // Використовуємо масиви з достатнім запасом пам'яті для зміни довжини
            char str1[50] = "abc***def";
            char expected1[] = "abc!!def";

            char str2[50] = "a***b***c";
            char expected2[] = "a!!b!!c";

            // Викликаємо функцію Change
            char* result1 = Change(str1);
            char* result2 = Change(str2);

            // Перевіряємо результати через Assert::AreEqual
            // Перевіряємо як сам змінений рядок (param), так і вказівник, що повернувся (result)
            Assert::AreEqual(expected1, str1);
            Assert::AreEqual(expected1, result1);

            Assert::AreEqual(expected2, str2);
            Assert::AreEqual(expected2, result2);
        }
	};
}
