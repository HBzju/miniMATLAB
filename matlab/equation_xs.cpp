#include "equation_xs.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>

equation_xs::equation_xs(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(640,480);
    input=new QTextEdit;
    output=new QTextEdit;
    input->setPlaceholderText("求解方程");
    output->setPlaceholderText("");
    button=new QPushButton(tr("解方程"));

    QHBoxLayout *hlayout=new QHBoxLayout;
    hlayout->addWidget(input);
    hlayout->addWidget(button);

    QVBoxLayout *vlayout=new QVBoxLayout;
    vlayout->addLayout(hlayout);
    vlayout->addWidget(output);

    setLayout(vlayout);

    connect(button,SIGNAL(clicked(bool)),this,SLOT(equation_slots()));
    connect(this,SIGNAL(setAnswer(const QString&)),output,SLOT(setText(const QString&)));
}

equation_xs::~equation_xs()
{
}
