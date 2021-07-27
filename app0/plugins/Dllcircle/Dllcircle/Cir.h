class Cir {
	const char* name;
public:
	Cir(const char* CSVfile);
	const char* Find(const char* name,const char* path);
};
extern "C" _declspec(dllexport) void* Create(const char* name) {
	return (void*)new Cir(name);
}
extern "C" _declspec(dllexport) void FindDetect(Cir *c, const char* csvPath,const char* Path,char *result) {
	const char* ct=c->Find(csvPath,Path);
	//const char* ct = "hello";
	strcpy(result, ct);
}
