/* 
 * File:   Files.h
 * Author: Robert
 *
 * Created on 15 listopad 2012, 20:39
 */

#ifndef FILES_H
#define	FILES_H

#include <QDir>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QCoreApplication>

class Files {
public:
    Files();
    Files(const Files& orig);
    virtual ~Files();
    
    void prepareVars();
    
    QString basePath;
            
    QString componentName;
    QString emptyHtmlFileContent;
    QString controllerFileContent;
    QString componentFileContent;
    QString viewFileContent;
    QString defaultTmplFileContent;
    
private:
    
    
    public slots:
        void createDirs();
        void createFiles();
};

#endif	/* FILES_H */

