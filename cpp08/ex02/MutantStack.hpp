#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template <typename T>
class MutantStack
{

	public:

		MutantStack();
		MutantStack( MutantStack const & src );
		~MutantStack();

    bool empty() const;
    void pop();
    void push (const T & val);
    size_type size() const;
    value_type& top();
    const value_type& top() const;
    iterator begin();
    const_iterator begin() const;
    iterator end();

    // reverse_iterator rbegin();
    // const_reverse_iterator rbegin() const;const_iterator end() const;
    // reverse_iterator rend();
    // const_reverse_iterator rend() const;

    typedef typename std::list<T>::iterator iterator;
    typedef typename std::list<T>::const_iterator const_iterator;

		MutantStack &		operator=( MutantStack const & rhs );

	private:
    std::stack<T>       _stack;
    unsigned int        _size;

};

template <typename T>
std::ostream &			operator<<( std::ostream & o, MutantStack<T> const & i );

#endif /* ***************************************************** MUTANTSTACK_H */