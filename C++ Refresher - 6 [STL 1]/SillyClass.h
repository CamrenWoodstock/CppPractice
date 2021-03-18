/*
 *  SillyClass.h
 *
 *  Created by jean-yves hervé on 2020-02-27
 *
 */
 
 #include <string>
 #include <vector>

class SillyClass {

	public:
	
		SillyClass(int m, int n);
		
		~SillyClass(void);

		int getM(void) const;
		
		int getN(void) const;
		
		void setM(int m);
		
		void setN(int n);
		
		std::string toString(void) const;
		
		bool operator >= (const SillyClass& b) const;


	private:
	
		int m_; 
		int n_;
		
		std::vector<int> v_;


};

bool operator < (const SillyClass& a, const SillyClass& b);

