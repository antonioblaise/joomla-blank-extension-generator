/* 
 * File:   Configuration.h
 * Author: Robert
 *
 * Created on 12 listopad 2012, 21:50
 */

#ifndef CONFIGURATION_H
#define	CONFIGURATION_H

#include <QDate>
#include <QString>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QXmlStreamWriter>

class Configuration : public QObject {
    
    Q_OBJECT
    
public:
    QString name;
    QDate creationDate;
    QString author;
    QString authorEmail;
    QString authorUrl;
    QString copyright;
    QString license;
    QString version;
    QString description;
    
    QString basePath;
    QString componentName;


public slots:
        void save(); //save install XML

public:
    Configuration();
    Configuration(const Configuration& orig);
    virtual ~Configuration();
private:

};

#endif	/* CONFIGURATION_H */

