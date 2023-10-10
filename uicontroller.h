#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>

class UIController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isButtonClicked READ isButtonClicked WRITE setIsButtonClicked NOTIFY isButtonClickedChanged)
    Q_PROPERTY(int rotation READ rotation WRITE setRotation NOTIFY rotationChanged)
public:
    explicit UIController(QObject *parent = nullptr);
    bool isButtonClicked();
    int rotation();
    Q_INVOKABLE void setIsButtonClicked(bool isButtonClicked);
    Q_INVOKABLE void setRotation(bool clockwise);

signals:
    void isButtonClickedChanged();
    void rotationChanged();

private:
    bool m_isButtonClicked;
    int m_rotation;


};

#endif // UICONTROLLER_H
