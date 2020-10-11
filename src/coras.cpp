#include "coras.h"  


// Default Ctor and
Coras::Coras(){
    init();
}

Coras::~Coras(){
    // Do nothing - not necessary
}


//// Getters
std::string Coras::get_cpu_vendor_id() {
    return m_cpu_vendor_id;
}

std::string Coras::get_cpu_model() {
    return m_cpu_model;
}

std::string Coras::get_cpu_model_name() {
    return m_cpu_model_name;
}

std::string Coras::get_cpu_cache_size() {
    return m_cpu_cache_size;
}

std::string Coras::get_cpu_total_cores() {
    return m_cpu_siblings;
}

std::string Coras::get_cpu_physical_cores() {
    return m_cpu_cores;
}

std::string Coras::get_cpu_flags() {
    return m_cpu_flags;
}

long Coras::get_mem_total() {
    retrieve_mem_total();
    return m_mem_total;
}

long Coras::get_mem_free() {
    retrieve_mem_free();
    return m_mem_free;
}

long Coras::get_mem_used() {
    retrieve_mem_used();
    return m_mem_used;
}

long Coras::get_mem_buffer() {
    retrieve_mem_buffers();
    return m_mem_buffers;
}

long Coras::get_swap_mem_total() {
    retrieve_mem_swap_total();
    return m_mem_swap_total;
}

long Coras::get_swap_mem_free() {
    retrieve_mem_swap_free();
    return m_mem_swap_free;
}

std::string Coras::get_os_name() {
    return m_os_name;
}

std::string Coras::get_hostname() {
    return m_domain_name;
}

long Coras::get_uptime() {
    retrieve_uptime();
    return m_uptime;
}

std::vector<std::string> Coras::get_gpu_vendor_ids() {
    return m_gpu_vendor_ids;
}

std::vector<std::string> Coras::get_gpu_card_names() {
    return m_gpu_card_names;
}

std::vector<double> Coras::get_gpu_temps() {
    retrieve_gpu_temp();
    return m_gpu_temps;
}

std::vector<double> Coras::get_gpu_power_draws() {
    retrieve_gpu_power_draw();
    return m_gpu_power_draws;
}

std::string Coras::get_gpu_vendor_id_at(int location) {
    std::string to_return = "Unknown";
    if (location < m_gpu_vendor_ids.size()){
        to_return = m_gpu_vendor_ids.at(location);
    }
    return to_return;
}

std::string Coras::get_gpu_card_name_at(int location) {
    std::string to_return = "Unknown";
    if (location < m_gpu_card_names.size()){
        to_return = m_gpu_card_names.at(location);
    }
    return to_return;
}

int Coras::get_gpu_temp_at(int location) {
    retrieve_gpu_temp();
    int to_return = -1;
    if (location < m_gpu_temps.size()){
        to_return = m_gpu_temps.at(location);
    }
    return to_return;
}

int Coras::get_gpu_power_draws_at(int location) {
    retrieve_gpu_power_draw();
    int to_return = -1;
    if (location < m_gpu_power_draws.size()){
        to_return = m_gpu_power_draws.at(location);
    }
    return to_return;
}

bool Coras::get_has_AMD() {
    retrieve_avail_card_types();
    return m_has_AMD;
}

bool Coras::get_has_NVIDIA() {
    retrieve_avail_card_types();
    return m_has_NVIDIA;
}



std::vector<double> Coras::get_cpu_core_temps(){
    return m_cpu_core_temps;
}

std::vector<double> Coras::get_cpu_core_freqs(){
    return m_cpu_core_freqs;
}

std::vector<double> Coras::get_cpu_min_freqs(){
    return m_cpu_core_min_freqs;
}

std::vector<double> Coras::get_cpu_max_freqs(){
    return m_cpu_core_max_freqs;
}

long Coras::get_cpu_core_temp_at(long input) {
    long to_return = -1;
    if (input <= m_cpu_core_temps.size()){
        to_return = m_cpu_core_temps.at(input);
    }
    return to_return;
}

