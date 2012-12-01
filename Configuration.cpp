/* 
 * File:   Configuration.cpp
 * Author: Robert
 * 
 * Created on 12 listopad 2012, 21:50
 */

#include "Configuration.h"

Configuration::Configuration() {
}

Configuration::Configuration(const Configuration& orig) {
}

Configuration::~Configuration() {
}

void Configuration::save() {
    /* create a file*/
    QString filePath = basePath + QDir::separator() + "com_" + componentName + QDir::separator() + componentName + ".xml";
    QFile file(filePath); //TODO przesyłane jako parametr z GUI

    /* open a file*/
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(0, "Read only", "The file is in read only mode.");
    } else {
        QXmlStreamWriter* xmlWriter = new QXmlStreamWriter();
        xmlWriter->setDevice(&file);
        xmlWriter->writeStartDocument();

        /* write tags */
        xmlWriter->writeCharacters("\n");
        xmlWriter->writeStartElement("extension");
        xmlWriter->writeAttribute("type", "component");
        xmlWriter->writeAttribute("version", "2.5.0");
        xmlWriter->writeAttribute("method", "upgrade");

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("name");
        xmlWriter->writeCharacters(name);
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("creationDate");
        xmlWriter->writeCharacters(creationDate.toString());
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("author");
        xmlWriter->writeCharacters(author); //author tag
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("authorEmail");
        xmlWriter->writeCharacters(authorEmail);
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("authorUrl");
        xmlWriter->writeCharacters(authorUrl);
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("copyright");
        xmlWriter->writeCharacters(copyright);
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("license");
        xmlWriter->writeCharacters(license);
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("version");
        xmlWriter->writeCharacters(version);
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("description");
        xmlWriter->writeCharacters(description);
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("update");
        xmlWriter->writeCharacters("\n\t\t");
        xmlWriter->writeStartElement("schemas");
        xmlWriter->writeCharacters("\n\t\t");
//        xmlWriter->writeStartElement("schemapath");
//        xmlWriter->writeAttribute("type", "mysql");
//        xmlWriter->writeCharacters("sql/updates/mysql");
//        xmlWriter->writeEndElement(); // END schemapath

//        xmlWriter->writeCharacters("\n\t\t");
        xmlWriter->writeEndElement(); // END schemas

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeEndElement(); // END update

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("files");
        xmlWriter->writeAttribute("folder", "site");
        xmlWriter->writeCharacters("\n\t\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters("index.html");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters(componentName + ".php");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters("controller.php");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters("views//index.html");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters("views/" + componentName +"/index.html");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters("views/" + componentName +"/view.html.php");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters("views/" + componentName +"/tmpl/index.html");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters("views/" + componentName +"/tmpl/default.php");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeEndElement(); // END files
        xmlWriter->writeCharacters("\n\t");

        xmlWriter->writeStartElement("administration");
        xmlWriter->writeCharacters("\n\t\t");
        xmlWriter->writeStartElement("menu");
        xmlWriter->writeCharacters(componentName);
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t\t");
        xmlWriter->writeStartElement("files");
        xmlWriter->writeAttribute("folder", "admin");
        xmlWriter->writeCharacters("\n\t\t\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters("index.html");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t\t\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters(componentName + ".php");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t\t");
//        xmlWriter->writeStartElement("folder");
//        xmlWriter->writeCharacters("sql");
//        xmlWriter->writeEndElement();
//        xmlWriter->writeCharacters("\n\t\t");
        xmlWriter->writeEndElement(); // END files
        xmlWriter->writeCharacters("\n\t");

        xmlWriter->writeEndElement(); // END administration


        xmlWriter->writeCharacters("\n");
        xmlWriter->writeEndElement(); // END Extension

        xmlWriter->writeEndDocument();

        delete xmlWriter;
    }


}