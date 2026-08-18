#include <iostream>
#include <filesystem>
#include <regex>

struct hardwareInfo//todo
{
    // chip:
    // value:
    // label:
    // chennel:
};

int getSensor(){
    std::cout<<"is gone";
    using namespace std::filesystem;
    directory_iterator monFolder("/sys/class/hwmon/");
    std::regex pattern(R"(temp([0-9]+)_(input|label))");
    //ссылка будет использоваться тк без нее будет происходить постоянная аллокация на каждой итерации
    for (const directory_entry& currentFile : monFolder)
    {
        std::string filename=currentFile.path().filename().string();
        directory_iterator curMonFolder(currentFile.path());
            for (const directory_entry& currentMonFile : curMonFolder)
            {
                std::string filenameMon=currentMonFile.path().filename().string();
                std::smatch match;
                if(std::regex_match(filenameMon,match,pattern))
                    {
                        std::string matched=match[1].str();
                    }
            }
    }
    return 0;
}
