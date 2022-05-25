#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <list>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{

	public:

		MutantStack(){}
		MutantStack( MutantStack const & src ) : std::stack<T>(src) {}
		~MutantStack() {}

    typedef typename    std::stack<T>                             MStack;
    typedef typename    MStack::container_type::iterator          iterator;
    typedef typename    MStack::container_type::const_iterator    const_iterator;
    
    MStack const &            getStack() const { return (this->_stack); }

    iterator       begin() {return this->c.begin(); }
    const_iterator begin() const {return this->c.begin(); }
    iterator       end() {return this->c.end(); }
    const_iterator end() const {return this->c.end(); }

		MutantStack &		operator=( MutantStack const & rhs ) { if (this != &rhs) { this->c = rhs.c; } return *this; }

	private:
    MStack                  _stack;
};

template <typename T>
std::ostream &			operator<<( std::ostream & o, MutantStack<T> const & i ) {
  o << "[ ";
  typename std::stack<T>::container_type::const_iterator it;
  for (it = i.begin(); it != i.end(); it++ ) {
    o << *it << ", "; 
  }
  o << "\b\b ]";
  return o;
}

#endif /* ***************************************************** MUTANTSTACK_H */