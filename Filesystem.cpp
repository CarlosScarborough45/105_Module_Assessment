#include "Headers/Filesystem.h"
#include <iostream>
#include <filesystem>
#include <iomanip>
#include <limits>
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
	std::cout << "+" << std::string(60, '=') << "+" << "\n";
	std::cout << "Check File Size\n";
	std::cout << "+" << std::string(60, '=') << "+" << "\n";

	std::string file;
	std::cout << "Enter the File name: ";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, file);
	std::cout << "+" << std::string(60, '=') << "+" << "\n";

	fs::path base = "C:/Users/OEM/OneDrive - UP Education/Desktop/Projects/105 Aseessment";

	std::pair<std::string, fs::path> dirs[2] = {
		{"Header Files", base / "Headers"},
		{"Data Files", base / "Data"},
	};

	std::cout << std::left << std::setw(30) << "File Name" << "| " << std::setw(20) << "Size (bytes)" << "\n";
	std::cout << "+" << std::string(60, '-') << "+" << "\n";

	bool found = false;
	for (const auto& [label, dir] : dirs) {
		std::error_code ec;
		if (!fs::exists(dir, ec) || ec) continue;

		for (auto it = fs::directory_iterator(dir, ec); !ec && it != fs::directory_iterator(); it.increment(ec)) {
			if (it->path().filename().string() == file) {
				uintmax_t size = fs::file_size(it->path(), ec);
				if (!ec) {
					std::cout << std::left << std::setw(30) << file << "| " << std::setw(20) << size << "\n";
					found = true;
				}
			}
		}
	}

	if (!found) {
		std::cout << "File \"" << file << "\" not found in Headers or Data folders.\n";
	}
	std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void CheckFiles() {
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Data Files\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    fs::path dataDir = "C:/Users/OEM/OneDrive - UP Education/Desktop/Projects/105 Aseessment/Data";

    std::error_code ec;
    if (!fs::exists(dataDir, ec) || ec){
        std::cout << "Data folder not found\n";
        return;
    }

    std::cout << std::left << std::setw(30) << "File" << "| " << std::setw(15) << "Size (bytes)" << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";
    for (auto it = fs::directory_iterator(dataDir, ec); !ec && it != fs::directory_iterator(); it.increment(ec)){
        uintmax_t size = fs::file_size(it->path(), ec);
        std::cout << std::left << std::setw(30) << it->path().filename().string()
                  << "| " << (!ec ? std::to_string(size) : "?") << "\n";
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void DeleteFiles() {
	std::cout << "+" << std::string(60, '=') << "+" << "\n";
	std::cout << "Welcome To Delete Files\n";
	std::cout << "+" << std::string(60, '=') << "+" << "\n";

	std::string file;
	std::cout << "Enter File Name\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, file);

	fs::path base = "C:/Users/OEM/OneDrive - UP Education/Desktop/Projects/105 Aseessment";

	std::pair<std::string, fs::path> dirs[2] = {
		{"Header Files", base / "Headers"},
		{"Data Files", base / "Data"},
	};

	bool deleted = false;
	for (const auto& [label, dir] : dirs) {
		std::cout << "+" << std::string(60, '-') << "+" << "\n";
		std::cout << "[" << label << "]\n";

		std::error_code ec;
		if (!fs::exists(dir, ec) || ec) {
			std::cout << "Directory not found: " << dir.string() << "\n";
			continue;
		}

		fs::path target = dir / file;
		if (fs::exists(target, ec) && !ec) {
			fs::remove(target, ec);
			if (!ec) {
				std::cout << "File deleted: " << file << "\n";
				deleted = true;
			} else {
				std::cout << "Failed to delete: " << file << "\n";
			}
			break;
		}
	}

	if (!deleted) {
		std::cout << "File \"" << file << "\" not found in Headers or Data folders.\n";
	}
	std::cout << "+" << std::string(60, '-') << "+" << "\n";
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