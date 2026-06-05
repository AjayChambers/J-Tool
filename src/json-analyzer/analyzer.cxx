#include <iostream>
#include <json-analyzer.hxx>


namespace JT
{
    /************************************************************
     *
     ************************************************************/
    JsonAnalyzer::JsonAnalyzer(JsonBuffer buff)
     : buffer(std::string(buff.begin(), buff.end())) {}




    /************************************************************
     *
     ************************************************************/
    JsonAnalyzer::JsonAnalyzer(const std::string &json)
     : buffer(json) {}




    /************************************************************
     *
     ************************************************************/
    JsonAnalyzer::JsonAnalyzer(std::vector<char> &&json)
     : buffer(std::move(json)) {}




    /************************************************************
     * @brief Walks through the JSON data contained with in the
     *  calling JsonAnalyzer instance, and validates the data
     *  while generating an abstract tree representation of the
     *  data at the same time. If the data is invalid a
     *  JsonPosition object will be returned. The object
     *  communicates where the issue is at within the JSON by
     *  providing the row and col where the error can be found.
     ************************************************************/
    void JsonAnalyzer::analyze() {
        Iterator iter = buffer.begin();
        Iterator end  = buffer.end();

        while (iter != end) {
            ++iter;
            std::cout << *iter;
        }
    }
} // namespace JT
