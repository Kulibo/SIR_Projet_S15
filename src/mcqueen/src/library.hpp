#ifndef MCQUEEN_LIBRARY_HPP
#define MCQUEEN_LIBRARY_HPP
#include <vector>
#include <algorithm>
#include <functional>

namespace mq {
    template <typename T>
        class Mcqueen{
            public:
                using vectors = std::vector<T>;
            public:
                Mcqueen(size_t nPrototypes, std::function<double(T)> distance, double step = 0.5);
                vectors update(T sample);

            private:
                typename std::vector<T>::iterator find(T sample) const;

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
    typename std::vector<T>::iterator Mcqueen<T>::find(T sample) const{
        return std::min_element(_prototypes.begin(), _prototypes.end(), [this, sample](T a, T b){return _distance(a-sample)<=_distance(b-sample);}); 
    }

    template<typename T>
    std::vector<T> Mcqueen<T>::update(T sample){
        auto prototype = find(sample);
        *prototype += _step*(sample - *prototype);
        return _prototypes;
    }

    

}

#endif
