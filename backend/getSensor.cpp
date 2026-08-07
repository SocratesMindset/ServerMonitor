#include <iostream>
#include <filesystem>

int getSensor(){
    std::cout<<"is gone";
    using namespace std::filesystem;
    directory_iterator monFolder("/sys/class/hwmon/");
    //ссылка будет использоваться тк без нее будет происходить постоянная аллокация на каждой итерации
    for (const directory_entry& currentFile : monFolder)
    {
        std::string filename=currentFile.path().filename().string();
        directory_iterator curMonFolder("/sys/class/hwmon/"+filename+"/");//полный бред, сюда проще передать currentFile.path()
            for (const directory_entry& currentMonFile : curMonFolder)
            {

            }
    }
}
