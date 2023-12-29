#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;

void moveNewFiles(const fs::path& sourcePath, const fs::path& destinationPath) {
    std::cout << "Überwache Verzeichnis: " << sourcePath << std::endl;

    while (true) {
        for (const auto& entry : fs::directory_iterator(sourcePath)) {
            if (fs::is_regular_file(entry)) {
                std::string username = entry.path().stem().string();

                fs::path destinationFile = destinationPath / username / entry.path().filename();

                fs::rename(entry.path(), destinationFile);

                std::cout << "Datei erfolgreich verschoben von "
                          << entry.path() << " nach " << destinationFile << std::endl;
            }
        }

        std::this_thread::sleep_for(std::chrono::minutes(1));
    }
}

int main() {
    fs::path sourcePath = "/var/{domain}/mailboxes/";

    fs::path destinationPath = "/pfad/zum/zielverzeichnis/";

    moveNewFiles(sourcePath, destinationPath);

    return 0;
}
