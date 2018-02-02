#include <QCoreApplication>
#include "ObjectUsingFSM.h"

int main(int argc, char *argv[])
{
    ObjectUsingFSM fsm;
    fsm.SetState(EState::STT_EAT);

    QCoreApplication a(argc, argv);

    return a.exec();
}
