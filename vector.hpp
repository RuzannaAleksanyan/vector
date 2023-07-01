#ifndef VECTOR
#define VECTOR

#include <iostream>
#include <string>

template <typename T>
class Vector
{
    private:
        T*      m_arr;
        int     m_size;
        int     m_capacity;
    public:
		constexpr Vector(int capacity = 0) noexcept;
		constexpr Vector(std::initializer_list<T>) noexcept;

		constexpr Vector(const Vector<T>&) noexcept;
		constexpr Vector(int, T&) noexcept;
		constexpr Vector(Vector<T>&& other) noexcept;

		~Vector();

		constexpr void reserve(int count);
		constexpr void resize() noexcept;
	    constexpr void push_back(const T&);
	    constexpr void pop_back();
		constexpr T& at(int) const;
		constexpr int size() const noexcept;
		constexpr void clear() noexcept;
		constexpr T& front() const;
		constexpr T& back() const;
		constexpr bool empty() const noexcept;
		constexpr int capacity() const noexcept;		
		constexpr void erase(int);
		constexpr void insert(int, const T&);
		constexpr void insert(int, int, int);
		constexpr void insert(Vector*, int, int);
		constexpr T& operator[](const int) const;
		constexpr Vector<T>& operator=(const Vector<T>&) noexcept;
		constexpr T* begin() const noexcept;
		constexpr T* end() const noexcept;
		friend std::ostream& operator<<(std::ostream& os, Vector<T> vec)  
		{
        	for(int i = 0; i < vec.size(); ++i) 
			{
            	os << vec.m_arr[i] << " ";
        	}
        	return os;
    	}
};

template <typename T>
constexpr void Vector<T>::reserve(int count)
{
	if(m_capacity != count)
	{
		m_capacity = count;
		T* tmp = new T[m_capacity];
		for(int i = 0; i < m_size; ++i)
		{
			tmp[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = tmp;
		tmp = nullptr;
	}
}

template <typename T>
constexpr Vector<T>::Vector(int capacity) noexcept
{
	m_size = 0;
	m_capacity = capacity;
	m_arr = new T[m_capacity];
}

template <typename T>
constexpr Vector<T>::Vector(const Vector<T>& other) noexcept
    : m_size(other.m_size), m_capacity(other.m_capacity)
{
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = other.m_arr[i];
    }
}

template <typename T>
constexpr Vector<T>::Vector(int size, T& value) noexcept
    : m_size(size), m_capacity(size)
{
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) 
	{
        m_arr[i] = value;
    }
}

template <typename T>
constexpr Vector<T>::Vector(std::initializer_list<T> init) noexcept
    : m_size(init.size()), m_capacity(init.size())
{
    m_arr = new T[m_capacity];
    int i = 0;
    for (const auto& value : init) {
        m_arr[i] = value;
        ++i;
    }
}

template <typename T>
constexpr Vector<T>::Vector(Vector<T>&& other) noexcept
    : m_arr(other.m_arr), m_size(other.m_size), m_capacity(other.m_capacity)
{
    other.m_arr = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] m_arr;
}

template <typename T>
constexpr void Vector<T>::resize() noexcept
{
	m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
	T* tmp = new T[m_capacity];
	for(int i = 0; i < m_size; ++i)
	{
		tmp[i] = m_arr[i];
	}
	delete [] m_arr;
	m_arr = tmp;
	tmp = nullptr;
}

template <typename T>
constexpr void Vector<T>::push_back(const T& elem)
{
	if(m_size == m_capacity)
	{
		resize();
	}
	m_arr[m_size] = elem;
	m_size++;
}

template <typename T>
constexpr void Vector<T>::pop_back()
{
	if(m_size != 0)
    {
        m_size--;
    }
}

template <typename T>
constexpr T& Vector<T>::at(int index) const
{
	if(index < m_size && index >= 0)
	{
		return m_arr[index];
	}
	else
	{
		throw std::out_of_range("error");
	}
	
}

template <typename T>
constexpr int Vector<T>::size() const noexcept
{
	return m_size;
}

template <typename T>
constexpr void Vector<T>::clear() noexcept
{
	m_size = 0;
}

template <typename T>
constexpr T& Vector<T>::front() const
{
	return at(0);
}

template <typename T>
constexpr T& Vector<T>::back() const 
{
	return at(m_size - 1);
}

template <typename T>
constexpr bool Vector<T>::empty() const noexcept
{
	if(m_size == 0)
	{
		return true;
	}
	return false;
}

template <typename T>
constexpr int Vector<T>::capacity() const noexcept
{
	return m_capacity;
}

template <typename T>
constexpr void Vector<T>::erase(int index)
{
	at(index);
	for(int i = index; i < m_size; ++i)
	{
		m_arr[i] = m_arr[i + 1];
	}
	m_size--;
}

template <typename T>
constexpr void Vector<T>::insert(int index, const T& elem)
{
	if(index >= 0 && index < m_size) //
	{
		m_size++;
		for (int i = m_size; i > index; --i)
		{
			m_arr[i] = m_arr[i - 1];
		}
		m_arr[index] = elem;
	}
}

template <typename T>
constexpr void Vector<T>::insert(int index, int count, int elem)
{
	if(index < 0 || index >= m_size)
	{
		m_size += count;
		for (int i = m_size - 1; i > index + 1; --i)
		{
			m_arr[i] = m_arr[i - 2];
		}
		m_arr[index] = elem;
		m_arr[index + 1] = elem;
	}
}

template <typename T>
constexpr void Vector<T>::insert(Vector* v, int start, int end)
{
	if(start >= 0 && start < m_size && end >= start)
	{
		m_size = m_size + end - start + 1;
		for(int i = m_size - (end - start + 1); i < m_size + (end - start + 1); ++i)
		{
			if(start != end + 1)
			{
				m_arr[i] = v->arr[start];
				start++;
			}
		}
	}
}

template <typename T>
constexpr T& Vector<T>::operator[](const int index) const
{ 
    return at(index); 
}

template <typename T>
constexpr Vector<T>& Vector<T>::operator=(const Vector<T>& other) noexcept
{
	if(this == &other)
	{
		return *this;
	}
	m_size = 0;
	for(int i = 0; i < other.m_size; ++i)
	{
		push_back(other.m_arr[i]);
	}
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	return *this;
}

template <typename T>
constexpr T* Vector<T>::begin() const noexcept
{
	return m_arr;
}

template <typename T>
constexpr T* Vector<T>::end() const noexcept
{
	return m_arr + m_size - 1;
}

#endif