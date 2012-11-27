/*
 * File:   main.cpp
 * Author: Robert
 *
 * Created on 11 listopad 2012, 18:08
 */

#include <QtGui/QApplication>

#include "MainWindow.h";

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    
    MainWindow window;
    window.show();

    // create and show your widgets here

    return app.exec();
}
