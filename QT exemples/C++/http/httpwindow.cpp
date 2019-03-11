#include <QtWidgets>
#include <QtNetwork>
#include <QUrl>
#include <QDebug>
#include "httpwindow.h"
#include "ui_authenticationdialog.h"
#include <QNetworkCookie>
#if QT_CONFIG(ssl)
//const char defaultUrl[] = "https://www.qt.io/";
//const char defaultUrl[] = "https://e.mail.ru/messages/inbox?back=1&back=1&from=mail.login&back=1";
//const char defaultUrl[] ="https://gitlab.com/users/sign_in";
//const char defaultUrl[] ="https://gitlab.com/Sergey_Timofeev/cpp_3_task-";
//const char defaultUrl[] = "http://www.cyberforum.ru/login.php";
const char defaultUrl[] = "http://www.cyberforum.ru/log-in.php";
 //const char defaultUrl[] = "http://www.cyberforum.ru/usercp.php";
//const char defaultUrl[] = "https://accounts.google.com/signin/v2/identifier?passive=1209600&continue=https%3A%2F%2Faccounts.google.com%2FManageAccount&followup=https%3A%2F%2Faccounts.google.com%2FManageAccount&flowName=GlifWebSignIn&flowEntry=ServiceLogin";
//const char defaultUrl[] = "https://mail.ru";
const char defaultUsername[] = "alkimand@mail.ru";
const char defaultUserPas[] = "qwertyop";
#else
const char defaultUrl[] = "http://www.qt.io/";
#endif
const char defaultFileName[] = "index.html";

ProgressDialog::ProgressDialog(const QUrl &url, QWidget *parent)
  : QProgressDialog(parent)
{
    setWindowTitle(tr("Download Progress"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setLabelText(tr("Downloading %1.").arg(url.toDisplayString()));
    setMinimum(0);
    setValue(0);
    setMinimumDuration(0);
    setMinimumSize(QSize(400, 75));
}

void ProgressDialog::networkReplyProgress(qint64 bytesRead, qint64 totalBytes)
{
    setMaximum(totalBytes);
    setValue(bytesRead);
}

HttpWindow::HttpWindow(QWidget *parent)
    : QDialog(parent)
    , statusLabel(new QLabel(tr("Please enter the URL of a file you want to download.\n\n"), this))
    , urlLineEdit(new QLineEdit(defaultUrl))
    , downloadButton(new QPushButton(tr("Download")))
    , launchCheckBox(new QCheckBox("Launch file"))
    , defaultFileLineEdit(new QLineEdit(defaultFileName))
    , downloadDirectoryLineEdit(new QLineEdit)
    , reply(nullptr)
    , file(nullptr)
    , httpRequestAborted(false)
{
     qnam = new QNetworkAccessManager();
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle(tr("HTTP"));

    connect(qnam, &QNetworkAccessManager::authenticationRequired,
            this, &HttpWindow::slotAuthenticationRequired);
#ifndef QT_NO_SSL
    connect(qnam, &QNetworkAccessManager::sslErrors,
            this, &HttpWindow::sslErrors);
#endif

    QFormLayout *formLayout = new QFormLayout;
    urlLineEdit->setClearButtonEnabled(true);
    connect(urlLineEdit, &QLineEdit::textChanged,
            this, &HttpWindow::enableDownloadButton);
    formLayout->addRow(tr("&URL:"), urlLineEdit);
    QString downloadDirectory = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    downloadDirectory ="C:/temp";
    if (downloadDirectory.isEmpty() || !QFileInfo(downloadDirectory).isDir())
        downloadDirectory = QDir::currentPath();
    downloadDirectoryLineEdit->setText(QDir::toNativeSeparators(downloadDirectory));
    formLayout->addRow(tr("&Download directory:"), downloadDirectoryLineEdit);
    formLayout->addRow(tr("Default &file:"), defaultFileLineEdit);
    launchCheckBox->setChecked(true);
    formLayout->addRow(launchCheckBox);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);

    mainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));

    statusLabel->setWordWrap(true);
    mainLayout->addWidget(statusLabel);

    downloadButton->setDefault(true);
    connect(downloadButton, &QAbstractButton::clicked, this, &HttpWindow::downloadFile);
    QPushButton *quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);
    connect(quitButton, &QAbstractButton::clicked, this, &QWidget::close);
    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton(downloadButton, QDialogButtonBox::ActionRole);
    QPushButton *setPathButton = new QPushButton(tr("SetPath"));
    connect(setPathButton, &QAbstractButton::clicked, this, &HttpWindow::downloadFile2);
    buttonBox->addButton(setPathButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);
    mainLayout->addWidget(buttonBox);

    urlLineEdit->setFocus();
}

