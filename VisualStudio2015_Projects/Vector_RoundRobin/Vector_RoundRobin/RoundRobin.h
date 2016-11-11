#pragma once

/*

	Simple RoundRobin class

*/

#include <vector>

template <typename T>
class RoundRobin
{
public:
	RoundRobin(int cnt_proc = 0);
	virtual ~RoundRobin();

public:
	virtual void Add(const T&);
	virtual void Remove(const T&);
	virtual T& GetNext() throw(std::out_of_range);

protected:
	std::vector<T> element_vector;
	typename std::vector<T>::iterator element_vector_it;

private:
	/* private initialization prevents copy by value and */
	RoundRobin(const RoundRobin&);
	RoundRobin& operator=(const RoundRobin& rhs);
};

template <typename T>
RoundRobin<T>::RoundRobin(int cnt_proc = 0)
{
	// initialize vector for number of processes
	element_vector.reserve(cnt_proc);

	// vector iterator initialize
	element_vector_it = element_vector.begin();
}

template <typename T>
RoundRobin<T>::~RoundRobin(){/* Do nothing */}

template <typename T>
void RoundRobin<T>::Add(const T& element)
{
	// save current vector index
	int cur_pos = element_vector_it - element_vector.begin();
	
	// push element in the back of the vector
	element_vector.push_back(element);

	// restor iterator
	element_vector_it = element_vector.begin() + cur_pos;
}
	
template <typename T>
void RoundRobin<T>::Remove(const T& element)
{
	// search element to erase in vector
	for(auto it = element_vector.begin(); it != element_vector.end(); ++it)
	{
		// when found
		if(*it == element)
		{
			// save position
			int pos;

			// position update
			if(element_vector_it <= it)
				pos = element_vector_it - element_vector.begin();
			else
				pos = element_vector_it - element_vector.begin() - 1;

			element_vector.erase(it);

			element_vector_it = element_vector.begin() + pos;

			if(element_vector_it == element_vector.end())
				element_vector_it = element_vector.begin();
			return;
		}
	}
}

template <typename T>
T& RoundRobin<T>::GetNext() throw(std::out_of_range)
{
	// check if not empty
	if(element_vector.empty())
		throw std::out_of_range("No elements in the list!");

	// referenced data
	T& ret_val = *element_vector_it;

	++element_vector_it;
	if(element_vector_it == element_vector.end())
		element_vector_it = element_vector.begin();

	return ret_val;
}







