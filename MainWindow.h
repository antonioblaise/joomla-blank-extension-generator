/* 
 * File:   MainWindow.h
 * Author: Robert
 *
 * Created on 11 listopad 2012, 18:22
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QDateEdit>
#include <QLineEdit>
#include <QTextEdit>
#include <QCloseEvent>

class MainWindow : public QMainWindow {
public:
    MainWindow();
    MainWindow(const MainWindow& orig);
    virtual ~MainWindow();
private:
protected:
//    void closeEvent(QCloseEvent *event);
};

#endif	/* MAINWINDOW_H */

