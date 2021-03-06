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
 * Author: eyjian@gmail.com, eyjian@qq.com
 *
 */
#include <scheduler/scheduler.h>
#include "packet_handler.h"
#include "protocol_parser.h"
#include "scheduler/scheduler.h"
MOOON_NAMESPACE_BEGIN

void CPacketHandler::timeout(time_t now)
{
}

bool CPacketHandler::handle(IProtocolParser* protocol_parser, IRequestResponsor* request_responsor)
{    
    schedule_message_t* schedule_message
        = static_cast<schedule_message_t*>(protocol_parser->get_buffer());

    return get_scheduler()->push_message(schedule_message);
}

MOOON_NAMESPACE_END
