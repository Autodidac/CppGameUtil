#include "FileManager.h"
#include "pch.h"

namespace Utilities {

    bool FileManager::OpenFileDialog(std::wstring& filePath, std::wstring& selectedFile)
    {
        // Initialize COM for the current thread
        HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
        if (FAILED(hr))
            return false;

        // Create the FileOpenDialog object
        IFileOpenDialog* pFileDialog;
        hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileDialog));
        if (FAILED(hr)) {
            CoUninitialize();
            return false;
        }

        // Show the Open File dialog window
        hr = pFileDialog->Show(NULL);
        if (FAILED(hr)) {
            pFileDialog->Release();
            CoUninitialize();
            return false;
        }

        // Get the selected file
        IShellItem* pItem;
        hr = pFileDialog->GetResult(&pItem);
        if (FAILED(hr)) {
            pFileDialog->Release();
            CoUninitialize();
            return false;
        }

        // Get the file path
        PWSTR pszFilePath;
        hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
        if (FAILED(hr)) {
            pItem->Release();
            pFileDialog->Release();
            CoUninitialize();
            return false;
        }

        // Convert WCHAR to std::wstring
        filePath = pszFilePath;

        // Extract the selected file name
        size_t pos = filePath.find_last_of(L"/\\");
        if (pos != std::wstring::npos) {
            selectedFile = filePath.substr(pos + 1);
        }

        // Cleanup
        CoTaskMemFree(pszFilePath);
        pItem->Release();
        pFileDialog->Release();
        CoUninitialize();

        return true;
    }

    bool FileManager::SaveFileDialog(std::wstring& filePath, const std::wstring& defaultFileName)
    {
        // Initialize COM for the current thread
        HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
        if (FAILED(hr))
            return false;

        // Create the FileSaveDialog object
        IFileSaveDialog* pFileSaveDialog;
        hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL, IID_IFileSaveDialog, reinterpret_cast<void**>(&pFileSaveDialog));
        if (FAILED(hr)) {
            CoUninitialize();
            return false;
        }

        // Set default file name
        pFileSaveDialog->SetFileName(defaultFileName.c_str());

        // Show the Save File dialog window
        hr = pFileSaveDialog->Show(NULL);
        if (FAILED(hr)) {
            pFileSaveDialog->Release();
            CoUninitialize();
            return false;
        }

        // Get the selected file
        IShellItem* pItem;
        hr = pFileSaveDialog->GetResult(&pItem);
        if (FAILED(hr)) {
            pFileSaveDialog->Release();
            CoUninitialize();
            return false;
        }

        // Get the file path
        PWSTR pszFilePath;
        hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
        if (FAILED(hr)) {
            pItem->Release();
            pFileSaveDialog->Release();
            CoUninitialize();
            return false;
        }

        // Convert WCHAR to std::wstring
        filePath = pszFilePath;

        // Cleanup
        CoTaskMemFree(pszFilePath);
        pItem->Release();
        pFileSaveDialog->Release();
        CoUninitialize();

        return true;
    }

    bool FileManager::OpenFolderDialog(std::wstring& folderPath)
    {
        // Initialize COM for the current thread
        HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
        if (FAILED(hr))
            return false;

        // Create the FolderPicker object
        IFileOpenDialog* pFolderPicker;
        hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFolderPicker));
        if (FAILED(hr)) {
            CoUninitialize();
            return false;
        }

        // Set options to select folders
        hr = pFolderPicker->SetOptions(FOS_PICKFOLDERS);
        if (FAILED(hr)) {
            pFolderPicker->Release();
            CoUninitialize();
            return false;
        }

        // Show the Folder Picker dialog window
        hr = pFolderPicker->Show(NULL);
        if (FAILED(hr)) {
            pFolderPicker->Release();
            CoUninitialize();
            return false;
        }

        // Get the selected folder
        IShellItem* pItem;
        hr = pFolderPicker->GetResult(&pItem);
        if (FAILED(hr)) {
            pFolderPicker->Release();
            CoUninitialize();
            return false;
        }

        // Get the folder path
        PWSTR pszFolderPath;
        hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFolderPath);
        if (FAILED(hr)) {
            pItem->Release();
            pFolderPicker->Release();
            CoUninitialize();
            return false;
        }

        // Convert WCHAR to std::wstring
        folderPath = pszFolderPath;

        // Cleanup
        CoTaskMemFree(pszFolderPath);
        pItem->Release();
        pFolderPicker->Release();
        CoUninitialize();

        return true;
    }
}
