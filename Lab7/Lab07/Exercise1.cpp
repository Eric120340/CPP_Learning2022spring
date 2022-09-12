#include <iostream>
#include <cstring>

struct stringy
{
    char *str;
    int ct;
};

void set(stringy &s, const char *str)
{
    s.str = new char[strlen(str) + 1];
    strcpy(s.str, str);
    s.ct = sizeof(str) / sizeof(char);
}

void show(stringy s, int i)
{
    while (i--)
        std::cout << s.str << std::endl;
}

void show(stringy s)
{
    show(s, 1);
}

void show(char *s, int i)
{
    while (i--)
        std::cout << s << std::endl;
}
void show(char *s)
{
    show(s, 1);
}

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);

    show(beany);
    show(beany, 2);

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    return 0;
}
