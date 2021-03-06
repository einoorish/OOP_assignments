#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QInputDialog>
#include <QDateTime>
#include <QCloseEvent>

#include "note.h"

namespace Ui { class NoteWindow; }

class NoteWindow: public QDialog
{
    Q_OBJECT
public:
    NoteWindow(QWidget *parent = nullptr);
    ~NoteWindow();

private slots:

    void on_actionSave_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();


private:
    Ui::NoteWindow *ui;
};
#endif // NOTEWINDOW_H
