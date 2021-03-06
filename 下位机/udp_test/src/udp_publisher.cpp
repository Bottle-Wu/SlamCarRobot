/******************************************************************************
*
* The MIT License (MIT)
*
* Copyright (c) 2018 Bluewhale Robot
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Author: Randoms
*******************************************************************************/

#include "udp_node.h"
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "udp_pub_node");
    ros::AsyncSpinner spinner(4);
    spinner.start();
    ros::NodeHandle private_nh("~");
    ros::Publisher test_pub = private_nh.advertise<std_msgs::String>("/chatter", 10);
    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "arm -> nvidia";
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());
        test_pub.publish(msg);
        sleep(1);
    }

}
