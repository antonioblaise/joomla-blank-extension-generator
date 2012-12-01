/* 
 * File:   MainWindow.cpp
 * Author: Robert
 * 
 * Created on 11 listopad 2012, 18:22
 */

#include "MainWindow.h"
#include "Dialog.h"

MainWindow::MainWindow() {
    
    QTabWidget* tabWidget = new QTabWidget();
    tabWidget->addTab(new Dialog(), tr("Component"));

    setWindowTitle("Joomla! Blank Extension (0.0.2)");    
//    setCentralWidget(new Dialog());
    setCentralWidget(tabWidget);

}

MainWindow::MainWindow(const MainWindow& orig) {
}

MainWindow::~MainWindow() {
}

//void MainWindow::closeEvent(QCloseEvent *event) {
//    event->ignore(); // always prevent the window from being closed
//} 