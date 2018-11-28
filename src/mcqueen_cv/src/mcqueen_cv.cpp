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

    void Mcqueen_CV::select_prototypes(size_t proto_index)
    {
	// Vérifie que l'on demande un index correct
	if(proto_index >= _learner.prototypes().size())
		throw std::logic_error("Not enough prototypes");

	// Met le prototype à jour
	_sel_prot = proto_index;

	// On a modifié le prototype considéré, met à jour le masque
	update_binary_mask();
    }

    cv::Mat Mcqueen_CV::binay_mask() const
    {
        return _binary_mask;
    }

    void Mcqueen_CV::update_binary_mask()
    {
	// Met à jour le masque
    }


}
	

