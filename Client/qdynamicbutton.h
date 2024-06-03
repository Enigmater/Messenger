#ifndef QDYNAMICBYTTONN_H
#define QDYNAMICBYTTONN_H

#include <QPushButton>

class QDynamicButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QDynamicButton(QWidget* parent = nullptr);
    ~QDynamicButton();
    static int resID;

    int GetID();
    void SetChatID(int id) {this->chatID = id;}
    int GetChatID() {return this->chatID;}

    void setType(bool type) {this->type = type;}
    bool isPublic() {return this->type;}

private:
    int buttonID = 0;
    int chatID = 0;
    bool type;
};

#endif // QDYNAMICBYTTONN_H