void HttpWindow::startRequest(const QUrl &requestedUrl)
{
    qDebug () << " HttpWindow::startReques " ;
    qDebug () << "requestedUrl = " << requestedUrl.toString();
    url = requestedUrl;
    url.setUserName(defaultUsername);
    url.setPassword(defaultUserPas);
    httpRequestAborted = false;


    reply = qnam->get(QNetworkRequest(url));
    connect(reply, &QNetworkReply::finished, this, &HttpWindow::httpFinished);
    connect(reply, &QIODevice::readyRead, this, &HttpWindow::httpReadyRead);

    ProgressDialog *progressDialog = new ProgressDialog(url, this);
    progressDialog->setAttribute(Qt::WA_DeleteOnClose);
    connect(progressDialog, &QProgressDialog::canceled, this, &HttpWindow::cancelDownload);
    connect(reply, &QNetworkReply::downloadProgress, progressDialog, &ProgressDialog::networkReplyProgress);
    connect(reply, &QNetworkReply::finished, progressDialog, &ProgressDialog::hide);
    progressDialog->show();

    statusLabel->setText(tr("Downloading %1...").arg(url.toString()));
}

void HttpWindow::downloadFile()
{
    const QString urlSpec = urlLineEdit->text().trimmed();
    if (urlSpec.isEmpty())
        return;

    const QUrl newUrl = QUrl::fromUserInput(urlSpec);
    if (!newUrl.isValid()) {
        QMessageBox::information(this, tr("Error"),
                                 tr("Invalid URL: %1: %2").arg(urlSpec, newUrl.errorString()));
        return;
    }

    QString fileName = newUrl.fileName();
    //if (fileName.isEmpty())
        //fileName = defaultFileLineEdit->text().trimmed();
        fileName = defaultFileLineEdit->text().trimmed();
    //qDebug()<< "defaultFileLineEdit->text()" << defaultFileLineEdit->text();

    if (fileName.isEmpty())
        fileName = defaultFileName;
    QString downloadDirectory = QDir::cleanPath(downloadDirectoryLineEdit->text().trimmed());
    bool useDirectory = !downloadDirectory.isEmpty() && QFileInfo(downloadDirectory).isDir();
    if (useDirectory)
        fileName.prepend(downloadDirectory + '/');
    if (QFile::exists(fileName)) {
        if (QMessageBox::question(this, tr("Overwrite Existing File"),
                                  tr("There already exists a file called %1%2."
                                     " Overwrite?")
                                     .arg(fileName,
                                          useDirectory
                                           ? QString()
                                           : QStringLiteral(" in the current directory")),
                                     QMessageBox::Yes | QMessageBox::No,
                                     QMessageBox::No)
            == QMessageBox::No) {
            return;
        }
        QFile::remove(fileName);
    }

    file = openFileForWrite(fileName);
    if (!file)
        return;

    downloadButton->setEnabled(false);

    // schedule the request
    startRequest(newUrl);
}
void HttpWindow::downloadFile2()
{
    qDebug () << "HttpWindow::downloadFile2()";
    const QString urlSpec = urlLineEdit->text().trimmed();
    if (urlSpec.isEmpty())
        return;

    const QUrl newUrl = QUrl::fromUserInput(urlSpec);
    if (!newUrl.isValid()) {
        QMessageBox::information(this, tr("Error"),
                                 tr("Invalid URL: %1: %2").arg(urlSpec, newUrl.errorString()));
        return;
    }

    QString fileName = newUrl.fileName();
    //if (fileName.isEmpty())
        fileName = defaultFileLineEdit->text().trimmed();
    if (fileName.isEmpty())
        fileName = defaultFileName;
    QString downloadDirectory = QDir::cleanPath(downloadDirectoryLineEdit->text().trimmed());
    bool useDirectory = !downloadDirectory.isEmpty() && QFileInfo(downloadDirectory).isDir();
    if (useDirectory)
        fileName.prepend(downloadDirectory + '/');

    file = openFileForWrite(fileName);
    if (!file)
        return;

    startSetPass(newUrl);




}

