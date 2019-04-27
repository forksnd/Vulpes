#include "handler.hpp"
#include "../halo_functions/console.hpp"
#include <vector>
#include <cstdio>
#include <string.h>
#include <regex>

using namespace std;

static vector<char*> commands;
regex command_split("([^[:space:]\"]+)|\"([^\"]*)\"|\"([^\"]*)");

// Adds Vulpes results to an already constructed autocomplete list.
__attribute__((cdecl))
void auto_complete(char* buffer[], uint16_t* current_index, const char* input){
    string input_str(input);

    int i = 0;
    int j = *current_index;
    while (i < commands.size() && *current_index < 256){
        string cmp_str(commands[i]);
        if (input_str.size() <= cmp_str.size()){
            cmp_str.resize(input_str.size());
            if (input_str == cmp_str){
                buffer[j] = commands[i];
                j++;
            };
        };
        i++;
    };
    *current_index = j;
}

// Returns false if the original Halo function should not fire after this.
__attribute__((cdecl))
bool process_command(char* input, int32_t network_machine_id){
    string input_str(input);
    // A line starting with this should be ignored.
    if(input_str.find(";") == 0){
        return false;
    };
    if(input_str.find("#") == 0){
        return false;
    };
    if(input_str.find("//") == 0){
        return false;
    };

    vector<string> matches;

    smatch arg_match;
    string::const_iterator search_start(input_str.cbegin());
    while(regex_search(search_start, input_str.cend(), arg_match, command_split)){
        if(arg_match[1] != ""){
            string str = arg_match[1];
            int semicolon_pos = str.find(";");
            if (semicolon_pos != string::npos){
                if (semicolon_pos > 0){
                    matches.push_back(str.substr(0, semicolon_pos));
                };
                break; // We shouldn't match anything after a semicolon
            };
            matches.push_back(str);
        }else if(arg_match[2] != ""){
            matches.push_back(arg_match[2]);
        }else if(arg_match[3] != ""){
            matches.push_back(arg_match[3]);
        };
        search_start = arg_match.suffix().first;
    };
    console_out_warning("Found args:");
    for (int i=0; i < matches.size(); i++){
        console_out(matches[i]);
    };
    return true;
}