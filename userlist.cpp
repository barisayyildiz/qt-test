#include "userlist.h"

UserList::UserList(QObject *parent)
    : QObject{parent}
{
    m_users << new User("Jane");
    m_users << new User("John");
    m_users << new User("Joe");
    m_users << new User("Jules");
}

int UserList::count() const {
    return m_users.count();
}

QObject* UserList::userAt(int index) const {
    if(index < 0 || index >= m_users.count())
        return 0;

    return m_users[index];
}

