#include "mcqueen_cv.hpp"

#include <stdexcept>
#include <random>
namespace mq{
    Color_selector::Color_selector(std::string img_filename)
    : _img_mat(cv::imread(img_filename))
    {}

    Color_selector::Color_selector(cv::Mat img)
    : _img_mat(img)
    {
        if(_img_mat.channels()!=3)
            throw std::logic_error("Wrong channels number, expected 3, got " + std::to_string(_img_mat.channels()));
    }

    //std::vector<rgb> Color_selector::get_colors

    rgb Color_selector::get_random_pixel(){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist_col(0, _img_mat.cols);
        std::uniform_int_distribution<> dist_row(0, _img_mat.rows)
        rgb pix;

        int row_index(dist_row(gen));
        int col_index(dist_col(gen));

        pix[0]= _img_mat.data[row_index*_img_mat.rows*_img_mat.channels() + col_index*_img_mat.cols*_img_mat.channels() + 2];
        pix[1]= _img_mat.data[row_index*_img_mat.rows*_img_mat.channels() + col_index*_img_mat.cols*_img_mat.channels() + 1];
        pix[2]= _img_mat.data[row_index*_img_mat.rows*_img_mat.channels() + col_index*_img_mat.cols*_img_mat.channels() + 0];
        return pix;
    }
}