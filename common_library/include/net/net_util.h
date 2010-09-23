/**
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: jian yi, eyjian@qq.com
 */
#ifndef NET_UTIL_H
#define NET_UTIL_H
#include <poll.h>
#include <vector>
#include "net/net_config.h"
#include "sys/syscall_exception.h"
NET_NAMESPACE_BEGIN

/***
  * 与网络相关的工具类
  */
class CNetUtil
{
public:
    typedef std::string TIP;  /** IP地址 */
    typedef std::string TEth; /** 网卡名 */
    typedef std::vector<TIP> TIPArray; /** IP地址数组 */
    typedef std::vector<std::pair<TEth, TIP> > TEthIPArray; /** 网卡名和IP对数组 */

    /** 判断给定的字符串是否为一个IPV4地址
      * @return: 如果给定的字符串是一个IPV4地址，则返回true，否则返回false
      */
    static bool valid_ipv4(const char* str);

    /** 得到网卡名和对应的IP
      * @eth_ip_array: 用于保存所有获取到的IP地址
      * @exception: 如果发生错误，抛出CSyscallException异常
      */
    static void get_ethx_ip(TEthIPArray& eth_ip_array);

    /** 根据网卡名得到绑定在该网卡上的所有IP地址
      * @ethx: 网卡名，如：eth0，如果为NULL，则表示所有网卡
      * @ip_array: 用于保存所有获取到的IP地址
      * @exception: 如果发生错误，抛出CSyscallException异常
      */
    static void get_ethx_ip(const char* ethx, TIPArray& ip_array);    

    /** 根据整数类型的IP，得到字符串类型的IP地址
      * @ip: 整数类型的IP
      * @return: 字符串类型的IP地址
      */
    static std::string get_ip_address(int ip);

    /** 将一个字符串转换成IPV4整数类型的地址
      * 成功返回大于0的值，否则返回0
      */
    static int convert_ipv4(const char* ip);

    /** 判断传入的字符串是否为接口名，如：eth0等
      * @return: 如果str是接口名，则返回true，否则返回false
      */
    static bool is_ethx(const char* str);

    /** 判断传入的字符串是否为广播地址
      * @return: 如果str为广播地址，则返回true，否则返回false
      */
    static bool is_broadcast_address(const char* str);

    /** 超时POLL单个fd对象
      * @fd: 被POLL的单个fd，注意不是fd数组
      * @events_requested: 请求监控的事件
      * @milliseconds: 阻塞的毫米数，总是保证等待这个时长，即使被中断
      * @events_returned: 用来保存返回的事件，如果为NULL，则无事件返回，通过检测返回事件，可以明确是哪个事件发生了
      * @return: 超时返回false，有事件返回true
      * @exception: 网络错误，则抛出CSyscallException异常
      */
    static bool timed_poll(int fd, int events_requested, int milliseconds, int* events_returned=NULL);
};

NET_NAMESPACE_END
#endif // NET_UTIL_H
