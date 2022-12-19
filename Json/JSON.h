#ifndef CH_JSON_H__
	#define CH_JSON_H__
	typedef enum { J_NULL, J_FALSE, J_TRUE, J_NUMBER, J_OBJECT, J_STRING, J_ARRAY } j_type;
	typedef struct {
		j_type type;
	}j_value;
	int j_parse(j_value* v, const char* json);
	enum j_parse_ret {
		J_PARSE_OK = 0,
		J_PARSE_EXPECT_VALUE,
		J_PARSE_INVALID_VALUE,
		J_PARSE_ROOT_NOT_SINGULAR
	};
#endif // !CH_JSON_H__
