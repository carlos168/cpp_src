#ifndef __ARGS_PARSER_H__
#define __ARGS_PARSER_H__

#include <string>
#include <map>
#include <vector>
#include <sstream>

class Args_parser
{
public:
    Args_parser():_process_name("") {};
    ~Args_parser(){};


    std::string get_process_name()
    {
        return _process_name;
    }


    void parse_args(int argc, char **argv)
    {
        _map_args.clear();
        std::string process_name = argv[0];
        std::string::size_type pos = process_name.find_last_of("/");
        if (pos == std::string::npos) {
            pos = process_name.find_last_of("\\");
            if (pos == std::string::npos) {
                _process_name = process_name;
            } else {
                _process_name = process_name.substr(pos+1, process_name.size()-pos-1);
            }   
        } else {
            _process_name = process_name.substr(pos+1, process_name.size()-pos-1);
        }   

        std::string temp;
        for(int i = 1; i<argc; i++) {
            temp = argv[i];
            if ('-' == temp[0]) {
                std::string key = temp.substr(1);
                std::string value = ""; 
                if ((i+1) < argc) {
                    temp = argv[i+1];
                    if ('-' != temp[0]) {
                        value = temp;
                        ++i;
                    }   
                }   
                _map_args[key] = value;
            } else {
                printf("invalid arg: %s\n", temp.c_str());
            }   
        }
        return;
    }


    void show()
    {
        std::map<std::string, std::string>::iterator it = _map_args.begin();
        for (;it != _map_args.end(); ++it)
        {
            printf("key: %s, value: %s\n", it->first.c_str(), it->second.c_str());
        }
    }

    template<typename T>
    bool get_opt(const std::string &key, T* value = NULL, T* default_value = NULL)
    {
        bool bret = false;
        std::map<std::string, std::string>::iterator it = _map_args.find(key);
        if (it != _map_args.end()) {
            if (value != NULL) {
                std::istringstream s(it->second);
                s>>*value;
            }
            bret = true;
        } else {
            if ((value != NULL) && (default_value != NULL)) {
                *value = *default_value;
            }
        }
        return bret;
    }

private:
    std::string _process_name;
    std::map<std::string, std::string> _map_args;

};

#endif
