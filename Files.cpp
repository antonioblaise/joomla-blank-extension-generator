/* 
 * File:   Files.cpp
 * Author: Robert
 * 
 * Created on 15 listopad 2012, 20:39
 */

#include "Files.h"

Files::Files() {    
    

}

Files::Files(const Files& orig) {
}

Files::~Files() {
}

/* Prepare variables containing files content */
void Files::prepareVars() {
        /* File content preparing */        
    emptyHtmlFileContent = "<html><body bgcolor=\"#FFFFFF\"></body></html>";

    controllerFileContent = "<?php\n";
    controllerFileContent.append("//// No direct access\n");
    controllerFileContent.append("defined( '_JEXEC' ) or die( 'Restricted access' );\n");
    controllerFileContent.append("jimport('joomla.application.component.controller');\n");
    controllerFileContent.append("class " + componentName + "Controller extends JController\n");
    controllerFileContent.append("{\n");
    controllerFileContent.append("function display()\n");
    controllerFileContent.append("{\n");
    controllerFileContent.append("parent::display();\n");
    controllerFileContent.append("}\n");    
    controllerFileContent.append("}\n");

    componentFileContent.append("<?php\n");
    componentFileContent.append("// No direct access\n");
    componentFileContent.append("defined( '_JEXEC' ) or die( 'Restricted access' );\n");
    componentFileContent.append("// Require the base controller\n");
    componentFileContent.append("require_once( JPATH_COMPONENT.DS.'controller.php' );\n");
    componentFileContent.append("// Require specific controller if requested\n");
    componentFileContent.append("if($controller = JRequest::getWord('controller')) {\n");
    componentFileContent.append("$path = JPATH_COMPONENT.DS.'controllers'.DS.$controller.'.php';\n");
    componentFileContent.append("if (file_exists($path)) {\n");
    componentFileContent.append("require_once $path;\n");
    componentFileContent.append("} else {\n");
    componentFileContent.append("$controller = '';\n");
    componentFileContent.append("}\n");
    componentFileContent.append("}\n");
    componentFileContent.append("// Create the controller\n");
    componentFileContent.append("$classname    = '" + componentName + "Controller'.$controller;\n");
    componentFileContent.append("$controller   = new $classname( );\n");
    componentFileContent.append("// Perform the Request task\n");
    componentFileContent.append("$controller->execute( JRequest::getWord( 'task' ) );\n");
    componentFileContent.append("// Redirect if set by the controller\n");
    componentFileContent.append("$controller->redirect();\n");

    viewFileContent.append("<?php\n");
    viewFileContent.append("// no direct access\n");
    viewFileContent.append("defined( '_JEXEC' ) or die( 'Restricted access' );\n");
    viewFileContent.append("jimport( 'joomla.application.component.view');\n");
    viewFileContent.append("class " + componentName + "View" + componentName + " extends JView\n");
    viewFileContent.append("{\n");
    viewFileContent.append("function display($tpl = null)\n");
    viewFileContent.append("{\n");
    viewFileContent.append("$greeting = 'Hello World!';\n");
    viewFileContent.append("$this->assignRef( 'greeting', $greeting );\n");
    viewFileContent.append("parent::display($tpl);\n");
    viewFileContent.append("}\n");
    viewFileContent.append("}\n");

    defaultTmplFileContent.append("<?php\n");
    defaultTmplFileContent.append("// No direct access\n");
    defaultTmplFileContent.append("defined('_JEXEC') or die('Restricted access'); ?>\n");
    defaultTmplFileContent.append("<h1><?php echo $this->greeting; ?></h1>\n");
    
}

void Files::createDirs() {

    /* Create component directories */
    
//    QString path = "C://Data//com_" + componentName;
    QString path = basePath + QDir::separator() + "com_" +  componentName;

    /* Create main directories */
    QDir* dir = new QDir(path);
    if (!dir->exists()) {
        dir->mkdir(path);
    }

    dir = new QDir(path + "//site");
    if (!dir->exists()) {
        dir->mkdir(path + "//site");
    }

    dir = new QDir(path + "//admin");
    if (!dir->exists()) {
        dir->mkdir(path + "//admin");
    }

    /* Create admin subdirectories */
    dir = new QDir(path + "//admin//sql");
    if (!dir->exists()) {
        dir->mkdir(path + "//admin/sql");
    }
    
    /* Create site subdirectories */
    dir = new QDir(path + "//site//views");
    if (!dir->exists()) {
        dir->mkdir(path + "//site//views");
    }

    dir = new QDir(path + "//site/views//" + componentName);
    if (!dir->exists()) {
        dir->mkdir(path + "//site/views//" + componentName);
    }

    dir = new QDir(path + "//site//views//" + componentName + "//tmpl");
    if (!dir->exists()) {
        dir->mkdir(path + "//site//views//" + componentName + "//tmpl");
    }

}

void Files::createFiles() {

    QString path = basePath + QDir::separator() + "com_" +  componentName;    
    
    QFile file;
    QTextStream out;

    /* Create site files*/
    file.setFileName(path + "//index.html");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << emptyHtmlFileContent;
    file.close();

    file.setFileName(path + "//site//index.html");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << emptyHtmlFileContent;
    file.close();    

    file.setFileName(path + "//site//controller.php");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << controllerFileContent;
    file.close();

    file.setFileName(path + "//site//" + componentName + ".php");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << componentFileContent;
    file.close();

    file.setFileName(path + "//site//views//index.html");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << emptyHtmlFileContent;
    file.close();

    file.setFileName(path + "//site/views//" + componentName + "//index.html");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << emptyHtmlFileContent;
    file.close();

    file.setFileName(path + "//site/views//" + componentName + "//view.html.php");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << viewFileContent;
    file.close();

    file.setFileName(path + "//site//views//" + componentName + "//tmpl" + "//index.html");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << emptyHtmlFileContent;
    file.close();

    file.setFileName(path + "//site//views//" + componentName + "//tmpl" + "//default.php");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << defaultTmplFileContent;
    file.close();

    /* Create admin files*/
    file.setFileName(path + "//admin/index.html");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << emptyHtmlFileContent;
    file.close();
    
    file.setFileName(path + "//admin/sql/index.html");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    out.setDevice(&file);
    out << emptyHtmlFileContent;
    file.close();

}
