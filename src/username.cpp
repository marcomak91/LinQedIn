#include"username.h"

Username::Username(string l, string p)
    : password(p), login(l) {}

string Username::getPassword() const
{
    return password;
}

void Username::setPassword(string p)
{
    password=p;
}
