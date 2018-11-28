#include "mcqueen_cv.hpp"

namespace mq {
    Mcqueen_CV::Mcqueen_CV(cv::Mat img, size_t nPrototypes)
    : _selector(new Color_selector(img))
    , _learner(Mcqueen<rgb>(nPrototypes))
    , _sel_prot(0)
    , _binary_mask(_selector.size(), CV_8U)
   {update_binary_mask();
}

    Mcqueen_CV::Mcqueen_CV(std::string img_filename, size_t nPrototypes)
    : _selector(new Color_selector(img_filename))
    , _learner(Mcqueen<rgb>(nPrototypes))
    , _sel_prot(0)
    , _binary_mask(_selector.size(), CV_8U)
    {update_binary_mask();
}

    Mcqueen_CV::Mcqueen_CV(cv::Mat img, std::vector<rgb> prototypes)
    : _selector(new Color_selector(img))
    //FIXME
    , _learner(Mcqueen<rgb>(prototypes.length()).set_prototypes(prototypes))
    , _sel_prot(0)
    , _binary_mask(_selector.size(), CV_8U)
    {update_binary_mask();
}
    
    
    Mcqueen_CV::Mcqueen_CV(std::string img_filename, std::vector<rgb> prototypes)
    : _selector(new Color_selector(img_filename))
    //FIXME
    , _learner(Mcqueen<rgb>(prototypes.length()).set_prototypes(prototypes))
    , _sel_prot(0)
    , _binary_mask(_selector.size(), CV_8U)
   {update_binary_mask();
}

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
    
    cv::Mat display_prototypes(Mcqueen& learner const, size_t sel_prot) {
        //TODO Gérer la répartition sur plusieurs lignes
        size_t prot_num = learner.prototypes().size();
        int img [1080][520][3];
        /*int rows = 1;
        if(1080/prot_num < 110){
            rows = 2;
        }
        else if(1080/prot_num<50) {
            rows = 3;
        }*/
        for(int i=0, i<1080, i++){
            for(int j=0, j<1080, j++){
                img[i][j] = learner.prototypes()[std::floor(i/prot_num)]
            }
        }   
    }

}
	

