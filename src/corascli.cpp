#include "corascli.h"  



std::string CorasCLI::get_gpu_information() {
    // This function will format the input received from Coras into proper cli format for display
    // in a terminal
    std::string to_return = "";
    std::string degrees_symbol = " °C";
    std::string watt_symbol = " W";
    long gpu_single_column_size = 14;
    long total_column_size = gpu_single_column_size*4;
    long gpu_vendor_size = 10;
    long gpu_temp_size = 12;
    long gpu_power_size = 10;
    long gpu_card_name_size = total_column_size-gpu_vendor_size-gpu_temp_size-gpu_power_size;

    to_return += "";
    to_return += adapted_string("Graphical Processing Unit (GPU):", total_column_size);
    to_return += "\n";
    to_return += repeat_char('=', total_column_size);
    to_return += "\n";
    // Vendor, Card Name, Temp, Power Draw
    to_return += adapted_string("Vendor", gpu_vendor_size);
    to_return += adapted_string("Card Name", gpu_card_name_size);
    to_return += adapted_string("Temp", gpu_temp_size);
    to_return += adapted_string("Power", gpu_power_size);
    to_return += "\n";
    to_return += repeat_char('-',total_column_size);
    to_return += "\n";
    for (auto i = 0; i < m_coras_info.get_gpu_vendor_ids().size(); i++) {
        to_return += adapted_string(m_coras_info.get_gpu_vendor_id_at(i),gpu_vendor_size);
        to_return += adapted_string(m_coras_info.get_gpu_card_name_at(i),gpu_card_name_size);
        to_return += adapted_string(to_string(m_coras_info.get_gpu_temp_at(i), 3)+degrees_symbol,gpu_temp_size);
        to_return += adapted_string(to_string(m_coras_info.get_gpu_power_draws_at(i), 3)+watt_symbol,gpu_power_size);
        to_return += "\n";
    }


    return to_return;
}

std::string CorasCLI::get_cpu_information() {
    // This function will format the input received from Coras into proper cli format for display
    // in a terminal
    std::string to_return = "";
    std::string degrees_symbol = "°C";
    double freq_divide = 1000.0*1000;
    int total_column_size = 14+14+14+14; // 4 columns
    int cpu_prop_size = 21;
    int cpu_value_size = total_column_size - cpu_prop_size;

    to_return += "Central Processing Unit (CPU):\n";
    to_return += repeat_char('=', total_column_size);
    to_return += "\n";
    // Core Name, Max Temp, Curr Temp, Min Temp
    to_return += adapted_string("Core Name");
    to_return += adapted_string("Max Temp");
    to_return += adapted_string("Curr Temp");
    to_return += adapted_string("Min Temp");
    to_return += "\n";
    to_return += repeat_char('-', total_column_size);
    to_return += "\n";
    for (auto i = 0; i < std::stoi(m_coras_info.get_cpu_physical_cores()); i++) {
        to_return += adapted_string("Core "+to_string(i));
        to_return += adapted_string(to_string(100,3)+" "+degrees_symbol);
        to_return += adapted_string(to_string(m_coras_info.get_cpu_core_temp_at(i),3)+" "+degrees_symbol);
        to_return += adapted_string(to_string(0,3)+" "+degrees_symbol);
        to_return += "\n";
    }

    // Core Name, Max Freq, Curr Freq, Min Freq
    to_return += "\n";
    to_return += adapted_string("Core Name");
    to_return += adapted_string("Max Freq");
    to_return += adapted_string("Curr Freq");
    to_return += adapted_string("Min Freq");
    to_return += "\n";
    to_return += repeat_char('-', total_column_size);
    to_return += "\n";
    for (auto i = 0; i < std::stoi(m_coras_info.get_cpu_total_cores()); i++) {
        to_return += adapted_string("Core "+to_string(i));
        to_return += adapted_string(to_string(m_coras_info.get_cpu_core_max_freq_at(i)/freq_divide,3)+" GHz");
        to_return += adapted_string(to_string(m_coras_info.get_cpu_core_freq_at(i)/freq_divide,3)+" GHz");
        to_return += adapted_string(to_string(m_coras_info.get_cpu_core_min_freq_at(i)/freq_divide,3)+" GHz");
        to_return += "\n";
    }

    // CPU Property, Value
    to_return += "\n";
    to_return += adapted_string("CPU Properties:", cpu_prop_size);
    to_return += "\n";
    to_return += repeat_char('-', total_column_size);
    // Vendor Id
    to_return += "\n";
    to_return += adapted_string("Vendor ID: ", cpu_prop_size);
    to_return += adapted_string(m_coras_info.get_cpu_vendor_id(), cpu_value_size);
    // Model Name
    to_return += "\n";
    to_return += adapted_string("Model Name: ", cpu_prop_size);
    to_return += adapted_string(m_coras_info.get_cpu_model_name(), cpu_value_size);
    // Model
    to_return += "\n";
    to_return += adapted_string("Model: ", cpu_prop_size);
    to_return += adapted_string(m_coras_info.get_cpu_model(), cpu_value_size);
    // Total Cores
    to_return += "\n";
    to_return += adapted_string("Total Cores: ", cpu_prop_size);
    to_return += adapted_string(m_coras_info.get_cpu_total_cores(), cpu_value_size);
    // Physical Cores
    to_return += "\n";
    to_return += adapted_string("Physical Cores: ", cpu_prop_size);
    to_return += adapted_string(m_coras_info.get_cpu_physical_cores(), cpu_value_size);
    // Cache Size
    to_return += "\n";
    to_return += adapted_string("Cache Size: ", cpu_prop_size);
    to_return += adapted_string(m_coras_info.get_cpu_cache_size(), cpu_value_size);
    to_return += "\n";
    // Flags
    to_return += "\n";
    to_return += adapted_string("Flags: ", cpu_prop_size);
    to_return += adapted_string(m_coras_info.get_cpu_flags(), cpu_value_size);
    to_return += "\n";

    return to_return;
}

