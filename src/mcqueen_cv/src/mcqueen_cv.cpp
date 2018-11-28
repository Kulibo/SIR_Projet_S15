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

std::vector<rgb> Mcqueen_CV::update()
{
	//TODO convergence ?
	for(unsigned int row(0); row < _binary_mask.rows ; row++)
	    for(unsigned int col(0); col < _binary_mask.cols; col++)
		    _learner.update(_selector.get_pixel(row, col));

	return _learners.prototypes();
}

std::vector<rgb> Mcqueen_CV::reinit_prototypes()
{
	//TODO
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
	for(unsigned int row(0); row < _binary_mask.rows ; row++)
	{
	    for(unsigned int col(0); col < _binary_mask.cols; col++)
	    {
		size_t closest_rank = find_closest_rank(_selector.get_pixel(row, col));
	        _binary_mask.at(row, col) = (closest_rank == _sel_prot) ? 255 : 0;
	    }
	}
    }
}
	

