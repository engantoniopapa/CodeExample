#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QString>
#include "MVC-Example1-lib_global.h"

namespace MVC_Example1 {
namespace controllers {

    class MVCEXAMPLE1LIB_EXPORT MasterController : public QObject
    {
        Q_OBJECT
        Q_PROPERTY( QString ciao_MessageEx1 MEMBER MessageEx1 CONSTANT )
        public:
        explicit MasterController(QObject* parent = nullptr);
        QString MessageEx1 = "Ciao ciao";
    };
}}
#endif // MASTERCONTROLLER_H



