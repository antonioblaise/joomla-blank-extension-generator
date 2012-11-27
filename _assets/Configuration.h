#ifndef Configuration_h
#define Configuration_h

#include <QDate>
#include <QString>
#include <QFile>

class Configuration {
        Configuration();        

public:
        static const QString name;
		static const QDate creationDate;
        static const QString author;
		static const QString authorEmail;
        static const QString authorUrl;
		static const QString copyright;
		static const QString license;
		static const QString version;
		static const QString description;
          
	void save(); //save install XML
	
	}