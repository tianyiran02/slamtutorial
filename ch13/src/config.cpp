#include "myslam/config.h"

namespace myslam {
bool Config::SetParameterFile(const std::string &filename) {
    if (config_ == nullptr)
        config_ = std::shared_ptr<Config>(new Config);
    auto filechk = cv::FileStorage(filename.c_str(), cv::FileStorage::READ);
    if (filechk == nullptr)
    {
        LOG(ERROR) << "failed to create OpenCV file storage from parameter file.";
        return false;
    }
    config_->file_ = filechk;
    if 
    if (config_->file_.isOpened() == false) {
        LOG(ERROR) << "parameter file " << filename << " does not exist.";
        config_->file_.release();
        return false;
    }
    return true;
}

Config::~Config() {
    if (file_.isOpened())
        file_.release();
}

std::shared_ptr<Config> Config::config_ = nullptr;

}
