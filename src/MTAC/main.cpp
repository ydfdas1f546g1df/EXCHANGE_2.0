#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;

void moveNewFiles(const fs::path& sourcePath, const fs::path& destinationPath) {
    std::cout << "Überwache Verzeichnis: " << sourcePath << std::endl;

    while (true) {
        for (const auto& entry : fs::directory_iterator(sourcePath)) {
            // Überprüfen, ob es sich um ein reguläres File handelt
            if (fs::is_regular_file(entry)) {
                // Dynamischen Teil des Dateinamens extrahieren (username)
                std::string username = entry.path().stem().string();

                // Ziel-Pfad erstellen (Zielverzeichnis + Dateiname)
                fs::path destinationFile = destinationPath / username / entry.path().filename();

                // Datei verschieben
                fs::rename(entry.path(), destinationFile);

                std::cout << "Datei erfolgreich verschoben von "
                          << entry.path() << " nach " << destinationFile << std::endl;
            }
        }

        // Eine Pause von 1 Minute (kann nach Bedarf angepasst werden)
        std::this_thread::sleep_for(std::chrono::minutes(1));
    }
}

int main() {
    // Dynamisch gescannter Quellpfad
    fs::path sourcePath = "/var/{domain}/mailboxes/";

    // Pfad zum Zielverzeichnis
    fs::path destinationPath = "/pfad/zum/zielverzeichnis/";

    // Ziel-Pfad erstellen (Zielverzeichnis + Dateiname)
    moveNewFiles(sourcePath, destinationPath);

    return 0;
}
