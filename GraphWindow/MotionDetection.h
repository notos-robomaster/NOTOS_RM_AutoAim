#ifndef MOTIONDETECTION_H
#define MOTIONDETECTION_H

#include "qcustomplot.h"
#include "qapplication.h"
#include "opencv2/opencv.hpp"

class MotionDetect: public QMainWindow
{
    Q_OBJECT
public:
    explicit MotionDetect();

    void setPoint(double x, int y);

    void clearData();

    void showPlot();

private slots:

    void on_ptn_clear_clicked();

    void clicked_Graph(QMouseEvent *event);

    void on_btn_stop_clicked();

    void on_btn_start_clicked();

private:
    QCustomPlot plot;
    QCPGraph *graph;

    QVector<double> qv_x, qv_y, qv_t1, qv_t2;

    double programe_start_time;
    int history_num_ = 5000;
    int range_num_ = 5;
    bool mouse_flag_ = 0;
    bool stop_plot_flag_ = 0;
};

#endif //MOTIONDETECTION_H