QFile *HttpWindow::openFileForWrite(const QString &fileName)
{
    QScopedPointer<QFile> file(new QFile(fileName));
    if (!file->open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Error"),
                                 tr("Unable to save the file %1: %2.")
                                 .arg(QDir::toNativeSeparators(fileName),
                                      file->errorString()));
        return nullptr;
    }
    return file.take();
}

void HttpWindow::cancelDownload()
{
    statusLabel->setText(tr("Download canceled."));
    httpRequestAborted = true;
    reply->abort();
    downloadButton->setEnabled(true);
}

void HttpWindow::httpFinished()
{
    QFileInfo fi;
    if (file) {
        fi.setFile(file->fileName());
        file->close();
        delete file;
        file = nullptr;
    }

    if (httpRequestAborted) {
        reply->deleteLater();
        reply = nullptr;
        return;
    }

    if (reply->error()) {
        QFile::remove(fi.absoluteFilePath());
        statusLabel->setText(tr("Download failed:\n%1.").arg(reply->errorString()));
        downloadButton->setEnabled(true);
        reply->deleteLater();
        reply = nullptr;
        return;
    }

    const QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);

    reply->deleteLater();
    reply = nullptr;

    if (!redirectionTarget.isNull()) {
        const QUrl redirectedUrl = url.resolved(redirectionTarget.toUrl());
        if (QMessageBox::question(this, tr("Redirect"),
                                  tr("Redirect to %1 ?").arg(redirectedUrl.toString()),
                                  QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) {
            QFile::remove(fi.absoluteFilePath());
            downloadButton->setEnabled(true);
            statusLabel->setText(tr("Download failed:\nRedirect rejected."));
            return;
        }
        file = openFileForWrite(fi.absoluteFilePath());
        if (!file) {
            downloadButton->setEnabled(true);
            return;
        }
        startRequest(redirectedUrl);
        return;
    }

    statusLabel->setText(tr("Downloaded %1 bytes to %2\nin\n%3")
                         .arg(fi.size()).arg(fi.fileName(), QDir::toNativeSeparators(fi.absolutePath())));
    if (launchCheckBox->isChecked())
        QDesktopServices::openUrl(QUrl::fromLocalFile(fi.absoluteFilePath()));
    downloadButton->setEnabled(true);
}

void HttpWindow::httpReadyRead()
{
    // this slot gets called every time the QNetworkReply has new data.
    // We read all of its new data and write it into the file.
    // That way we use less RAM than when reading it at the finished()
    // signal of the QNetworkReply
    if (file)
        file->write(reply->readAll());
}

void HttpWindow::enableDownloadButton()
{
    downloadButton->setEnabled(!urlLineEdit->text().isEmpty());
}

