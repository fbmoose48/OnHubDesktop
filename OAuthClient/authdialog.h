#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <QDialog>
#include <QtWebEngineWidgets>
//#include "HTTP/requestmanager.h"
#include <QtNetwork>
//#include <QtWebEngineCore>
#include <QSysInfo>
#include "AuthenticationUtilities.h"
#include "Encryption/qaesencryption.h"

namespace Ui {
    class AuthDialog;
}

class AuthDialog : public QDialog {
Q_OBJECT

public:
    explicit AuthDialog(QWidget *parent = nullptr);

    ~AuthDialog();

    void doLoginPageRequest();


private:
    QString deviceName = QSysInfo::machineHostName();
    QString deviceId = AuthenticationUtilities::generateDeviceId();
    QString deviceChallenge = AuthenticationUtilities::generateChallenge();
    QString clientState = AuthenticationUtilities::generateClientState();
    Ui::AuthDialog *ui;
    QWebEngineView *view = new QWebEngineView();

    void launchWebEngine(QString authUri);

    void loginPageRequestComplete(QNetworkReply *reply);

    void cookieAdded(QNetworkCookie cookie);

    void saveRefreshToken(QNetworkReply *reply);
};

#endif // AUTHDIALOG_H
