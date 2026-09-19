#include "Headers/Filesystem.h"
#include <iostream>
#include <filesystem>
#include <iomanip>
#include <string>
#include <vector>

namespace fs = std::filesystem;
void CheckFolders() {
	fs::directory_entry Directory1{"C:/Users/OEM/OneDrive - UP Education/Desktop/Projects/105 Aseessment/Headers"};
	if (!Directory1.exists()) {
		std::cout << "+" << std::string(60, '=') << "+" << "\n";
		std::cout << "Cannot find Folder\n";
		std::cout << "+" << std::string(60, '=') << "+" << "\n";
		create_directory(Directory1);
		return;
	}
	if (Directory1.exists()) {
		std::cout << "+" << std::string(60, '=') << "+" << "\n";
		std::cout << "Header Folder" << Directory1 << "\n";
		std::cout << "+" << std::string(60, '=') << "+" << "\n";
	}


	fs::directory_entry Directory2{"C:/Users/OEM/OneDrive - UP Education/Desktop/Projects/105 Aseessment/Data"};
	if (!Directory2.exists()) {
		std::cout << "+" << std::string(60, '=') << "+" << "\n";
		std::cout << "Cannot Find Folder\n";
		std::cout << "+" << std::string(60, '=') << "+" << "\n";
		create_directory(Directory2);
		return;
	}
	if (Directory2.exists()) {
		std::cout << "+" << std::string(60, '=') << "+" << "\n";
		std::cout << "Data Folder" << Directory2 << "\n";
		std::cout << "+" << std::string(60, '=') << "+" << "\n";
	}
}

void CheckFileSize() {

}

void CheckFiles() {

}

void DeleteFiles() {
	std::cout << "+" << std::string(60, '=') << "+" << "\n";
	std::cout << "Welcome To Delete Files\n";
	std::cout << "+" << std::string(60, '=') << "+" << "\n";

}

void ViewFiles() {
	std::cout << "+" << std::string(60, '=') << "+" << "\n";
	std::cout << "Welcome to View Files\n";
	std::cout << "+" << std::string(60, '=') << "+" << "\n";

	fs::path base = "C:/Users/OEM/OneDrive - UP Education/Desktop/Projects/105 Aseessment";

	std::pair<std::string, fs::path> dirs[2] = {
		{ "Header Files", base / "Headers" },
		{ "Data Files",   base / "Data"    },
	};

	for (const auto& [label, dir] : dirs) {
		std::cout << "+" << std::string(60, '-') << "+" << "\n";
		std::cout << "[" << label << "]\n";

		std::error_code ec;
		if (!fs::exists(dir, ec) || ec) {
			std::cout << "  Directory not found: " << dir.string() << "\n";
			continue;
		}

		int count = 0;
		for (auto it = fs::directory_iterator(dir, ec); !ec && it != fs::directory_iterator(); it.increment(ec)) {
			std::cout << "  " << it->path().filename().string() << "\n";
			++count;
		}
		if (ec)    std::cout << "  Read error: " << ec.message() << "\n";
		if (!count && !ec) std::cout << "  (empty)\n";
	}

	std::cout << "+" << std::string(60, '=') << "+" << "\n";
}