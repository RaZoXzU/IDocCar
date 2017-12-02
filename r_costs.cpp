#include "r_costs.h"
#include "ui_r_costs.h"

#include <QDebug>

r_Costs::r_Costs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::r_Costs)
{
    ui->setupUi(this);

    connector = new SQL("localhost","idoccar","root","");
    connector->test();

//    series = new QAreaSeries();
    series0 = new QLineSeries();
    series1 = new QLineSeries();
    series2 = new QLineSeries();
    series3 = new QLineSeries();


    axisX = new QCategoryAxis();
    axisY = new QCategoryAxis();

    mainChart = new QChart();
    mainChart->addSeries(series0);


//------------------------------------------

    //loadSeries(series0,36);

    //series0->append(1,1);
    //series0->append(1.5,1.5);

//    int gh = 0;
//    while(gh<20)
//    {
//        series0->append(gh/2,(4+(gh*0.1)));
//        gh++;
//    }

    setXAxis();

    series0->setName("Renault Laguna II");
    series1->setName("CAT 352F 2017");

               /*<< QPointF(1, 5) << QPointF(2, 1) << QPointF(4, 3) << QPointF(6, 5) << QPointF(8, 5);*/
//       *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
//                << QPointF(16, 4) << QPointF(18, 3);


       QAreaSeries *series = new QAreaSeries(series0);
       series->setName("Batman");
       series->setBrush(Qt::NoBrush);
       QPen pen(0x059605);
       pen.setWidth(3);
       qDebug() << pen.isSolid();
       series->setPen(pen);

//       QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
//       gradient.setColorAt(0.0, 0x3cc63c);
//       gradient.setColorAt(1.0, 0x26f626);
//       gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
//       series->setBrush(gradient);

       mainChart->setTitle("Simple chart - średnie spalanie w ciągu miesiąca zestawienie roczne");
       mainChart->createDefaultAxes();
       mainChart->setAxisX(axisX,series0);
//       if(true)
//       {
//           mainChart->setAxisX(axisX,series1);
//       }
//       else
//       {
//           mainChart->setAxisX(axisX,series0);
//       }

       mainChart->axisX()->setRange(0, 12);
       mainChart->axisY()->setRange(0, 12);

       mainChart->legend()->setVisible(true);


       chartView = new QChartView(mainChart, ui->widget);
       chartView->setRenderHint(QPainter::Antialiasing);
//       ui->widget->resize((this->width()-5),(this->height()-5));
       chartView->resize((ui->widget->width()-10),(ui->widget->height()-10));


}

r_Costs::~r_Costs()
{
    delete ui;
}

void r_Costs::loadComboBox(int tanktype)
{
    ui->cb_carid->clear();
    QString stream;
    int i=0;

    if(tanktype==0)
    {
        ui->cb_carid->clear();
        connector->tankType(1);
        //connector->CarName();
        while (connector->getCarName(stream,i)) {
        ui->cb_carid->addItem(stream,i);
    }

//    connector->CarName();
//    while (connector->getCarName(stream,i)) {
//        ui->cb_carid->addItem(stream,i);
//      }
        ui->cb_carid->update();
    }
}

void r_Costs::loadSeries(QLineSeries *seriesN, int carId)
{
    QString date;
    int fuelId;
    float fuelCon;
    int i=0, temp_day;

//    while(i<400)
//    {
//        series0->append((1+(i/30)),(4+(0.01*i)));
//        ++i;
//    }
//    while (i<12) {

//        series0->append(i,i);
//    }

        SQL *test = new SQL("localhost","idoccar","root","");
        test->fuelInfo(carId);

    seriesN->append(0,0);
    while(test->fuelInfoQuest(fuelId,date,fuelCon))
    {
        QDate temp_date;
        temp_date = QDate::fromString(date,"yyyy-MM-dd");
        temp_day = temp_date.day();
        float temp_day_v = temp_day/30;
        int month = -1;
        month = temp_date.month();
        qDebug() << QString::number(month) + " td: " + QString::number(temp_day_v);

        float a = (1+temp_day_v);
        qDebug() <</* QString::number(a)*/ + " " + QString::number(fuelCon);
//        if(month==1)
//        {
//            seriesN->append(a,fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else if(month==2)
//        {
//            seriesN->append((2+temp_day_v),fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else if(month==3)
//        {
//            seriesN->append((3+temp_day_v),fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else if(month==4)
//        {
//            seriesN->append((4+temp_day_v),fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else if(month==5)
//        {
//            seriesN->append((5+temp_day_v),fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else if(month==6)
//        {
//            seriesN->append((6+temp_day_v),fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else if(month==7)
//        {
//            seriesN->append((7+temp_day_v),fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else if(month==8)
//        {
//            seriesN->append((8+temp_day_v),fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else if(month==9)
//        {
//            seriesN->append((9+temp_day_v),fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else if(month==10)
//        {
//            seriesN->append((10+temp_day_v),fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else if(month==11)
//        {
//            seriesN->append((11+temp_day_v),fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else if(month==12)
//        {
//            seriesN->append((12+temp_day_v),fuelCon);
//            setyMaxMin(fuelCon);
//        }
//        else
//            continue;

        switch(month)
        {
        case 1:
            seriesN->append((1+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 2:
            seriesN->append((2+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 3:
            seriesN->append((3+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 4:
            seriesN->append((4+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 5:
            seriesN->append((5+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 6:
            seriesN->append((6+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 7:
            seriesN->append((7+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 8:
            seriesN->append((8+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 9:
            seriesN->append((9+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 10:
            seriesN->append((10+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 11:
            seriesN->append((11+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 12:
            seriesN->append((12+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        default:
            break;
        }

    }

}

void r_Costs::setXAxis()
{
    axisX->append("Styczeń", 1);
    axisX->append("Luty", 2);
    axisX->append("Marzec", 3);
    axisX->append("Kwiecień",4);
    axisX->append("Maj",5);
    axisX->append("Czerwiec",6);
    axisX->append("Lipiec",7);
    axisX->append("Sierpień",8);
    axisX->append("Wrzesień",9);
    axisX->append("Październik",10);
    axisX->append("Listopad",11);
    axisX->append("Grudzień",12);
    axisX->setRange(0, 12);
}

void r_Costs::setYAxis()
{
    axisY->setRange(yMin,yMax);
}

void r_Costs::setyMaxMin(float v)
{
    if(v<yMin)
    {
        yMin=v;
    }
    else if(v>yMax)
    {
        yMax=v;
    }
}

void r_Costs::on_chb_on_clicked()
{
    loadComboBox(0);
    //ui->cb_carid->currentIndexChanged();
}


void r_Costs::on_cb_carid_currentIndexChanged(const QString &arg1)
{
    int i;
    i = ui->cb_carid->currentData().toInt();
    qDebug() << "reaguje: " + QString::number(i);

    loadSeries(series0,i);
    //loadComboBox(0);

    chartView->repaint();
    //ui->widget->repaint();
    ui->widget->update();
}
