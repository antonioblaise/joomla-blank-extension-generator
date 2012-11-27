/* 
 * File:   Dialog.h
 * Author: Robert
 *
 * Created on 11 listopad 2012, 18:41
 */

#ifndef DIALOG_H
#define	DIALOG_H

#include <QWidget>
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QDateEdit>
#include <QLineEdit>
#include <QTextEdit>
#include <QDateEdit>
#include <QFileDialog>

class Dialog : public QWidget {
    Q_OBJECT

public:
    Dialog();
    Dialog(const Dialog& orig);
    virtual ~Dialog();


    QLabel* labelName;
    QLabel* labelCreationDate;
    QLabel* labelAuthor;
    QLabel* labelAuthorEmail;
    QLabel* labelAuthorUrl;
    QLabel* labelCopyright;
    QLabel* labelLicense;
    QLabel* labelVersion;
    QLabel* labelDescription;

    QDateEdit* dateEditCreationDate;

    QLineEdit* lineEditName;
    QLineEdit* lineEditAuthor;
    QLineEdit* lineEditAuthorEmail;
    QLineEdit* lineEditAuthorUrl;
    QLineEdit* lineEditCopyright;
    QLineEdit* lineEditLicense;
    QLineEdit* lineEditVersion;

    QTextEdit* textEditDescription;

private:
    QString configDir;
    QString configFileName;

private slots:
    void saveFile(); // save button action
    QStringList loadConfig(); // try load form fields on open
    void saveConfig(); // save form fields to disk on exit
    void aboutDialog();

};

#endif	/* DIALOG_H */

