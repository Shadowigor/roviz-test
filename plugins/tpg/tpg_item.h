﻿#ifndef TPG_H
#define TPG_H

#include "core/export_handling.h"

// This is a simulation only item
#if ROVIZ_BACKEND == ROVIZ_BACKEND_Dev

#include <QImage>
#include <QTimer>
#include <atomic>
#include "core/roviz_item.h"
#include "streams/image_m.h"

/**
 * @brief Test pattern generator for testing
 *
 * \ingroup robot_plugins
 */
class TPGItem : public RovizItem
{
    Q_OBJECT

public:
    ROVIZ_INVOKABLE TPGItem();
    ~TPGItem();

private:
    void starting(void) override;
    void thread(void) override;

    QImage test_pattern;
    QTimer timer;
    int timeout;
    Output<Image> output;
    Trim trim_fps;
    bool timer_expired;

private slots:
    void timerExpired(void);

};

#endif
#endif // TPG_H
