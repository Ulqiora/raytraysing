#include "ViewApplication.h"
#include "ui_ViewApplication.h"

ViewApplication::ViewApplication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewApplication)
{
    ui->setupUi(this);
}

ViewApplication::~ViewApplication()
{
    delete ui;
}

