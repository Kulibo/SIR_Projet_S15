#ifndef MCQUEEN_LIBRARY_HPP
#define MCQUEEN_LIBRARY_HPP
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>

#include "iterable_trait.hpp"

namespace mq {
    template <typename T>
        class Mcqueen{
            public:
                using vectors = std::vector<T>;
            public:
                Mcqueen(size_t nPrototypes, std::function<double(T)> distance = Default_distance<std::vector<T>>(), double step = 0.5);
                vectors update(T sample);
                vectors prototypes() const;
                vectors set_prototypes(std::vector<T> prototypes);
                typename std::vector<T>::iterator find_closest_prototype(T sample);

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
    typename std::vector<T>::iterator Mcqueen<T>::find_closest_prototype(T sample) {
        return std::min_element(_prototypes.begin(), _prototypes.end(), [this, sample](T a, T b){return _distance(a-sample)<=_distance(b-sample);}); 
    }

    template<typename T>
    std::vector<T> Mcqueen<T>::update(T sample){
        auto prototype = find_closest_prototype(sample);
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
