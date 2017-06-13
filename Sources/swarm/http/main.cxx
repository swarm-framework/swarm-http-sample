/*
 * Copyright 2017 Dami <contact@damiengiron.me>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "process/RequestInfoProcess.hxx"
#include "swarm/http/service/HTTPServiceBuilder.hxx"
#include <swarm/http/fcgi/FastCGIServerDelegate.hxx>
#include <swarm/http/message/request/HTTPMethod.hxx>
#include <swarm/http/server/HTTPServer.hxx>
#include <swarm/http/router/HTTPRouter.hxx>
#include <swarm/http/router/HTTPRouterBuilder.hxx>

using namespace swarm::http;

#define DEBUG true

int main(int arc, char *argv[]) {
    
    auto logger = LOGGER(Main);
    
    logger.log(cxxlog::Level::INFO, "Create router");
    
    // Create process
    std::shared_ptr<HTTPProcess> infoProcess = std::make_shared<RequestInfoProcess>();
    
    // Create router builder
    HTTPRouterBuilder routerBuilder{};
    
    // Add process for info sub path
    routerBuilder.add(HTTPMethod::GET, "/info/*", infoProcess);
    
    // Add simple log service
    routerBuilder.add(
        HTTPServiceBuilder{}.service<void>(HTTPMethod::GET, "/ws/log").handler([](){
            LOGGER(LOG_SERVICE).log(cxxlog::INFO, "Log '/ws/log' access");
        })
    );
    
    // Router
    std::shared_ptr<swarm::http::HTTPRouter> router = routerBuilder.build();
    
    logger.log(cxxlog::Level::INFO, "Create delegate");
    
    // Create fast cgi delegate
    auto delegate = std::make_shared<swarm::http::fastcgi::FastCGIServerDelegate>();
    
    logger.log(cxxlog::Level::INFO, "Create server");
    
    // Create server
    swarm::http::HTTPServer server{delegate, 9090, router};
    
    logger.log(cxxlog::Level::INFO, "Start server");
    
    // Process launch
    server.process();
    
    logger.log(cxxlog::Level::INFO, "Stop server");
}