void HttpWindow::slotAuthenticationRequired(QNetworkReply *, QAuthenticator *authenticator)
{
    QDialog authenticationDialog;
    Ui::Dialog ui;
    ui.setupUi(&authenticationDialog);
    authenticationDialog.adjustSize();
    ui.siteDescription->setText(tr("%1 at %2").arg(authenticator->realm(), url.host()));
    qDebug () << "authenticator->realm()" << authenticator->realm();
    // Did the URL have information? Fill the UI
    // This is only relevant if the URL-supplied credentials were wrong
    ui.userEdit->setText(url.userName());
    ui.passwordEdit->setText(url.password());

    if (authenticationDialog.exec() == QDialog::Accepted) {
        authenticator->setUser(ui.userEdit->text());
        authenticator->setPassword(ui.passwordEdit->text());
    }
}


void HttpWindow::startSetPass(const QUrl &requestedUrl)
{
    qDebug () << "HttpWindow::startSetPass";
   // qDebug () << "requestedUrl = " << requestedUrl.toString();
    QByteArray postDataByteArray;// = variantMapToJson(data);
    QByteArray postData;
    QString userName;
   userName = "alkimand@mail.ru";
   //userName= "AlkimandFromHell@gmail.com";
    QString password;
   password = "qwertyop";

   qDebug () << "requestedUrl - " << requestedUrl.toString();
   qDebug () << "userName - " << userName;
   qDebug () << "password - " << password;


   //password = "qwertyop1";

//куки
//https://toster.ru/q/527324

   QNetworkCookie cookie;

QList<QNetworkCookie> cookies;

    postData+= "&vb_login_username=" +  QUrl::toPercentEncoding( userName.toUtf8() );
    postData+= "&cookieuser=1";
    postData+= "&vb_login_password="+  QUrl::toPercentEncoding( password.toUtf8() );
    postData+= "&s=&securitytoken=guest";
    postData+= "&do=login";
    postData+= "&vb_login_md5password=";
    postData+= "&vb_login_md5password_utf=";

//    postData+= "&identifier=" +  QUrl::toPercentEncoding( userName.toUtf8() );
//    postData+= "&cookieuser=1";
//    postData+= "&vb_login_password="+  QUrl::toPercentEncoding( password.toUtf8() );
//    postData+= "&s=&securitytoken=guest";
//    postData+= "&do=login";
//    postData+= "&vb_login_md5password=";
//    postData+= "&vb_login_md5password_utf=";
   


    url = requestedUrl;

    QNetworkRequest Newrequest(url);
    Newrequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    Newrequest.setRawHeader("Accept-Encoding","identity");

    //QUrl url2("http://www.cyberforum.ru/usercp.php");
    //reply = this->qnam->get(QNetworkRequest(url2));
    reply = this->qnam->post(Newrequest,postData);

    //reply = this->qnam->get(QNetworkRequest(url));






    connect(reply, &QNetworkReply::finished, this, &HttpWindow::httpFinished);
    connect(reply, &QIODevice::readyRead, this, &HttpWindow::httpReadyRead);

    ProgressDialog *progressDialog = new ProgressDialog(url, this);
    progressDialog->setAttribute(Qt::WA_DeleteOnClose);
    connect(progressDialog, &QProgressDialog::canceled, this, &HttpWindow::cancelDownload);
    connect(reply, &QNetworkReply::downloadProgress, progressDialog, &ProgressDialog::networkReplyProgress);
    connect(reply, &QNetworkReply::finished, progressDialog, &ProgressDialog::hide);
    progressDialog->show();

    statusLabel->setText(tr("Downloading %1...").arg(url.toString()));
    qDebug () << "HttpWindow::startSetPass - end";
}



#ifndef QT_NO_SSL
void HttpWindow::sslErrors(QNetworkReply *, const QList<QSslError> &errors)
{
    QString errorString;
    foreach (const QSslError &error, errors) {
        if (!errorString.isEmpty())
            errorString += '\n';
        errorString += error.errorString();
    }

    if (QMessageBox::warning(this, tr("SSL Errors"),
                             tr("One or more SSL errors has occurred:\n%1").arg(errorString),
                             QMessageBox::Ignore | QMessageBox::Abort) == QMessageBox::Ignore) {
        reply->ignoreSslErrors();
    }
}
#endif

