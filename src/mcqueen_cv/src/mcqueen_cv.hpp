#pragma once

#include <mcqueen>
#include <vector>
#include <opencv2/core/core.hpp>

namespace mq{
    using rgb = std::array<unsigned char, 3>;
    
    class Color_selector{
        public:
            Color_selector(cv::Mat img);
            Color_selector(std::string img_filename);
            //std::vector<rgb> get_colors(cv::Mat img);
            rgb get_random_pixel();
        private:
        private:
            cv::Mat _img_mat;

    };

    class Mcqueen_CV{
        public:
            Mcqueen_CV(cv::Mat img, std::vector<rgb> prototypes);
            Mcqueen_CV(std::string img_filename, std::vector<rgb> prototypes);
            Mcqueen_CV(cv::Mat img, size_t nPrototypes = 10);
            Mcqueen_CV(std::string img_filename, size_t nPrototypes = 10);
            std::vector<rgb> update();
            std::vector<rgb> reinit_prototypes();
        public:
	    void select_prototype(size_t proto_index);
        private:
            std::unique_ptr<Color_selector> _selector;
            Mcqueen _learner;
            size_t _sel_prot;
    };
}
