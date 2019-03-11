// ======================================================================
//  UdpServer.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.3 Professional programming with C++"
// ======================================================================
//  Copyright (c) 2014 by Max Schlee
//
//  Email : Max.Schlee@neonway.com
//  Blog  : http://www.maxschlee.com
//
//  Social Networks
//  ---------------
//  FaceBook : http://www.facebook.com/mschlee
//  Twitter  : http://twitter.com/Max_Schlee
//  2Look.me : http://2look.me/NW100003
//  Xing     : http://www.xing.com/profile/Max_Schlee
//  vk.com   : https://vk.com/max.schlee
// ======================================================================

#include <QtNetwork>
#include <QtGui>
#include "UdpServer.h"

// ----------------------------------------------------------------------
UdpServer::UdpServer(QWidget* pwgt /*=0*/) : QTextEdit(pwgt)
{
    setWindowTitle("UdpServer");

    m_pudp = new QUdpSocket(this);

    QTimer* ptimer = new QTimer(this);
    ptimer->setInterval(500);
    ptimer->start();
    connect(ptimer, SIGNAL(timeout()), SLOT(slotSendDatagram()));
}

// ----------------------------------------------------------------------
void UdpServer::slotSendDatagram()
{
    QByteArray baDatagram;
    i++;
    QDataStream out(&baDatagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    //QDateTime dt = QDateTime::currentDateTime();
    QString  str = "02/24/2019 21:57:04.131/103/31/af_app_manager/AppManagerWorker_2/SetAppIconPath/2936/=Menu Bar Icon of App VTA is not Present in App Folder.So Setting Default Location /pas/scfg/appfwCfg/default.png";
    QString  str2 = "02/24/2019 21:57:02.284/4943/29/sa_vp4_sal_service/sa_vp4_sal_service/SAL_NTFY_CANVS_CAN_BUS_STATUS_EVENTHandler/8895/=PublishcanDownReasonEvent - KONA sent";
    QString  str3 = "02/24/2019 21:57:02.283/1737/27/NS_NPPService/NS_NPPService/PasReaction/359/=Publish Notfn request, src=vs_can, name=vs_can/VS_CAN_BUS_STATUS_EVENT, len=4";
    QString  str4 = "02/24/2019 21:57:15.636/1226/30/Positioning.exe/0440_NAV_GPS_MAIN/DEV_Gps_DetectComPort/1445/=#Sierra DEV_Gps_DetectComPort1# NG cnt=275";
    QString  str5 = "02/24/2019 21:57:15.681/256/29/CORAL_CELL//WaitForModemReady/5517/=TIMEOUT COUNTER = 209";
    QString  str6 = "02/24/2019 21:57:20.221/957/29/GtfStatic/GtfStatic/DP_SAL_To_HMICallBack/2553/=dpID:60028 Bool:0";
    QString  str7 = "02/24/2019 21:57:10.480/1021/30/Positioning.exe/0440_NAV_GPS_MAIN/DEV_Gps_DetectComPort/1445/=#Sierra DEV_Gps_DetectComPort1# NG cnt=224";
    QString  str8 = "//////=";
    QString  str9 = "02/24/2019 21:57:08.258/932/30/Positioning.exe/0440_NAV_GPS_MAIN/DEV_Gps_ErrorOut/146/= COMMENT = CreateFile error";
    QString  str10 ="02/24/2019 21:57:08.196/172/29/CORAL_CELL//WaitForModemReady/5517/=TIMEOUT COUNTER = 135";
    QString  str11 = "02/24/2019 21:57:22.502/1042/29/GtfStatic/GtfStatic/processDpList/2000/=dpID:16711813 Idx:0 Img=/fs/mmc1/xletDir/xlets/Assist//tray_icon_assist.png";
    //out << dt;
    out << str << str2 << str3 << str4 << str5 << str6 << str7 << str8 << str9 << str10 << str11;

   // append("Sent:" + dt.toString());
    clear();
    append(str);
    append(str2);
    append(str3);
    append(str4);
    append(str5);
    append(str6);
    append(str7);
    append(str8);
    append(str9);
    append(str10);
    append(str11);
   // out << dt;
    m_pudp->writeDatagram(baDatagram, QHostAddress::LocalHost, 3500);
}

