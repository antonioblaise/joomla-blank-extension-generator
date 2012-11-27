/* 
 * File:   Dialog.cpp
 * Author: Robert
 * 
 * Created on 11 listopad 2012, 18:41
 */

#include "Dialog.h"
#include "Configuration.h"
#include "Files.h"

#include "iostream"
using namespace std;

Dialog::Dialog() {



    //configuration filepath
    configDir = QCoreApplication::applicationDirPath();
    configFileName = "qtjxmlgen.config";


    /* Try to load config from file */
    QStringList config = loadConfig();


    // Layout
    QGridLayout* mainLayout = new QGridLayout();

    // Widgets
    labelName = new QLabel("Name");
    labelCreationDate = new QLabel("Creation Date");
    labelAuthor = new QLabel("Author");
    labelAuthorEmail = new QLabel("Author Email");
    labelAuthorUrl = new QLabel("Author Url");
    labelCopyright = new QLabel("Copyright");
    labelLicense = new QLabel("License");
    labelVersion = new QLabel("Version");
    labelDescription = new QLabel("Description");

    dateEditCreationDate = new QDateEdit();

    lineEditName = new QLineEdit();
    lineEditAuthor = new QLineEdit();
    lineEditAuthorEmail = new QLineEdit();
    lineEditAuthorUrl = new QLineEdit();
    lineEditCopyright = new QLineEdit();
    lineEditLicense = new QLineEdit();
    lineEditVersion = new QLineEdit();

    textEditDescription = new QTextEdit();


    // Default values
    QString editName;
    QString editAuthor;
    QString editAuthorEmail;
    QString editAuthorUrl;
    QString editCopyright;
    QString editLicense;
    QString editVersion;
    QString editDescription;
    if (!config.isEmpty()) {
        editName = config.at(0);
        editAuthor = config.at(1);
        editAuthorEmail = config.at(2);
        editAuthorUrl = config.at(3);
        editCopyright = config.at(4);
        editLicense = config.at(5);
        editVersion = config.at(6);
        editDescription = config.at(7);
    } else if (config.isEmpty()) {
        editName = "Joomla Extension Generator";
        editAuthor = "Robert Ostrowicki";
        editAuthorEmail = "info@fromsoft.pl";
        editAuthorUrl = "http://fromsoft.pl";
        editCopyright = "Copyright(c)2012 FROMSOFT Systemy Komputerowe";
        editLicense = "GNU GPL";
        editVersion = "0.0.1";
        editDescription = "Generate blank joomla extension installer.";
    }

    lineEditName->setText(editName);
    dateEditCreationDate->setDate(QDate::currentDate());
    lineEditAuthor->setText(editAuthor);
    lineEditAuthorEmail->setText(editAuthorEmail);
    lineEditAuthorUrl->setText(editAuthorUrl);
    lineEditCopyright->setText(editCopyright);
    lineEditLicense->setText(editLicense);
    lineEditVersion->setText(editVersion);
    textEditDescription->setText(editDescription);

    // fill layout
    mainLayout->addWidget(labelName, 0, 0);
    mainLayout->addWidget(lineEditName, 0, 1);
    mainLayout->addWidget(labelCreationDate, 1, 0);
    mainLayout->addWidget(dateEditCreationDate, 1, 1);
    mainLayout->addWidget(labelAuthor, 2, 0);
    mainLayout->addWidget(lineEditAuthor, 2, 1);
    mainLayout->addWidget(labelAuthorEmail, 3, 0);
    mainLayout->addWidget(lineEditAuthorEmail, 3, 1);
    mainLayout->addWidget(labelAuthorUrl, 4, 0);
    mainLayout->addWidget(lineEditAuthorUrl, 4, 1);
    mainLayout->addWidget(labelCopyright, 5, 0);
    mainLayout->addWidget(lineEditCopyright, 5, 1);
    mainLayout->addWidget(labelLicense, 6, 0);
    mainLayout->addWidget(lineEditLicense, 6, 1);
    mainLayout->addWidget(labelVersion, 7, 0);
    mainLayout->addWidget(lineEditVersion, 7, 1);
    mainLayout->addWidget(labelDescription, 8, 0);
    mainLayout->addWidget(textEditDescription, 8, 1);



    // add about button
    QPushButton* buttonAbout = new QPushButton("About");
    QObject::connect(buttonAbout, SIGNAL(clicked()), this, SLOT(aboutDialog()));
    mainLayout->addWidget(buttonAbout, 9, 0);

    // add save button
    QPushButton* buttonSave = new QPushButton("Save...");
    QObject::connect(buttonSave, SIGNAL(clicked()), this, SLOT(saveFile()));
    mainLayout->addWidget(buttonSave, 9, 1);



    setLayout(mainLayout);
}

