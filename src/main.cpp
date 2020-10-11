#include <iostream>
#include <map>

#include "corascli.h"

void display_information(std::map<std::string, bool> arguments);

int main(int argc, char *argv[]){
    // Variable declarations
    std::map<std::string, bool> arg_map;

    // Add the map variables as required
    arg_map.insert({"--help", false});
    arg_map.insert({"--gpu", false});
    arg_map.insert({"--cpu", false});
    arg_map.insert({"--mem", false});
    arg_map.insert({"--os", false});

    // Set flags based on the passed arguments
    for (auto i = 1; i < argc; i++) {
        // If the argument is passed, flip the flag to display the information
        std::string arg = argv[i];
        if (arg_map.find(arg) != arg_map.end()) {
            arg_map[arg] = true;
        }

    }

    // In the event that no flags are passed, display the help menu
    if (argc <= 1) {
        arg_map["--help"] = true;
    }

    // Display the Hardware Information
    display_information(arg_map);

    return 0;
}

void display_information(std::map<std::string, bool> arguments) {
    // This function will look at the provided map and only display data if it's not empty
    // Display all the information individually
    if (!arguments.at("--help")){
        // Obtain teh Hardware Information
        CorasCLI coras_cli;

        // If the map is not empty display the hardware information
        // CPU Information
        if (arguments.at("--cpu")) {
            std::cout << coras_cli.get_cpu_information() << std::endl;
        }
        // GPU Information
        if (arguments.at("--gpu")) {
            std::cout << coras_cli.get_gpu_information() << std::endl;
        }
        // Mem Information
        if (arguments.at("--mem")) {
            std::cout << coras_cli.get_mem_information() << std::endl;
        }
        // OS Information
        if (arguments.at("--os")) {
            std::cout << coras_cli.get_os_information() << std::endl;
        }
    }else{
        // Help Information
        std::cout << "" << std::endl;
        std::cout << "coras [arguments]" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Arguments:" << std::endl;
        std::cout << "\t--gpu \t Displays the GPU information." << std::endl;
        std::cout << "\t--cpu \t Displays the CPU information." << std::endl;
        std::cout << "\t--mem \t Displays Memory information." << std::endl;
        std::cout << "\t--os  \t Displays System information." << std::endl;
        std::cout << "\t--help\t Displays this information." << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Examples:" << std::endl;
        std::cout << "\tcoras --gpu" << std::endl;
        std::cout << "\tcoras --cpu --os" << std::endl;
        std::cout << "" << std::endl;
    }
}