long Coras::get_cpu_core_freq_at(long input) {
    long to_return = -1;
    if (input <= m_cpu_core_freqs.size()){
        to_return = m_cpu_core_freqs.at(input);
    }
    return to_return;
}

long Coras::get_cpu_core_min_freq_at(long input) {
    long to_return = -1;
    if (input <= m_cpu_core_min_freqs.size()){
        to_return = m_cpu_core_min_freqs.at(input);
    }
    return to_return;
}

long Coras::get_cpu_core_max_freq_at(long input) {
    long to_return = -1;
    if (input <= m_cpu_core_max_freqs.size()){
        to_return = m_cpu_core_max_freqs.at(input);
    }
    return to_return;
}

std::string Coras::get_os_info(){
    std::string result = "";

    result += "System Information: \n";
    result += "==============================\n";
    result += "OS Name:     \t" + get_os_name();
    result += "\nUser Name: \t" + get_hostname();
    result += "\nUptime:    \t" + std::to_string(get_uptime()); 
    result += " sec (" + std::to_string(get_uptime()/60) + " min)";
    result += " (" + std::to_string(get_uptime()/3600) + " hours)";
    result += "\n";

    return result;
}

std::string Coras::get_memory_info() {
    std::string result = "";

    result += "Sytem Memory Information: \n";
    result += "==============================\n";
    result += "\nTotal Memory:  \t" + auto_size(get_mem_total());
    result += "\nFree Memory:   \t" + auto_size(get_mem_free());
    result += "\nUsed Memory:   \t" + auto_size(get_mem_used());
    result += "\nBuffer Memory: \t" + auto_size(get_mem_buffer());
    result += "\nTotal Swap:    \t" + auto_size(get_swap_mem_total());
    result += "\nFree Swap:     \t" + auto_size(get_swap_mem_free());
    result += "\nUsed Swap:     \t" + auto_size(get_swap_mem_total() - get_swap_mem_free());
    result += "\n";

    return result;
}

std::string Coras::get_cpu_info() {
    std::string result = "";
    std::string trailing_temp_str = "°C";

    result += "Sytem CPU Information: \n";
    result += "==============================";
    result += "\nVendor ID:         " + get_cpu_vendor_id();
    result += "\nModel:             " + get_cpu_model();
    result += "\nModel Name:        " + get_cpu_model_name(); 
    result += "\nCache Size:        " + get_cpu_cache_size();
    result += "\nTotal Cores:       " + get_cpu_total_cores();
    result += "\nPhysical Cores:    " + get_cpu_physical_cores(); 
    result += "\nCore Frequencies:  ";
    result += "\n" + to_list_string(get_cpu_core_freqs(), "\t\t    Core ", " GHz");
    result += "\nCore Temperatures: ";
    result += "\n" + to_list_string(get_cpu_core_temps(), "\t\t    Core ", trailing_temp_str);
    result += "\nFlags:             " + get_cpu_flags();
    result += "\n";

    return result;
}

std::string Coras::get_gpu_info() {
    std::string result = "";
    std::string trailing_temp_str = "°C";
    std::string trailing_power_str = "W";
    
    result += "Sytem GPU Information: \n";
    result += "==============================";
    result += "\nCard Family:    \n\t" + to_list_string(get_gpu_vendor_ids(), "\t\tCard ", "");
    result += "\nCard Name:      \n\t" + to_list_string(get_gpu_card_names(), "\t\tCard ", "");
    result += "\nCard Temp:      \n\t" + to_list_string(get_gpu_temps(), "\t\tCard ", trailing_temp_str);
    result += "\nCard Power Draw:\n\t" + to_list_string(get_gpu_power_draws(), "\t\tCard ", trailing_power_str);
    result += "\n";

    return result;
}