std::string CorasCLI::get_mem_information() {
    // This function will format the input received from Coras into proper cli format for display
    // in a terminal
    std::string to_return = "";
    double mem_divide = 1024.0*1024;

    to_return += "Memory:\n";
    to_return += "========================================================";
    to_return += "\n";
    // Row 1: Memory
    to_return += adapted_string("Total");
    to_return += adapted_string("Used");
    to_return += adapted_string("Free");
    to_return += adapted_string("Buffer");
    to_return += "\n";
    to_return += "--------------------------------------------------------";
    to_return += "\n";
    to_return += adapted_string(to_string(m_coras_info.get_mem_total()/mem_divide,3)+" GB");
    to_return += adapted_string(to_string(m_coras_info.get_mem_used()/mem_divide,3)+" GB");
    to_return += adapted_string(to_string(m_coras_info.get_mem_free()/mem_divide,3)+" GB");
    to_return += adapted_string(to_string(m_coras_info.get_mem_buffer()/mem_divide,3)+" GB");
    to_return += "\n";
    // Row 2: Swap
    to_return += "\n";
    to_return += "Swap:\n";
    to_return += "========================================================";
    to_return += "\n";
    to_return += adapted_string("Total");
    to_return += adapted_string("Used");
    to_return += adapted_string("Free");
    to_return += "\n";
    to_return += "--------------------------------------------------------";
    to_return += "\n";
    to_return += adapted_string(to_string(m_coras_info.get_swap_mem_total()/mem_divide,3)+" GB");
    to_return += adapted_string(to_string((m_coras_info.get_swap_mem_total()-m_coras_info.get_swap_mem_free())/mem_divide,3)+" GB");
    to_return += adapted_string(to_string(m_coras_info.get_swap_mem_free()/mem_divide,3)+" GB");
    to_return += "\n";

    return to_return;
}

std::string CorasCLI::get_os_information() {
    // This function will format the input received from Coras into proper cli format for display
    // in a terminal
    std::string to_return = "";
    long total_column_size = 14+14+14+14;
    long os_prop_size = 21;
    long os_value_size = total_column_size - os_prop_size;

    to_return += "";
    to_return += adapted_string("System Information: ", total_column_size);
    to_return += "\n";
    to_return += repeat_char('=', total_column_size);
    to_return += "\n";
    to_return += adapted_string("Operating System:", os_prop_size);
    to_return += adapted_string(m_coras_info.get_os_name(), os_value_size);
    to_return += "\n";
    to_return += adapted_string("Hostname:", os_prop_size);
    to_return += adapted_string(m_coras_info.get_hostname(), os_value_size);
    to_return += "\n";
    to_return += adapted_string("Uptime:", os_prop_size);
    to_return += adapted_string(to_string(m_coras_info.get_uptime()/60.0,3)+" min(s) ["+to_string(m_coras_info.get_uptime()/60.0/60)+" hour(s)]", os_value_size);
    to_return += "\n";

    return to_return;
}

std::string CorasCLI::adapted_string(std::string input, int length) {
    // This function will convert the input string to a length provided
    std::string to_return = "";
    std::string whitespace = "";

    // Add in spaces equal to length for padding
    for (auto i = 0; i < length; i++){
        whitespace += " ";
    }
    
    // Calculate the length of the string. If the string is longer than length
    // Remove the that part of the string, and add in a "..." before the end of the string
    // otherwise pad the string in such a way that it's equal to length
    if(input.length() > length){
        // Remove the excess of the string
        to_return = input.substr(0, length-3);
        to_return += "...";
    }else if(input.length() < length){
        to_return = input;
        to_return += whitespace.substr(0, length - input.length());
    }else {
        to_return = input;
    }

    return to_return;
}

std::string CorasCLI::to_string(double input, int decimals) {
    // This function converts all numerical values tostrings using the
    // built-in std::to_string function. Afterwards convert it to the the proper decimal
    std::string to_return = "";

    //Convert to string
    to_return = std::to_string(input);
    //Add the decimals
    to_return = to_return.substr(0, to_return.find('.')+decimals);

    return to_return;
}

std::string CorasCLI::repeat_char(char input, int length) {
    // This function will take a char and repeat it length times and return it
    std::string to_return = "";

    for (auto i = 0; i < length; i++) {
        to_return += input;
    }

    return to_return;
}
