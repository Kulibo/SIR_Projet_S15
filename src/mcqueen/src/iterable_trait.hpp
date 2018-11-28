namespace custom_trait
{
    // To allow ADL with custom begin/end
    using std::begin;
    using std::end;
    
    template <typename T>
    auto is_iterable_impl(int)
    -> decltype (
       begin(std::declval<T&>()) != end(std::declval<T&>()), // begin/end and operator !=
       void(), // Handle evil operator ,
       ++std::declval<decltype(begin(std::declval<T&>()))&>(), // operator ++
       void(*begin(std::declval<T&>())), // operator*
        std::true_type{});
    
    template <typename T>
    std::false_type is_iterable_impl(...);
    
}
    
template <typename T>
using is_iterable = decltype(custom_trait::is_iterable_impl<T>(0));

template <typename T, typename std::enable_if_t<std::is_integral<T>::value, T>* = nullptr>
std::function <double(T)> Default_distance()
{
	return [] (T a) {return static_cast<double>(abs(a));};
}

template <typename T, typename std::enable_if_t<std::is_floating_point<T>::value, T>* = nullptr>
std::function <double(T)> Default_distance()
{
	return [] (T a) {return fabs(a);};
}

template <typename T, typename std::enable_if_t<is_iterable<T>::value, T>* = nullptr>
std::function <double(T)> Default_distance()
{
	return [] (T a) {
		return std::accumulate(a.begin(), a.end(), 0.0, [] (double accu, typename T::value_type element) 
							 	{return accu + Default_distance<typename T::value_type>()(element);});
	};
}
