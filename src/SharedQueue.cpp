//
// Created by jestemleon on 08.01.2021.
//

#include "SharedQueue.h"

#include <cerrno>
#include <cstring>
#include <iostream>

SharedQueue::SharedQueue(bool will_write, bool non_block, const char *queue_name) {
    mq = will_write ? ( non_block ? mq_open(queue_name, O_WRONLY | O_NONBLOCK) : mq_open(queue_name, O_WRONLY) )
            : ( non_block ? mq_open(queue_name, O_RDONLY | O_NONBLOCK) : mq_open(queue_name, O_RDONLY) );

    mq_attr m_attr;
    mq_getattr(mq, &m_attr);
    msg_size = m_attr.mq_msgsize;
}