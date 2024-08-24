// Utilities_Example.cpp
#include "MathUtils.h"
#include "RandomUtils.h"
#include "StringUtils.h"
#include "TimeUtils.h"
#include "SourceCodeAggregator.h"
#include "FileManager.h"

#include <iostream>
#include <thread>

int main() {
    // MathUtils Example
    std::cout << "MathUtils Example:\n";
    std::cout << "Add: " << Utilities::MathUtils::add(5, 3) << "\n";
    std::cout << "Subtract: " << Utilities::MathUtils::subtract(5, 3) << "\n";
    std::cout << "Multiply: " << Utilities::MathUtils::multiply(5, 3) << "\n";
    std::cout << "Divide: " << Utilities::MathUtils::divide(5, 3) << "\n";
    std::cout << "Degrees to Radians (90): " << Utilities::MathUtils::degreesToRadians(90) << "\n";
    std::cout << "Radians to Degrees (PI/2): " << Utilities::MathUtils::radiansToDegrees(3.14159265358979323846 / 2) << "\n";
    std::cout << "Clamp (10, 0, 5): " << Utilities::MathUtils::clamp(10, 0, 5) << "\n";
    std::cout << "Lerp (0, 10, 0.5): " << Utilities::MathUtils::lerp(0, 10, 0.5) << "\n";

    // RandomUtils Example
    Utilities::RandomUtils randomUtils; // Create an instance of RandomUtils
    std::cout << "\nRandomUtils Example:\n";
    std::cout << "Random Int (1, 10): " << randomUtils.getRandomInt(1, 10) << "\n";
    std::cout << "Random Double (0.0, 1.0): " << randomUtils.getRandomDouble(0.0, 1.0) << "\n";

    // StringUtils Example
    std::cout << "\nStringUtils Example:\n";
    std::string testStr = "Hello, World!";
    std::cout << "To Upper Case: " << Utilities::StringUtils::toUpperCase(testStr) << "\n";
    std::cout << "To Lower Case: " << Utilities::StringUtils::toLowerCase(testStr) << "\n";
    std::cout << "Starts with 'Hello': " << (Utilities::StringUtils::startsWith(testStr, "Hello") ? "True" : "False") << "\n";
    std::cout << "Ends with 'World!': " << (Utilities::StringUtils::endsWith(testStr, "World!") ? "True" : "False") << "\n";
    std::cout << "Split by ',': ";
    auto tokens = Utilities::StringUtils::split(testStr, ',');
    for (const auto& token : tokens) {
        std::cout << "[" << token << "] ";
    }
    std::cout << "\n";

    // TimeUtils Example
    std::cout << "\nTimeUtils Example:\n";

    // Timer Example
    Utilities::Timer timer;
    std::cout << "Starting Timer...\n";
    timer.start();
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate some work
    timer.stop();
    std::cout << "Elapsed Time (seconds): " << timer.elapsedSeconds() << "\n";

    // Demonstrate Reversal
    std::cout << "Reversing Time...\n";
    timer.reverse();
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate some work
    timer.update();
    std::cout << "Elapsed Time After Reversal (seconds): " << timer.elapsedSeconds() << "\n";

    // Reset Timer
    std::cout << "Resetting Timer...\n";
    timer.reset();
    std::cout << "Elapsed Time After Reset (seconds): " << timer.elapsedSeconds() << "\n";

    // DateTime Example
    std::cout << "Current Date: " << Utilities::DateTime::getCurrentDate() << "\n";
    std::cout << "Current American Date: " << Utilities::DateTime::getCurrentDateUS() << "\n";
    std::cout << "Current Time: " << Utilities::DateTime::getCurrentTime() << "\n";
    std::cout << "Current DateTime: " << Utilities::DateTime::getCurrentDateTime() << "\n";
    std::cout << "Current American DateTime: " << Utilities::DateTime::getCurrentDateTimeUS() << "\n";

    // FileManagerWin32 Example
    std::cout << "\nFileManagerWin32 Example:\n";
    Utilities::FileManager fileManager;
    std::wstring filePath, selectedFile;
    if (fileManager.OpenFileDialog(filePath, selectedFile)) {
        std::wcout << L"Selected file: " << filePath << L"\n";
        std::wcout << L"File name: " << selectedFile << L"\n";
    }
    else {
        std::wcout << L"Failed to open file dialog.\n";
    }

    if (fileManager.SaveFileDialog(filePath, L"example.txt")) {
        std::wcout << L"Save file path: " << filePath << L"\n";
    }
    else {
        std::wcout << L"Failed to open save file dialog.\n";
    }

    std::wstring folderPath;
    if (fileManager.OpenFolderDialog(folderPath)) {
        std::wcout << L"Selected folder: " << folderPath << L"\n";
    }
    else {
        std::wcout << L"Failed to open folder dialog.\n";
    }

    // FileAggregator Example
    std::cout << "\nFileAggregator Example:\n";
    std::wstring outputPath = L"combined_output.txt";
    std::vector<std::wstring> directories = { L"D:\\repos\\Utilities\\src", L"D:\\repos\\Utilities\\include" }; // Replace with actual directories
    Utilities::SourceCodeAggregator::aggregateFiles(directories, outputPath);
    std::wcout << L"Combined files into: " << outputPath << L"\n";

    // Time Reversal Example
    std::cout << "\nTime Reversal Example:\n";
    Utilities::Timer reverseTimer;
    reverseTimer.start();
    std::this_thread::sleep_for(std::chrono::seconds(10)); // Simulate some work
    reverseTimer.stop();
    std::cout << "Advanced Time (seconds): " << reverseTimer.elapsedSeconds() << "\n";

    // Reversing time
    reverseTimer.reverse();
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Simulate some work
    reverseTimer.update();
    std::cout << "Reversed Time (seconds): " << reverseTimer.elapsedSeconds() << "\n";

    return 0;
}
