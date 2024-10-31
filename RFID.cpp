#include <iostream>
#include <logicalaccess/logicalaccess.h>

int main() {
    try {
        // Initialize the library
        LogicalAccess::Initialize();

        // Create a reader instance
        LogicalAccess::Reader reader("PCSC", "ACS ACR122 0");

        // Connect to the reader
        reader.connect();

        // Get the tag information
        LogicalAccess::Tag tag = reader.getTag(LogicalAccess::Tag::getDefaultTargetList());

        // Read the tag's UID
        std::string uid = tag.getUID();

        // Print the UID
        std::cout << "Tag UID: " << uid << std::endl;

        // Disconnect from the reader
        reader.disconnect();
    } catch (LogicalAccess::ReaderException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Release the library resources
    LogicalAccess::Release();

    return 0;
}