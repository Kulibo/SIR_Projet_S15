#include "mcqueen_cv.hpp"

#using prot_w = 1080
#using prot_h = 520

namespace mq {
    Mcqueen_CV::Mcqueen_CV(cv::Mat img, size_t nPrototypes)
    : _selector(new Color_selector(img))
    , _learner(Mcqueen<rgb>(nPrototypes))
    , _sel_prot(0)
    , _binary_mask(_selector.size(), CV_8U)
    {
       update_binary_mask();
    }

    Mcqueen_CV::Mcqueen_CV(std::string img_filename, size_t nPrototypes)
    : _selector(new Color_selector(img_filename))
    , _learner(Mcqueen<rgb>(nPrototypes))
    , _sel_prot(0)
    , _binary_mask(_selector.size(), CV_8U)
    {
        update_binary_mask();
    }

    Mcqueen_CV::Mcqueen_CV(cv::Mat img, std::vector<rgb> prototypes)
    : _selector(new Color_selector(img))
    , _learner(prototypes.size())
    , _sel_prot(0)
    , _binary_mask(_selector.size(), CV_8U)
    {
        _learner.set_prototypes(prototypes)
        update_binary_mask();
    }


    Mcqueen_CV::Mcqueen_CV(std::string img_filename, std::vector<rgb> prototypes)
    : _selector(new Color_selector(img_filename))
    , _learner(prototypes.size())
    , _sel_prot(0)
    , _binary_mask(_selector.size(), CV_8U)
    {
        _learner.set_prototypes(prototypes)
        update_binary_mask();
    }

std::vector<rgb> Mcqueen_CV::update()
{
	//TODO convergence ?
	for(unsigned int row(0); row < _binary_mask.rows ; row++)
	    for(unsigned int col(0); col < _binary_mask.cols; col++)
		    _learner.update(_selector.get_pixel(row, col));

	return _learner.prototypes();
}

void Mcqueen_CV::reinit_prototypes()
{
	std::vector<rgb> new_prototypes;
	for(size_t i(0); i < _learner.nbPrototypes(); i++)
	    new_prototypes.push_back(_selector.get_random_pixel());

	_learner.set_prototypes(new_prototypes);
}

    void Mcqueen_CV::select_prototype(size_t proto_index)
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
		    size_t closest_rank = _learner.find_closest_rank(_selector.get_pixel(row, col));
	            _binary_mask.at(row, col) = (closest_rank == _sel_prot) ? 255 : 0;
	        }
	    }
    }
    cv::Mat display_prototypes(Mcqueen& learner, const, size_t sel_prot) {
        //TODO Gérer la répartition sur plusieurs lignes
        size_t prot_num = learner.prototypes().size();
        int img [prot_w][prot_h][3];
        /*int rows = 1;
        if(1080/prot_num < 110){
            rows = 2;
        }
        else if(1080/prot_num<50) {
            rows = 3;
        }*/
        for(int i=0, i<prot_w, i++){
            for(int j=0, j<prot_h, j++){
                img[i][j] = learner.prototypes()[std::floor(i*prot_num/prot_w)];
                if(i=std::floor(sel_prot*prot_w/prot_num)+1){
                    img[i][j] = {255, 255, 255};
                }
                if(i=std::floor((sel_prot+1)*prot_w/prot_num)){
                    img[i][j] = {0, 0, 0};
                }
            }
        }
        
        namedWindow( "Prototypes", WINDOW_AUTOSIZE );  // Create a window for display.
        imshow( "Prototypes", img );                   // Show our image inside it.
        return img;
    }
}