//// Class Init Function
void Coras::init(){
    // Retrieve the information, except that which changes constantly
    // Retrieve the CPU Information
		retrieve_cpu_vendor_id();
		retrieve_cpu_model();
		retrieve_cpu_model_name();
		retrieve_cpu_cache_size();
		retrieve_cpu_siblings();
		retrieve_cpu_cores();
		retrieve_cpu_flags();
		retrieve_cpu_core_temps();
		retrieve_cpu_core_freqs();
		retrieve_cpu_max_freqs();
		retrieve_cpu_min_freqs();

    // Retrieve Memory Information
		retrieve_mem_total();
		retrieve_mem_free();
		retrieve_mem_used();
		retrieve_mem_buffers();
		retrieve_mem_swap_total();
		retrieve_mem_swap_free();

	// Retrieve System Information
		retrieve_os_name();
		retrieve_hostname();
		retrieve_uptime();

    // Retrieve the GPU information
        retrieve_gpu_temp();
        retrieve_gpu_vendor_id();
        retrieve_gpu_card_name();
        retrieve_gpu_power_draw();
        retrieve_avail_card_types();
}


//// Protected Manupulation Functions
std::string Coras::get_line(const std::string& file_path, const std::string& to_search_for){
	// Read the file into a vector line by line
	std::vector<std::string> input_lines;
	static std::string line_to_return = "";
    std::string line;
	std::ifstream input_file(file_path.c_str(), std::ios::in);
	if (input_file.is_open()){
		while(std::getline(input_file, line)){
			input_lines.push_back(line);
		}
		input_file.close();
	
		// Search the vector for the required string
		std::string to_look_for = to_lower_string(to_search_for);
        for (auto i = 0; i < input_lines.size(); i++){
			// look for case-insensitive matching of part of the string
            std::string temp_string_index = to_lower_string(input_lines.at(i));
            if(temp_string_index.find(to_look_for) != std::string::npos){
                line_to_return = input_lines.at(i);
                break;
            }// end of if
		}// end of for
	}// end of if
	
	//Clear the vector
	input_lines.clear();
	return line_to_return;
}

std::string Coras::get_line(const std::string& file_path, long line_num){
	// Read the file into a vector line by line
	std::vector<std::string> input_lines;
	static std::string line_to_return = "";
    std::string line;
	std::ifstream input_file(file_path.c_str(), std::ios::in);
	if (input_file.is_open()){
		while(std::getline(input_file, line)){
			input_lines.push_back(line);
		}
		input_file.close();
	
		// Search the vector for the required string
		for (auto i = 0; i < input_lines.size(); i++){
			// look for case-insensitive matching
			if(i == line_num){
				line_to_return = input_lines.at(i);
                break;
		    }// end of if
		}//end of for
	}// end of if
	
	//Clear the vector
	input_lines.clear();
	return line_to_return;
}

std::string Coras::to_lower_string(const std::string& input_string){
    // Convert each character to it's lowercase equivalent
    std::string to_return = input_string;
    std::transform(to_return.begin(), to_return.end(), to_return.begin(), ::tolower);
    return to_return;
}

std::string Coras::auto_size(long input){
    static std::string to_return = "";

    // Divide based on the size
    if(input < 1024) { //Bytes
        to_return = std::to_string(input);
        to_return += " KB";
    }else if(input < (1024.0*1024)) { //KB
        to_return = std::to_string(input/1024.0);
        to_return += " MB";
    }else if(input < (1024.0*1024*1024)) { //MB
        to_return = std::to_string(input/1024.0/1024);
        to_return += " GB";
    }else if(input < (1024.0*1024*1024*1024)) { //GB
        to_return = std::to_string(input/1024.0/1024/1024);
        to_return += " TB";
    }else { //TB   
        to_return = std::to_string(input/1024.0/1024/1024/1024);
        to_return += " EB";
    }

    return to_return;
}

std::string Coras::to_list_string(std::vector<double> input_vec, const std::string& leading_str, const std::string& trailing_str){
    // Convert the double values to strings and input them into the original function
    std::vector<std::string> converted_vec;
    converted_vec.clear();
    //Determine the whether the size is adaquate
    if (input_vec.size() > 0){
        for(double i: input_vec){
            converted_vec.push_back(std::to_string(i));
        }
    }
    
    return to_list_string(converted_vec, leading_str, trailing_str);
}

