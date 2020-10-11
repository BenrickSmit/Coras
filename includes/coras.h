#pragma once

#include <string>
#include <vector>
#include <sys/sysinfo.h>
#include <fstream>
#include <ctype.h>
#include <cstdlib>
#include <algorithm>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

// NOTE: will require "target_link_libraries(${PROJECT_NAME} stdc++fs)" for CMake in base CMakeLists.txt

// Improvements
//	~ \todo Add in a path checker that sets booleans that it checks to reduce io time for cpu temp etc
//	~ \todo Change the way the execute_command() function works, let it return a value which can be assigned and add getters and setters for m_read_...
//	~ \todo Create a simple cli tool and a library for use

class Coras {
	public:
		// Default ctor and dtor
		Coras();
		~Coras();

		// Getters
		// CPU Information
		std::string get_cpu_vendor_id();
		std::string get_cpu_model();
		std::string get_cpu_model_name();
		std::string get_cpu_cache_size();
		std::string get_cpu_total_cores();
		std::string get_cpu_physical_cores();
		std::string get_cpu_flags();
		std::vector<double> get_cpu_core_temps();
		std::vector<double> get_cpu_core_freqs();
		std::vector<double> get_cpu_min_freqs();
		std::vector<double> get_cpu_max_freqs();
		long get_cpu_core_temp_at(long location = 0);
		long get_cpu_core_freq_at(long location = 0);
		long get_cpu_core_min_freq_at(long location = 0);
		long get_cpu_core_max_freq_at(long location = 0);

		// Memory Information
		long get_mem_total();
		long get_mem_free();
		long get_mem_used();
		long get_mem_buffer();
		long get_swap_mem_total();
		long get_swap_mem_free();

		// OS Information
		std::string get_os_name();
		std::string get_hostname();
		long get_uptime();

		// GPU Information
		std::vector<std::string> get_gpu_vendor_ids();
		std::vector<std::string> get_gpu_card_names();
		std::vector<double> get_gpu_temps();
		std::vector<double> get_gpu_power_draws();
		std::string get_gpu_vendor_id_at(int location = 0);
		std::string get_gpu_card_name_at(int location = 0);
		int get_gpu_temp_at(int location = 0);
		int get_gpu_power_draws_at(int location = 0);
		bool get_has_AMD();
		bool get_has_NVIDIA();

		// other functions
		std::string get_memory_info();
		std::string get_gpu_info();
		std::string get_cpu_info();
		std::string get_os_info();

	protected:
		/* MEMBER FUNCTIONS */
		// Converter Functions
		std::string to_lower_string(const std::string& input_string);

		// Reader Functions
		std::string get_line(const std::string& file_path, const std::string& string_to_search);
		std::string get_line(const std::string& file_path, long line_num);

		// Size Calculator
		std::string auto_size(long input);
		std::string to_list_string(std::vector<double> input_vec, const std::string& leading_str="", const std::string& trailing_str="");
		std::string to_list_string(std::vector<std::string> input_vec, const std::string& leading_str="", const std::string& trailing_str="");

		// Execute command on shell and obtain output
		void execute_command(std::string command);

	private:
		/* MEMBER FUNCTIONS */
		// Init the system information
		void init();

		// CPU Information
		void retrieve_cpu_vendor_id();
		void retrieve_cpu_model();
		void retrieve_cpu_model_name();
		void retrieve_cpu_cache_size();
		void retrieve_cpu_siblings();
		void retrieve_cpu_cores();
		void retrieve_cpu_flags();
		void retrieve_cpu_core_temps();
		void retrieve_cpu_core_freqs();
		void retrieve_cpu_max_freqs();
		void retrieve_cpu_min_freqs();

		// Memory Information
		void retrieve_mem_total();
		void retrieve_mem_free();
		void retrieve_mem_used();
		void retrieve_mem_buffers();
		void retrieve_mem_swap_total();
		void retrieve_mem_swap_free();

		// System Information
		void retrieve_os_name();
		void retrieve_hostname();
		void retrieve_uptime();

		// Graphics Information
		void retrieve_gpu_temp();
		void retrieve_gpu_power_draw();
		void retrieve_gpu_card_name();
		void retrieve_gpu_vendor_id();
		void retrieve_avail_card_types();


		/* MEMBER VARIABLES */
		// Read command from bash
		std::vector<std::string> m_read_command_output;

		// Pure CPU information
		std::string m_cpu_vendor_id;
		std::string m_cpu_model;
		std::string m_cpu_model_name;
		std::string m_cpu_cache_size;
		std::string m_cpu_siblings;
		std::string m_cpu_cores;
		std::string m_cpu_flags;

		std::vector<double> m_cpu_core_max_freqs;
		std::vector<double> m_cpu_core_min_freqs;
		std::vector<double> m_cpu_core_freqs;
		std::vector<double> m_cpu_core_temps;

		// Memory Information
		long m_mem_total;
		long m_mem_free;
		long m_mem_used;
		long m_mem_buffers;
		long m_mem_swap_total;
		long m_mem_swap_free;

		// System Information
		std::string m_os_name;
		std::string m_domain_name;
		long m_uptime;

		// Graphics Information
		std::vector<double> m_gpu_temps;
		std::vector<std::string> m_gpu_vendor_ids;
		std::vector<std::string> m_gpu_card_names;
		std::vector<double> m_gpu_power_draws;
		
		bool m_has_AMD = false;
		bool m_has_NVIDIA = false;
		bool m_already_tested = false;

		// Constant Variables
		const int MAX_GPU_COUNT = 4;
		const int MAX_LINES_COUNT = 2;
		const int MAX_CARD_ROW = 5;

		// TODO
		//std::string cpu_info_path;
		//std::string cpu_temps_path;
		//std::string mem_info_path;
		
};