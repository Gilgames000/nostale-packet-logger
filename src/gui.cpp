#include <windows.h>
#include "main_form.h"
#include "packet_logger.h"
#include "safequeue.h"

using namespace nostalepacketlogger;

int GuiMain()
{
    SafeQueue qSend, qRecv;

    StartLogger(&qSend, &qRecv);
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew main_form(&qSend, &qRecv, SendPacket, ReceivePacket));
    StopLogger();

    return 0;
}