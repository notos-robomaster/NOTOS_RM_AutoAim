#include "MotionDetection.h"

MotionDetect::MotionDetect()
{
    plot.addGraph();
    plot.graph(0)->setScatterStyle(QCPScatterStyle::ssCross);
    plot.graph(0)->setPen(QPen(Qt::red));
    plot.graph(0)->setLineStyle(QCPGraph::lsLine);


    plot.addGraph();
    plot.graph(1)->setScatterStyle(QCPScatterStyle::ssCross);
    plot.graph(1)->setPen(QPen(Qt::blue));
    plot.graph(1)->setLineStyle(QCPGraph::lsLine);
    plot.setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    connect(&plot, SIGNAL(mousePress(QMouseEvent *)), this, SLOT(clicked_Graph(QMouseEvent *)));

    plot.show();
    plot.replot();

    programe_start_time = cv::getTickCount();
}

void MotionDetect::setPoint(double x, int y)
{
    double t_tmp = cv::getTickCount();
    double t = (t_tmp - programe_start_time)/cv::getTickFrequency();

    switch (y)
    {
        case 0:
            qv_x.push_back(x);
            qv_t1.push_back(t);
            break;
        case 1:
            qv_y.push_back(x);
            qv_t2.push_back(t);
            break;
    }

    if (qv_x.size()>history_num_)
    {
        qv_x.pop_front();
        qv_t1.pop_front();
    }

    if (qv_y.size()>history_num_)
    {
        qv_y.pop_front();
        qv_t2.pop_front();
    }

    if (mouse_flag_ == 0)
    {
        plot.xAxis->rescale();
        plot.yAxis->rescale();
        plot.xAxis->setRange(plot.xAxis->range().upper, range_num_, Qt::AlignRight);
    }

    showPlot();
}

void MotionDetect::clearData()
{
    qv_x.clear();
    qv_y.clear();
    qv_t1.clear();
    qv_t2.clear();
}

void MotionDetect::showPlot()
{
    if (!stop_plot_flag_)
    {
        plot.graph(0)->setData(qv_t1, qv_x);
        plot.graph(1)->setData(qv_t2, qv_y);
        plot.replot();
    }
}

void MotionDetect::on_ptn_clear_clicked()
{
    clearData();
    showPlot();
}

void MotionDetect::clicked_Graph(QMouseEvent *event)
{
    QPoint point = event->pos();
    double m_x = plot.xAxis->pixelToCoord(point.x());
    double m_y = plot.xAxis->pixelToCoord(point.y());
    qDebug() << m_x << m_y;

    int button_flag = event->button();
    QVector<double> qv_tmp;
    if (button_flag == 1)
    {
        mouse_flag_ = 1;
    } else
    {
        mouse_flag_ = 0;
    }
}

void MotionDetect::on_btn_stop_clicked()
{
    stop_plot_flag_ = 1;
}

void MotionDetect::on_btn_start_clicked()
{
    stop_plot_flag_ = 0;
}
