#ifndef MCQUEEN_LIBRARY_HPP
#define MCQUEEN_LIBRARY_HPP
#include <vector>

namespace mq {
    template <typename T>
        class Mcqueen{
            public:
                using vectors = std::vector<T>;
            public:
                Mcqueen(size_t nPrototypes);
                vectors update(T sample);

            private:
                size_t find(T sample) const;

            private:
                vectors _prototypes;
        };
}



#endif
