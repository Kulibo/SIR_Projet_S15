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

        return get_pixel(row_index, col_index);
    }

    rgb Color_selector::get_pixel(int row_index, int col_index) const
    {
	auto bgrpix = _img_mat.at<cv::Vec3b>(col_index, row_index);
	rgb pix(bgrpix[2], bgrpix[1], bgrpix[0]);

	return pix;
    }

    cv::Size Color_selector::img_size() const
    {
	return _img_mat.size();
    }
}
