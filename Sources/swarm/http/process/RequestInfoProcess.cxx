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

#include "RequestInfoProcess.hxx"

#include <sstream>
#include <swarm/http/message/body/HTTPBody.hxx>
#include <swarm/http/message/response/HTTPResponseBuilder.hxx>
#include <swarm/http/stream/HTTPStringStream.hxx>
#include <swarm/http/message/request/HTTPRequest.hxx>

namespace swarm {
    namespace http {

        // Override
        HTTPResponse RequestInfoProcess::process(HTTPContext &context) {

            // Create stream
            std::stringstream out;
            
            out << "<html>";
            out << "<head>";
            out << "<title>Request info</title>";
            out << "</head>";
            out << "<body>";
            
            const HTTPRequest & request = context.request();
            
            out << "<h1>Request info</h1>";
            out << "<ul>";
            out << "<li><b>Version:</b>" << request.version() << "</li>";
            out << "<li><b>Method:</b>" << request.method() << "</li>";
            out << "<li><b>Path:</b>" << request.path() << "</li>";
            out << "<li><b>Uri:</b>" << request.uri() << "</li>";
            out << "</ul>";
            
            out << "<h1>Request headers</h1>";
            
            // Find headers
            auto headers = request.headers();
            if (!headers.empty()) {
                out << "<ul>";
                
                for (auto entry : headers) {
                    out << "<li><b>" << entry.first << ":</b>" << entry.second << "</li>";
                }
                
                out << "</ul>";
            }
            
            out << "<h1>Query parameters</h1>";
            
            // Find headers
            auto parameters = request.queryParams();
            if (!parameters.empty()) {
                out << "<ul>";
                
                for (auto entry : parameters) {
                    out << "<li><b>" << entry.first << ":</b>" << entry.second << "</li>";
                }
                
                out << "</ul>";
            }
            
            out << "<h1>Body</h1>";
            
            auto body = request.body();
            if (body) {
                out << "<p>Yes : " << body->mediaType();
                if (body->length() > 0) {
                    out << " (" << body->length() << ")";
                }
                out << "</p>";
            } else {
                out << "<p>No body</p>";
            }
            
            out << "</body>";
            out << "</html>";

            // Create stream
            std::shared_ptr<HTTPStream> outStream = HTTPStringStream::get(std::move(out));
            
            return HTTPResponseBuilder{}
                .status(HTTPResponseStatus::OK)
                .body(std::make_shared<HTTPBody>(MediaType::TEXT_HTML, outStream))
                .build();
        }
    }
}
