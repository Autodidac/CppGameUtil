#include "SourceCodeAggregator.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>
#include "pch.h"

namespace Utilities {

    namespace fs = std::filesystem;

    std::wstring GetExecutablePath() {
        wchar_t buffer[MAX_PATH];
        GetModuleFileName(NULL, buffer, MAX_PATH);
        std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
        return std::wstring(buffer).substr(0, pos);
    }

    void AggregateDirectoryFiles(const std::wstring& dirPath, std::wofstream& outputFile) {
        for (const auto& entry : fs::directory_iterator(dirPath)) {
            if (entry.is_regular_file()) {
                std::wstring filePath = entry.path().wstring();
                std::wstring extension = entry.path().extension().wstring();
                if (extension == L".cpp" || extension == L".h") {
                    std::wifstream inputFile(filePath);
                    if (inputFile.is_open()) {
                        std::wstringstream buffer;
                        buffer << inputFile.rdbuf();
                        std::wstring fileContents = buffer.str();
                        outputFile << L"/* Start of file: " << entry.path().filename().wstring() << L" */\n";
                        outputFile << fileContents << L"\n";
                        outputFile << L"/* End of file: " << entry.path().filename().wstring() << L" */\n";
                        inputFile.close();
                    }
                    else {
                        std::wcerr << L"Failed to open input file: " << filePath << std::endl;
                    }
                }
            }
        }
    }

    void SourceCodeAggregator::aggregateFiles(const std::vector<std::wstring>& directories, const std::wstring& outputFilePath) {
        std::wofstream outputFile(outputFilePath);
        if (!outputFile.is_open()) {
            std::wcerr << L"Failed to open output file: " << outputFilePath << std::endl;
            return;
        }

        // Combine files from the "lib" directory
        std::wstring libPath = GetExecutablePath() + L"\\lib";
        AggregateDirectoryFiles(libPath, outputFile);

        // Combine files from each specified directory
        for (const auto& dirPath : directories) {
            AggregateDirectoryFiles(dirPath, outputFile);
        }

        outputFile.close();
    }
}
