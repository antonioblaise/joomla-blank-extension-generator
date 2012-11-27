/********************************************************************************
** Form generated from reading UI file 'parametersdialog.ui'
**
** Created: Sun 11. Nov 18:10:05 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERSDIALOG_H
#define UI_PARAMETERSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_parametersdialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *parametersdialog)
    {
        if (parametersdialog->objectName().isEmpty())
            parametersdialog->setObjectName(QString::fromUtf8("parametersdialog"));
        parametersdialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(parametersdialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        retranslateUi(parametersdialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), parametersdialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), parametersdialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(parametersdialog);
    } // setupUi

    void retranslateUi(QDialog *parametersdialog)
    {
        parametersdialog->setWindowTitle(QApplication::translate("parametersdialog", "parametersdialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class parametersdialog: public Ui_parametersdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERSDIALOG_H
