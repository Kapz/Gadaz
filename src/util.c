#include "util.h"

unsigned int util_type_size(GLenum type){
    switch (type) {
		case GL_BYTE:
			return 1;
			break;
		case GL_UNSIGNED_BYTE:
			return 1;
			break;
		case GL_SHORT:
			return 2;
			break;
		case GL_UNSIGNED_SHORT:
			return 2;
			break;
		case GL_INT:
			return 4;
			break;
		case GL_UNSIGNED_INT:
			return 4;
			break;
		case GL_FIXED:
			return 4;
			break;
		case GL_HALF_FLOAT:
			return 2;
			break;
		case GL_FLOAT:
			return 4;
			break;
		case GL_DOUBLE:
			return 6;
			break;
		default:
			return 4;
			break;
	}
}