Dialog::Dialog(const Dialog& orig) {
}

Dialog::~Dialog() {
}

void Dialog::aboutDialog() {

    QString aboutText;
    aboutText = "Application generates blank Joomla extension.\n";
    aboutText.append("\nYou can zip it and install successfully on your Joomla installation for further development. ");
    aboutText.append("It may save your time by eliminating preparing and testing effort for creating your extensions 'canvas'.\n");
    aboutText.append("\nThis is open source software under LGPL license.\n");
    aboutText.append("\nMore information you can find on my website: fromsoft.pl - Joomla and Virtuemart Development");


    QMessageBox box;
    box.setText(aboutText);
    box.setStandardButtons(QMessageBox::Ok);
    box.setIcon(QMessageBox::Information);
    box.setDefaultButton(QMessageBox::Ok);
    box.exec();
}

void Dialog::saveFile() {

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    // create directories and files
    Files files;
    files.componentName = lineEditName->text().replace(" ", "").toLower(); // no spaces, all to lower
    files.basePath = dir;
    files.prepareVars();
    files.createDirs();
    files.createFiles();

    // write installation xml
    Configuration config;
    config.basePath = dir;
    config.componentName = files.componentName; // building filepaths purpose
    config.name = lineEditName->text();
    config.author = lineEditAuthor->text();
    config.authorEmail = lineEditAuthorEmail->text();
    config.authorUrl = lineEditAuthorUrl->text();
    config.copyright = lineEditCopyright->text();
    config.license = lineEditLicense->text();
    config.version = lineEditVersion->text();
    config.description = textEditDescription->toPlainText();
    config.save();

    // TODO zip install package [optional] - is it trully needed for developers?


    // Write dialog fields content to config file
    saveConfig();

    // Confirm that everything goes well
    if (!dir.isEmpty()) { // if user press cancel in file dialog do not process
        QMessageBox box;
        box.setText("Successfully saved to: \n" + dir);
        box.setStandardButtons(QMessageBox::Ok);
        box.setIcon(QMessageBox::Information);
        box.setDefaultButton(QMessageBox::Ok);
        box.exec();
    }

}

QStringList Dialog::loadConfig() {
    /* CSV separator*/
    QChar sep = ';';

    QString filePath = configDir + QDir::separator() + configFileName;
    QFile file(filePath);

    QStringList vals; // CSV values as list

    if (file.open(QIODevice::ReadOnly)) {
        //file opened successfully
        QString data;
        data = file.readAll();
        //        cout << "loaded: " + data.toStdString() + " END";
        vals = data.split(sep);
        file.close();
    }
    return vals;
}

void Dialog::saveConfig() {
    /* CSV separator*/
    QChar sep = ';';

    QString filePath = configDir + QDir::separator() + configFileName;
    QTextStream out;
    QFile file;

    /* configuration CSV */
    QString csv;
    csv.append(lineEditName->text() + sep);
    csv.append(lineEditAuthor->text() + sep);
    csv.append(lineEditAuthorEmail->text() + sep);
    csv.append(lineEditAuthorUrl->text() + sep);
    csv.append(lineEditCopyright->text() + sep);
    csv.append(lineEditLicense->text() + sep);
    csv.append(lineEditVersion->text() + sep);
    csv.append(textEditDescription->toPlainText() + sep);

    file.setFileName(filePath);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << csv;
    file.close();
}