#ifndef EQUTION_H
#define EQUTION_H

#include <qstring.h>

class eqution
{

        QString equtions;
    public:
        eqution();
        eqution(QString in);
        virtual bool isValid()=0;
};

#endif // EQUTION_H