std::string Coras::to_list_string(std::vector<std::string> input_vec, const std::string& leading_str, const std::string& trailing_str) {
    std::string to_return;

    // Create the output as required
    if(input_vec.size() > 0){
        std::string whitespace = "          ";
        for(auto counter = 0; counter < input_vec.size(); counter++){
            if(counter < 10){
                to_return += leading_str + std::to_string(counter) + ":" + whitespace.substr(0, whitespace.length()-2) + (input_vec.at(counter)) + trailing_str + "\n";
            }else if(counter < 100){
                to_return += leading_str + std::to_string(counter) + ":" + whitespace.substr(0, whitespace.length()-3) + (input_vec.at(counter)) + trailing_str + "\n";
            }else{
                to_return += leading_str + std::to_string(counter) + ":" + whitespace.substr(0, whitespace.length()-4) + (input_vec.at(counter)) + trailing_str + "\n";
            }
        }
    }

    return to_return;
}

void Coras::execute_command(std::string command){
    // Obtain a bash command, execute it, and save the data
    std::array<char, 128> buffer;
	m_read_command_output.clear();
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
	if(!pipe){
		//throw std::runtime_error("popen() failed!");
        return;
	}
	
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr){
		m_read_command_output.push_back(buffer.data());
	}
	return;
}


//// System CPU Information Functions
void Coras::retrieve_cpu_vendor_id() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/cpuinfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "vendor_id";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
        }
    #endif
    m_cpu_vendor_id = result;
}

void Coras::retrieve_cpu_model() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/cpuinfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "model";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
        }
    #endif
    m_cpu_model = result;
}

void Coras::retrieve_cpu_model_name() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/cpuinfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "model name";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
        }
    #endif
    m_cpu_model_name = result;
}

void Coras::retrieve_cpu_cache_size() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/cpuinfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "cache size";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
        }
    #endif
    m_cpu_cache_size = result;
}

void Coras::retrieve_cpu_siblings() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/cpuinfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "siblings";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
        }
    #endif
    m_cpu_siblings = result;
}

void Coras::retrieve_cpu_cores() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/cpuinfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "cpu cores";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
        }
    #endif
    m_cpu_cores = result;
}

void Coras::retrieve_cpu_flags() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/cpuinfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "flags";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
        }
    #endif
    m_cpu_flags = result;
}

void Coras::retrieve_cpu_core_temps() {
    std::string result = "-777";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        // Clear the temps
        m_cpu_core_temps.clear();

        // Set the path
        std::string path_to_file_part1 = "/sys/devices/platform/coretemp.";
        std::string path_to_file_part2 = "/hwmon/hwmon";
        std::string path_to_file_part3 = "/temp";
        std::string path_to_file_part4 = "_input";
        std::string path_to_file_part5 = "_label";
        std::string path_to_file = "";
        std::string path_to_info = ""; 
        std::string label_info = "";

        // To keep the complexity at O(n) I'll check individually
        // Find the base subdirectory to scout for temps
        const int TOTAL_MAX_COUNT = 1000;
        for (auto counter = 0; counter < TOTAL_MAX_COUNT; counter++){
            path_to_file = path_to_file_part1+std::to_string(counter);
            try{
                if(fs::is_directory(fs::path(path_to_file))){
                    path_to_file_part1 = path_to_file_part1+std::to_string(counter);
                    break;
                }
            }catch(std::exception& e){
                continue;
            }
        }

        // Find the correct hwmon file
        for (auto counter = 0; counter < TOTAL_MAX_COUNT; counter++){
            path_to_file = path_to_file_part1 + path_to_file_part2 + std::to_string(counter);
            try{
                if(fs::is_directory(fs::path(path_to_file))){
                    path_to_file_part2 = path_to_file_part2 + std::to_string(counter);
                    break;
                }
            }catch(std::exception & e){
                continue;
            }
        }
        

        // Find the all the temps in the file
        for (auto core_count = 0; core_count < TOTAL_MAX_COUNT; core_count++){
            path_to_info = path_to_file_part1 + path_to_file_part2 + path_to_file_part3 + std::to_string(core_count) + path_to_file_part5;
            path_to_file = path_to_file_part1 + path_to_file_part2 + path_to_file_part3 + std::to_string(core_count) + path_to_file_part4;
            if(std::ifstream(path_to_file.c_str())){
                result = get_line(path_to_file, 0);
                label_info = get_line(path_to_info, 0);
                label_info = to_lower_string(label_info);
                if(label_info.find("core") != std::string::npos){   // Only add the cores
                    result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
                    result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());
                    m_cpu_core_temps.push_back(std::stod(result)/1000);
                }
            }
        }
    #endif
    //variable = result;
}

