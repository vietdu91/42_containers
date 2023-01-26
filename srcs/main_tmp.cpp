namespace	ft {

	template<typename Iterator>
	std::ptrdiff_t distance(Iterator first, Iterator last) {
		std::ptrdiff_t dist = 0;
		while (first != last) {
			++dist;
			++first;
		}
		return (dist);
	}

	template<
		class T,
		class Allocator = std::allocator<T>
	>
	class vector {
		public:
			typedef Allocator 												allocator_type;
			typedef typename allocator_type::value_type						value_type;
			typedef typename allocator_type::size_type						size_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference 				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer 					const_pointer;
			typedef ft::random_access_iterator<value_type> 					iterator;
			typedef ft::random_access_iterator<const value_type> 			const_iterator;
			typedef	ft::reverse_iterator<iterator> 							reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator> 					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;

			// ================ Constructors ================

			explicit vector(const allocator_type& alloc = allocator_type()): _data(), _size(0), _capacity(0), _allocator(alloc) {};

			explicit vector(size_type count,const T& value = T(), const allocator_type& alloc = allocator_type()){

				_allocator = alloc;
				_size = 0;
				_capacity = 0;
				assign(count, value);
			};

			template<class InputIt>
			vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL){

				_allocator = alloc;
				_size = 0;
				_capacity = 0;
				assign(first, last);
			};

			vector(const vector& other): _data(), _size(0), _capacity(0),_allocator(allocator_type()){

				*this = other;
			};

			vector&	operator=(const vector& other) {

				if (this != &other) {

					_allocator = allocator_type();
					_size = 0;
					_capacity = other.size();
					_data = _allocator.allocate(other.size());

					for (size_type i = 0; i < other.size(); i++) {

						_allocator.construct(_data + i, other[i]);
						_size++;
					}
				}
				return (*this);
			};

			// ================ END Constructors ================
			// ================    Destructor    ================
			~vector(){
				for (size_type i = 0; i < _size; i++) {
					_allocator.destroy(_data + i);
				}
				if (_capacity > 0)
					_allocator.deallocate(_data, _capacity);
			};
			// ================  END Destructor  ================

			// ================     Iterator     ================
			iterator begin(){
				return (iterator(_data));
			};

			const_iterator begin() const{
				return (const_iterator(_data));
			};

			iterator end(){
				return (iterator(_data + _size));
			};

			const_iterator end() const{
				return (const_iterator(_data + _size));
			};

			reverse_iterator rbegin(){
				return (reverse_iterator(end()));
			};

			const_reverse_iterator rbegin() const{
				return (const_reverse_iterator(end()));
			};

			reverse_iterator rend(){
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator rend() const{
				return (const_reverse_iterator(begin()));
			};

			// ================ END Iterator     ================
			// ================     Capacity     ================
			size_type size() const{
				return (_size);
			};

			size_type max_size() const{
				return (_allocator.max_size());
			};

			void	resize(size_type n, value_type val = value_type()){
				if (n > _capacity)
					reserve(n);
				if (n >= _size){
					for (size_type i = _size; i < n; i++)
						_allocator.construct(_data + i, val);
				}
				else {
					for (size_type i = n; i < _size; i++)
						_allocator.destroy(_data + i);
					_capacity = n;
				}
				_size = n;
			}

			size_type capacity() const{
				return (_capacity);
			};

			bool empty() const{
				return (_size == 0);
			};

			void	reserve(size_type n){
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n > _capacity){
					pointer tmp = _allocator.allocate(n);
					for (size_type i = 0; i < _size; i++)
						_allocator.construct(tmp + i, _data[i]);
					for (size_type i = 0; i < _size; i++)
						_allocator.destroy(_data + i);
					if (_capacity > 0)
						_allocator.deallocate(_data, _capacity);
					_data = tmp;
					_capacity = n;
				}
			};
			// ================ END Capacity     ================
			// ================  Element access  ================
			reference operator[](size_type pos){
				return (_data[pos]);
			};

			const_reference operator[](size_type pos) const{
				return (_data[pos]);
			};

			reference at(size_type pos){
				if (pos >= _size)
					throw std::out_of_range("vector::at");
				return (_data[pos]);
			}

			const_reference at(size_type pos) const{
				if (pos >= _size)
					throw std::out_of_range("vector::at");
				return (_data[pos]);
			}

			reference front(){
				return (_data[0]);
			};

			const_reference front() const{
				return (_data[0]);
			};

			reference back(){
				return (_data[_size - 1]);
			};

			const_reference back() const{
				return (_data[_size - 1]);
			};
			// ================END Element access  ================
			// ================     Modifiers    ================
			void	clear(){
				if (_size > 0){
					resize(0);
				}
			}

			iterator	insert(iterator position, const value_type& val){
				size_type n = ft::distance(begin(), position);
				insert(position, 1, val);
				return (iterator(&_data[n]));
			};

			void	insert(iterator position, size_type n,const value_type& val){
				vector tmp(position, end());
				_size -= ft::distance(position, end());

				while (n){
					push_back(val);
					n--;
				}
				iterator it = tmp.begin();
				while (it != tmp.end()){
					push_back(*it); // push_back modify size
					it++;
				}
			};

			template <class InputIt>
			void	insert(iterator position, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL){
				vector tmp(position, end());
				_size -= ft::distance(position, end());
				while (first != last){
					push_back(*first);
					first++;
				}
				iterator it = tmp.begin();
				while (it != tmp.end()){
					push_back(*it);
					it++;
				}
			};

			iterator	erase(iterator position){
				if (empty())
					return (end());
				iterator first = begin();
				while (first != position)
					first++;
				_allocator.destroy(&(*first));
				while (first + 1 != end()){
					_allocator.construct(&(*first), *(first + 1));
					first++;
				}
				pop_back();
				return (position);
			};

			iterator erase (iterator first, iterator last){
				if (empty())
					return (end());
				difference_type n = ft::distance(first, last);
				iterator begin = this->begin();
				while (begin != first)
					begin++;
				for (; first != last; first++)
					_allocator.destroy(&(*first));
				while (first + n != end()){
					_allocator.construct(&(*first), *(first + n));
					first++;
				}
				while (n-- > 0)
					pop_back();
				return (first);
			};

			void	push_back(const value_type& val){
				if (_size == _capacity)
					empty() ? reserve(1) : reserve(_capacity * 2);
				_allocator.construct(_data + _size, val);
				_size++;
			};

			void	pop_back(){
				if (_size > 0){
					_size--;
					_allocator.destroy(_data + _size);
				}
			};

			void	swap(vector& other){
				allocator_type    tmp_allocator = _allocator;
				pointer           tmp_data = _data;
				size_type         tmp_capacity = _capacity;
				size_type         tmp_size = _size;

				_allocator = other._allocator;
				_data = other._data;
				_capacity = other._capacity;
				_size = other._size;

				other._allocator = tmp_allocator;
				other._data = tmp_data;
				other._capacity = tmp_capacity;
				other._size = tmp_size;
			}

			template <class InputIt>
			void assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL){
				clear();
				while (first != last){
					push_back(*first);
					first++;
				}
			};

			void assign(size_type n, const value_type& val){
				clear();
				while (n){
					push_back(val);
					n--;
				}
			};

			allocator_type	get_allocator()const {
				return (_allocator);
			}
		private:
			pointer _data;
			size_type _size;
			size_type _capacity;
			allocator_type _allocator;
	};

	template <class T, class Alloc>
	bool operator==( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return (!(lhs.size() == rhs.size()) && !(ft::equal(lhs.begin(), lhs.end(), rhs.begin())));
	}

	template <class T, class Alloc>
	bool operator<( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return (!(lhs > rhs));
	}

	template <class T, class Alloc>
	bool operator>( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs ){
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	}
}

int		main(void)
{
	ft::vector<int> vct(5);
	ft::vector<int>::iterator it = vct.begin(), ite = vct.end();

	lenght = ite - it;
	std::cout << "len: " << lenght << std::endl;
}
