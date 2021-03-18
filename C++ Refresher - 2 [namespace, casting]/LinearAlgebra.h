/*--------------------------------------------------------------------------+
|	Toy header to demonstrate the purpose and use of namespaces.			|
|																			|
|	Jean-Yves Hervé, 3DG, Dept. of Computer Science and Statistics, URI		|
|	2020-02-28																|
+--------------------------------------------------------------------------*/

#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

//	I declare that my class belongs to a specific namespace
namespace linalg
{
	class vector
	{
		
		public:
		
			//	The standard constructors/destructor/operators that
			//	you should either declare and implement or disable
			vector(void);
			vector(const vector& v) = default;
			vector(vector&& v) = delete;
			~vector(void);		
			vector& operator = (const vector& v) = default;
			vector& operator = (vector&& v) = delete;
			
			//	some additional function / operator
			vector operator +(const vector& v) const;
			vector operator *(float a) const;
			unsigned int size(void) const;
			float at(unsigned int index) const;
			float norm1(void) const;
			float norm2(void) const;
			float normInf(void) const;
			void normalize(void);
		
		private:
		
			unsigned int size_;
			float* v;
			mutable float norm1_, norm2_, normInf_;
			mutable bool norm1IsUpToDate_, norm2IsUpToDate_, normInfIsUpToDate_;
			
			void computeNorm1_(void) const;
			void computeNorm2_(void) const;
			void computeNormInf_(void) const;
			
	};
}

#endif	//	LINEAR_ALGEBRA_H