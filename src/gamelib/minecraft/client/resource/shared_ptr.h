#pragma once

namespace mc_boost {
	template<typename T>
	class shared_ptr {
	public:
		shared_ptr(T* p) {
			ptr = p;
	    	detail = nullptr;
	  	}

		shared_ptr(T* p, uint32_t* detail) {
			ptr = p;
	    	this->detail = detail;
	  	}
	
		shared_ptr() {
	    	ptr = nullptr;
	    	detail = nullptr;
	  	}
		
		T* operator->() const { return ptr; }
		T& operator[](int i) const { return ptr[i]; }
	
		T* get() const { return ptr; }

	  	T* ptr;
	  	uint32_t* detail;
	};
}