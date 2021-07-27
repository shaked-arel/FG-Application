class Cir {
	const char* name;
public:
	Cir(const char* CSVfile);
	const char* Find(const char* name);
};
extern "C" _declspec(dllexport) void* Create(const char* name) {
	return (void*)new Cir(name);
}
extern "C" _declspec(dllexport) const char* FindDetect(Cir * c, const char* csvPath) {
	return c->Find(csvPath);
}