void Coras::retrieve_cpu_core_freqs() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        // Clear the vetor for use
        m_cpu_core_freqs.clear();
        
        // Create the string to use to look for the base frequency
        std::string path_to_file = "";
        std::string path_to_file_part1 = "/sys/class/thermal/cooling_device0/device/physical_node/subsystem/devices/cpu";
        std::string path_to_file_part2 = "/cpufreq/base_frequency";
        double temp_data = 0;
        for (auto core_counter = 0; core_counter < 1000; core_counter ++){
            path_to_file = path_to_file_part1 + std::to_string(core_counter) + path_to_file_part2;
            if(std::ifstream(path_to_file.c_str())){
                result = get_line(path_to_file, 0);
                result.erase(std::remove_if(result.begin(), result.end(), ::isblank), result.end());
                result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());
                //Result is in Hz, so, let's divide by a 1000*1000 for GHz
                temp_data = std::stod(result);
                m_cpu_core_freqs.push_back(temp_data);
            }else{
                break;
            } 
        }
    #endif
    //variable = result;
}

void Coras::retrieve_cpu_max_freqs() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        // Clear the vetor for use
        m_cpu_core_max_freqs.clear();
        
        // Create the string to use to look for the base frequency
        std::string path_to_file = "";
        std::string path_to_file_part1 = "/sys/class/thermal/cooling_device0/device/physical_node/subsystem/devices/cpu";
        std::string path_to_file_part2 = "/cpufreq/cpuinfo_max_freq";
        double temp_data = 0;
        for (auto core_counter = 0; core_counter < 1000; core_counter ++){
            path_to_file = path_to_file_part1 + std::to_string(core_counter) + path_to_file_part2;
            if(std::ifstream(path_to_file.c_str())){
                result = get_line(path_to_file, 0);
                result.erase(std::remove_if(result.begin(), result.end(), ::isblank), result.end());
                result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());
                //Result is in Hz, so, let's divide by a 1000*1000 for GHz
                temp_data = std::stod(result);
                m_cpu_core_max_freqs.push_back(temp_data);
            }else{
                break;
            } 
        }
    #endif
    //variable = result;
}

void Coras::retrieve_cpu_min_freqs() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        // Clear the vetor for use
        m_cpu_core_min_freqs.clear();
        
        // Create the string to use to look for the base frequency
        std::string path_to_file = "";
        std::string path_to_file_part1 = "/sys/class/thermal/cooling_device0/device/physical_node/subsystem/devices/cpu";
        std::string path_to_file_part2 = "/cpufreq/cpuinfo_min_freq";
        double temp_data = 0;
        for (auto core_counter = 0; core_counter < 1000; core_counter ++){
            path_to_file = path_to_file_part1 + std::to_string(core_counter) + path_to_file_part2;
            if(std::ifstream(path_to_file.c_str())){
                result = get_line(path_to_file, 0);
                result.erase(std::remove_if(result.begin(), result.end(), ::isblank), result.end());
                result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());
                //Result is in Hz, so, let's divide by a 1000*1000 for GHz
                temp_data = std::stod(result);
                m_cpu_core_min_freqs.push_back(temp_data);
            }else{
                break;
            } 
        }
    #endif
    //variable = result;
}


