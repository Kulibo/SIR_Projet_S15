#include "mcqueen_cv.hpp"

namespace mq {
    Mcqueen_CV::Mcqueen_CV(cv::Mat img, size_t nPrototypes)
    : _selector(new Color_selector(img))
    , _learner(Mcqueen<rgb>(nPrototypes))
    , _sel_prot(0)
    {}

    Mcqueen_CV::Mcqueen_CV(std::string img_filename, size_t nPrototypes)
    : _selector(new Color_selector(img_filename))
    , _learner(Mcqueen<rgb>(nPrototypes))
    , _sel_prot(0)
    {}

    Mcqueen_CV::Mcqueen_CV(cv::Mat img, std::vector<rgb> prototypes)
    : _selector(new Color_selector(img))
    , _learner(Mcqueen<rgb>(prototypes.length()).set_prototypes(prototypes))
    , _sel_prot(0)
    {}
    
    
    Mcqueen_CV::Mcqueen_CV(std::string img_filename, std::vector<rgb> prototypes)
    : _selector(new Color_selector(img_filename))
    , _learner(Mcqueen<rgb>(prototypes.length()).set_prototypes(prototypes))
    , _sel_prot(0)
    {}
}
	

