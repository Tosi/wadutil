#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "06";
	static const char MONTH[] = "01";
	static const char YEAR[] = "2016";
	static const char UBUNTU_VERSION_STYLE[] =  "16.01";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 0;
	static const long BUILD  = 38;
	static const long REVISION  = 202;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 47;
	#define RC_FILEVERSION 0,0,38,202
	#define RC_FILEVERSION_STRING "0, 0, 38, 202\0"
	static const char FULLVERSION_STRING [] = "0.0.38.202";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 38;
	

}
#endif //VERSION_H
