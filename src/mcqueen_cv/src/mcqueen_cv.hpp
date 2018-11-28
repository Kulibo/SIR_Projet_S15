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
	    rgb get_pixel(int row, int col) const;

	    cv::Size img_size() const; 

	    
        private:
            cv::Mat _img_mat;

    };

    class Mcqueen_CV{
        public:
	    // Constructeurs
            Mcqueen_CV(cv::Mat img, std::vector<rgb> prototypes);
            Mcqueen_CV(std::string img_filename, std::vector<rgb> prototypes);
            Mcqueen_CV(cv::Mat img, size_t nPrototypes = 10);
            Mcqueen_CV(std::string img_filename, size_t nPrototypes = 10);
	    // Calcul des clusters dans _learner
            std::vector<rgb> update();
	    // Réinitialisation aléatoire des prototypes
            std::vector<rgb> reinit_prototypes();
        public:
	    // Choisit un prototype par son index
	    void select_prototype(size_t proto_index);
	    // Renvoie le masque binaire correspondant au prototype considéré
	    cv::Mat binary_mask() const;

	private:
	    // Calcule le masque binaire correspondant au prototype considéré
	    void update_binary_mask();

        private:
            std::unique_ptr<Color_selector> _selector;
            Mcqueen _learner;
            size_t _sel_prot;
	    cv::Mat _binary_mask;
    };
}
