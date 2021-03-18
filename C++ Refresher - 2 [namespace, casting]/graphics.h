/*--------------------------------------------------------------------------+
|	Toy header to demonstrate the purpose and use of namespaces.			|
|																			|
|	Jean-Yves Hervé, 3DG, Dept. of Computer Science and Statistics, URI		|
|	2020-02-28																|
+--------------------------------------------------------------------------*/

namespace graph
{
	class vector
	{
		
		public:
		
			//	The standard constructors/destructor/operators that
			//	you should either declare and implement or disable
			vector(void);
			vector(const vector& v);
			vector(vector&& v) = delete;
			~vector(void);		
			vector operator = (const vector& v);
			vector operator = (vector&& v) = delete;
			
			//	some additional function / operator
			void draw(void) const;

		
		private:
		
			unsigned int color_;
			float thickness_;
			float xy1_[2], xy2_[2];
	};
}