//// System Memory Functions
void Coras::retrieve_mem_total() {
    std::string result = "-1";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/meminfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "MemTotal:";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
            result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
            result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());
        }
    #endif
    m_mem_total = std::stol(result);
}

void Coras::retrieve_mem_free() {
    std::string result = "-1";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/meminfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "MemFree";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
            result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
            result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());
        }
    #endif
    m_mem_free = std::stol(result);
}

void Coras::retrieve_mem_used() {
    std::string result = "-1";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/meminfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "MemUsed:";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
            result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
            result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());
        }
    #endif
    m_mem_used = std::stol(result);
}

void Coras::retrieve_mem_buffers() {
    std::string result = "-1";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/meminfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "Buffers";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
            result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
            result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());
        }
    #endif
    m_mem_buffers = std::stol(result);
}

void Coras::retrieve_mem_swap_total() {
    std::string result = "-1";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/meminfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "SwapTotal";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
            result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
            result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());
        }
    #endif
    m_mem_swap_total = std::stol(result);
}

void Coras::retrieve_mem_swap_free() {
    std::string result = "-1";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/meminfo";
        if(std::ifstream(path_to_file.c_str())){
            std::string to_search_for = "SwapFree";    
            result = get_line(path_to_file, to_search_for);
            result = result.substr(result.find(":")+1, result.length());
            result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
            result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());
        }   
    #endif
    m_mem_swap_free = std::stol(result);
}


//// System Information Functions
void Coras::retrieve_os_name() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/sys/kernel/ostype";   
        if(std::ifstream(path_to_file.c_str())){
            result = get_line(path_to_file, 0);
        }
    #endif
    m_os_name = result;
}

void Coras::retrieve_hostname() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/sys/kernel/hostname";    
        if(std::ifstream(path_to_file.c_str())){
            result = get_line(path_to_file, 0);
        }
    #endif
    m_domain_name = result;
}

void Coras::retrieve_uptime() {
    std::string result = "-1";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        std::string path_to_file = "/proc/uptime";    
        if(std::ifstream(path_to_file.c_str())){
            result = get_line(path_to_file, 0);
            result = result.substr(0, result.find(" "));
        }
    #endif
    m_uptime = std::stol(result);
}


//// System GPU Information Functions
void Coras::retrieve_gpu_vendor_id() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        m_gpu_vendor_ids.clear();
        // Execute the commands a certain number of times to determine the number of cards
        // HAS NVIDIA CARD
        if(get_has_NVIDIA()){
            for (auto counter = 0; counter < MAX_GPU_COUNT; counter++){
                execute_command("nvidia-smi -q -i "+std::to_string(counter)+" -d POWER");
                if(m_read_command_output.size() >= MAX_LINES_COUNT){
                    result = "Nvidia";
                    m_gpu_vendor_ids.push_back(result);
                }
            }
        }
        // HAS AMD CARD
        if(get_has_AMD()) {
            for (auto counter = 0; counter < MAX_GPU_COUNT; counter++){
                execute_command("rockm-smi");
                if(m_read_command_output.size() > MAX_LINES_COUNT){
                    result = "AMD";
                    m_gpu_vendor_ids.push_back(result);
                }
            }
        }
    #endif
}

void Coras::retrieve_avail_card_types() {
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        if(!m_already_tested){
            // Test availability of Nvidia-Smi cli command
            execute_command("nvidia-smi -v");
            if ((m_read_command_output.front().find("command not found") != std::string::npos) || (m_read_command_output.size() == 0)){
                // Command not found, so no NVIDIA cards
                m_has_NVIDIA = false;
            }else {
                m_has_NVIDIA = true;
            }
            // Test availability of amd cli command
            execute_command("rockm-smi -v");
            if((m_read_command_output.front().find("command not found") != std::string::npos) || (m_read_command_output.size() == 0)){
                // Command not found, so no AMD cards
                m_has_AMD = false;
            }else{
                m_has_AMD = true;
            }
            
            m_already_tested = true;
        }
        
    #endif
}

