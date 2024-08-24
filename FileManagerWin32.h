#pragma once

#include <Windows.h>
#include <string>
#include <Shobjidl.h>  // Include Windows Shell API for IFileOpenDialog and IFileSaveDialog

namespace Utilities {

    class FileManager
    {
    public:
        bool OpenFileDialog(std::wstring& filePath, std::wstring& selectedFile);
        bool SaveFileDialog(std::wstring& filePath, const std::wstring& defaultFileName);
        bool OpenFolderDialog(std::wstring& folderPath);

    private:
        std::wstring sFilePath; // Use wstring to handle wide characters
    };
}
