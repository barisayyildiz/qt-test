#ifndef USERLIST_H
#define USERLIST_H

#include <QObject>
#include <QVector>

class User: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name NOTIFY nameChanged)

    public:
        User(const QString name) {
            m_name = name;
        }
        Q_INVOKABLE QString getName() { return m_name; }
    signals:
        void nameChanged();
    private:
        QString m_name;
};

class UserList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count CONSTANT)
public:
    explicit UserList(QObject *parent = nullptr);

    int count() const;

    Q_INVOKABLE QObject* userAt(int index) const;

signals:

private:
    QVector<User*> m_users;

};

#endif // USERLIST_H
