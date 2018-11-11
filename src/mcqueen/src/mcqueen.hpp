#ifndef MCQUEEN_LIBRARY_HPP
#define MCQUEEN_LIBRARY_HPP
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>

template <typename Container>
struct Default_distance
{
	typedef typename Container::value_type data_type;
	static std::function<double(Container)> fun()
	{
	    // Lambda fonction qui pour a un vector, renvoie la somme des carrés 
	    return [] (Container a)
	    {
	        return std::accumulate(a.begin(), a.end(), 0.0, [] (double accu, data_type element) {return accu + static_cast<double>(element*element);});	    
	    };
	}
};


namespace mq {
    template <typename T>
        class Mcqueen{
            public:
                using vectors = std::vector<T>;
            public:
                Mcqueen(size_t nPrototypes, std::function<double(T)> distance = Default_distance<std::vector<T>>::fun(), double step = 0.5);
                vectors update(T sample);
                vectors prototypes() const;
                vectors set_prototypes();
            private:
                typename std::vector<T>::iterator find(T sample);

            private:
                vectors _prototypes;
                std::function<double(T)> _distance;
                double _step;
        };
}


namespace mq{
    template<typename T>
    Mcqueen<T>::Mcqueen(size_t nPrototypes, std::function<double(T)> distance, double step )
    : _prototypes(nPrototypes)
    , _distance(distance)
    , _step(step)
    {
        
    }
    template<typename T>
    typename std::vector<T>::iterator Mcqueen<T>::find(T sample) {
        return std::min_element(_prototypes.begin(), _prototypes.end(), [this, sample](T a, T b){return _distance(a-sample)<=_distance(b-sample);}); 
    }

    template<typename T>
    std::vector<T> Mcqueen<T>::update(T sample){
        auto prototype = find(sample);
        *prototype += _step*(sample - *prototype);
        return _prototypes;
    }

    template<typename T>
    std::vector<T> Mcqueen<T>::prototypes() const{
        return _prototypes;
    }
    template<typename T>
    std::vector<T> Mcqueen<T>::set_prototypes(std::vector<T> prototypes){
        _prototypes = prototypes;
        return _prototypes;
    }

}

#endif