void Coras::retrieve_gpu_power_draw() {
    std::string result = "-1";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this        
        m_gpu_power_draws.clear();
        // HAS NVIDIA CARD
        if (get_has_NVIDIA()) {
            // Use either the nvidia-smi or rockm-smi utility
            std::string nv_command_part1 = "nvidia-smi -q -i ";
            std::string nv_command_part2 = " -d POWER";
            for (auto counter=0; counter < MAX_GPU_COUNT; counter++) {
                execute_command(nv_command_part1+std::to_string(counter)+nv_command_part2);
                
                if(m_read_command_output.size() > MAX_LINES_COUNT) { // nvidia-smi is installed
                    result = m_read_command_output.at(11);   // May be more than 1
                    // Remove all the punctuation and alphanumerics, and only keep the numbers
                    // This will likely stop working later on if the interface changes.
                    // I'll need to write a driver for this at some point
                    result.erase(std::remove_if(result.begin(), result.end(), ::ispunct), result.end());
                    result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
                    result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());

                    // Save the power as Watts (W)
                    m_gpu_power_draws.push_back(std::stod(result)/100.0);
                }
                
            }
        }
        // HAS AND AMD CARD
        if(get_has_AMD()) { //rockm-smi is installed
            execute_command("rockm-smi");
            if(m_read_command_output.size() > MAX_LINES_COUNT){   // Sift through the data to find the information
            }
        }
    #endif
}

void Coras::retrieve_gpu_card_name() {
    std::string result = "Unknown";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        // Use either the nvidia-smi or rockm-smi utility
        m_gpu_card_names.clear();
        // HAS NVIDIA CARD
        if(get_has_NVIDIA()){
            execute_command("nvidia-smi --query-gpu=name --format=csv");
        
            for (auto counter = 1; counter < MAX_CARD_ROW; counter++){
                if(counter < m_read_command_output.size()) { // nvidia-smi is installed
                    result = m_read_command_output.at(counter);   // May be more than 1
                    // Remove all the punctuation and alphanumerics, and only keep the numbers
                    // This will likely stop working later on if the interface changes.
                    // I'll need to write a driver for this at some point
                    result.erase(std::remove_if(result.begin(), result.end(), ::ispunct), result.end());
                    result.erase(std::remove_if(result.begin(), result.end(), ::iscntrl), result.end());
                    m_gpu_card_names.push_back(result);
                }
            }
        }
        // HAS AMD CARD
        if (get_has_AMD()){
            execute_command("rockm-smi");
            if(m_read_command_output.size() > MAX_LINES_COUNT){   // Sift through the data to find the information
            }
        }
    #endif
}

void Coras::retrieve_gpu_temp() {
    std::string result = "-1";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) //&& !defined(__CYGWIN__)
        // On windows do this
    #else
        // On *nix-based do this
        m_gpu_temps.clear();
        //HAS NVIDIA CARD
        if(get_has_NVIDIA()){
            // Use either the nvidia-smi or rockm-smi utility
            std::string nv_command_part1 = "nvidia-smi -q -i ";
            std::string nv_command_part2 = " -d TEMPERATURE";
            for (auto counter=0; counter < MAX_GPU_COUNT; counter++) {
                execute_command(nv_command_part1+std::to_string(counter)+nv_command_part2);

                if(m_read_command_output.size() > 1) { // nvidia-smi is installed
                    result = m_read_command_output.at(10); // Will possibly contain more than 1 GPU
                    // Remove all the punctuation and alphanumerics, and only keep the numbers
                    // This will likely stop working later on if the interface changes.
                    // I'll need to write a driver for this at some point
                    result.erase(std::remove_if(result.begin(), result.end(), ::isalpha), result.end());
                    result.erase(std::remove_if(result.begin(), result.end(), ::ispunct), result.end());
                    result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());

                    m_gpu_temps.push_back(std::stod(result));
                }
            }
        }
        //HAS AMD CARD
        if(get_has_AMD()){
            //rockm-smi is installed
            execute_command("rockm-smi");
            if(m_read_command_output.size() > 0){   // Sift through the data to find the information

            }
        }
    #endif
}