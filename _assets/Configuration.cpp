#ifndef Configuration_h
#define Configuration_h


void Configuration::save() {
/* create a file*/
    QFile file("c://Data//component.xml"); //TODO przesyłane jako parametr z GUI

    /* open a file*/
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(0, "Read only", "The file is in read only mode.");
    } else {
        QXmlStreamWriter* xmlWriter = new QXmlStreamWriter();
        xmlWriter->setDevice(&file);
        xmlWriter->writeStartDocument();

        xmlWriter->writeCharacters("\n");
        xmlWriter->writeStartElement("extension");
        xmlWriter->writeAttribute("type", "component");
        xmlWriter->writeAttribute("version", "2.5.0");
        xmlWriter->writeAttribute("method", "upgrade");

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("name");
        xmlWriter->writeCharacters("name_of_component");
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("creationDate");
        xmlWriter->writeCharacters("DD MM YYYY");
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("author");
        xmlWriter->writeCharacters("Robert Ostrowicki");
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("authorEmail");
        xmlWriter->writeCharacters("infor@fromsoft.pl");
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("authorUrl");
        xmlWriter->writeCharacters("fromsoft.pl");
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("copyright");
        xmlWriter->writeCharacters("FROMSOFT Systemy Komputerowe");
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("license");
        xmlWriter->writeCharacters("GNU GPL");
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("version");
        xmlWriter->writeCharacters("0.0.1");
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("description");
        xmlWriter->writeCharacters("Joomla Component XML generator");
        xmlWriter->writeEndElement();

        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeStartElement("update");
        xmlWriter->writeCharacters("\n\t\t");
        xmlWriter->writeStartElement("schemas");
        xmlWriter->writeCharacters("\n\t\t\t");
        xmlWriter->writeStartElement("schemapath");
        xmlWriter->writeAttribute("type", "mysql");
        xmlWriter->writeCharacters("sql//updates//mysql");
        xmlWriter->writeEndElement(); // END schemapath

        xmlWriter->writeCharacters("\n\t\t");
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
        xmlWriter->writeCharacters("name_of_component.php");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t");
        xmlWriter->writeEndElement(); // END files
        xmlWriter->writeCharacters("\n\t");

        xmlWriter->writeStartElement("administration");
        xmlWriter->writeCharacters("\n\t\t");
        xmlWriter->writeStartElement("menu");
        xmlWriter->writeCharacters("name_of_component");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t\t");
        xmlWriter->writeStartElement("files");
        xmlWriter->writeCharacters("\n\t\t\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters("index.html");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t\t\t");
        xmlWriter->writeStartElement("filename");
        xmlWriter->writeCharacters("name_of_component.php");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t\t\t");
        xmlWriter->writeStartElement("folder");
        xmlWriter->writeCharacters("sql");
        xmlWriter->writeEndElement();
        xmlWriter->writeCharacters("\n\t\t");
        xmlWriter->writeEndElement(); // END files
        xmlWriter->writeCharacters("\n\t");

        xmlWriter->writeEndElement(); // END administration


        xmlWriter->writeCharacters("\n");
        xmlWriter->writeEndElement(); // END Extension

        xmlWriter->writeEndDocument();

        delete xmlWriter;
    }
	
	
	}