#include <iostream>
#include <regex>
#include <string>
using namespace std;

void PrintMatches2(string str, regex reg)
{
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;
    while (currentMatch != lastMatch)
    {
        smatch match = *currentMatch;
        cout << match.str() << endl;
        currentMatch++;
    }
    cout << endl;
}

int main()
{
    string str = "This ape was at the apex";
    regex reg("(ape[^ ]?)");
    PrintMatches2(str, reg);

    string str1 = "I picked the pickle";
    regex reg1("(pick[^ ]+?)");
    PrintMatches2(str1, reg1);

    // match starting with crmfp and ending with at
    string str2 = "Cat rat mat fat pat";
    regex reg2("([crmfp]at)");
    PrintMatches2(str2, reg2);

    // Match words staring with C to f or c to f
    regex reg3("([C-Fc-f]at)");
    PrintMatches2(str2, reg3);

    // anything which is not starting with C and r
    regex reg4("([^Cr]at)");
    PrintMatches2(str2, reg4);

    // Replace Matches

    regex reg5("([Cr]at)");
    string owlFood = regex_replace(str2, reg5, "Owl");
    cout << "after replacemnt " << owlFood << endl;

    string str3 = "F.B.I. I.R.S. CIA";
    regex reg6("([^ ]\..\..\.)");
    PrintMatches2(str3, reg6);

    // Whitespace
    string str4 = "This is a\n miltiline string\n"
                  "that has many lines";

    regex reg7("\n");
    string noLBStr = regex_replace(str4, reg7, "|");
    cout << noLBStr << endl;

    // Single Numbers
    // \d [0-9]    ----> Match with Numbers
    // \D [^0-9]   ----> No Numbers

    string str8 = "12345";
    regex reg8("\\d");
    PrintMatches2(str8, reg8);

    // any of these having 5 to 7 digits in them in length
    string str9 = "123 12345 123456 123456 1234567";
    regex reg9("\\d{5,7}");
    PrintMatches2(str9, reg9);

    // match any single letter or digit
    // \w [a-zA-Z0-9]  --->any letter or digit
    // \W [^a-zA-Z0-9] ---> Except letter and digits

    string str10 = "412-867-5309";
    regex reg10("\\w{3}-\\w{3}-\\w{4}");
    PrintMatches2(str10, reg10);

    // word starting with a after ato z and has more than one
    string str11 = "a as ape bug";
    regex reg11("a[a-z]+");
    PrintMatches2(str11, reg11);

    string str12 = "db@aol.com m@.com @apple.com db@.com";
    regex reg12("[\\w._%+-]{1,20}@[\\w._%+-]{2,20}.[A-Za-z]{2,3}");
    PrintMatches2(str12, reg12);

    return 0;
}