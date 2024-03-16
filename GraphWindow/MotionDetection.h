#ifndef MOTIONDETECTION_H
#define MOTIONDETECTION_H

#include "qcustomplot.h"
#include "qapplication.h"
#include "opencv2/opencv.hpp"

class MotionDetect: public QMainWindow
{
    Q_OBJECT
public:
    explicit MotionDetect(QWidget *parent = nullptr);

    /**
     * @brief set different to points to draw the image
     * @param x
     * @param y
     */
    void setPoint(double x, int y);

    /**
     * @brief clear different points
     */
    void clearData();

    /**
     * @brief show points on image
     */
    void showPlot();

private slots:

    /**
     * @brief clear points on show image
     */
    void on_ptn_clear_clicked();

    /**
     * @brief handle click events
     * @param event
     */
    void clicked_Graph(QMouseEvent *event);

    /**
     * @brief stop display curves
     */
    void on_btn_stop_clicked();

    /**
     * @brief start display curves
     */
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