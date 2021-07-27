public class Reg {
	const char* name;
public:
	Reg(const char* CSVfileName);
	const char* findDetect(const char* det, const char* path);
};

extern "C" _declspec (dllexport) void* Create(const char* name) {
	return (void*) new Reg(name);
}
extern "C" _declspec(dllexport) void FindDetect(Reg * r, const char* csvPath, const char* Path, char* result) {
	const char* rt = r->findDetect(csvPath, Path);
	strcpy(result, rt);
}