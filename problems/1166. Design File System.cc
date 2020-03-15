#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class FileSystem {
public:
	FileSystem() {
		path_val[""] = 0;
	}

	bool create(string path, int value) {
		string parent = getParents(path);

		if (path_val.find(path) == path_val.end() &&
			path_val.find(parent) != path_val.end()) {
			path_val[path] = value;
			return true;
		}
		return false;
	}

	int get(string path) {
		if (path_val.find(path) == path_val.end()) {
			return -1;
		}
		return path_val[path];
	}

	string getParents(string path) {
		string copy_path = path;
		reverse(copy_path.begin(), copy_path.end());

		string parent = copy_path.substr(copy_path.find('/') + 1);
		reverse(parent.begin(), parent.end());
		return parent;
	}

private:
	unordered_map<string, int> path_val;
};

int main() {
	FileSystem* fileSystem = new FileSystem();
	cout << fileSystem->create("/leet", 1) << endl;
	cout << fileSystem->create("/leet/code", 2) << endl;
	cout << fileSystem->get("/leet/code") << endl;
	cout << fileSystem->create("/c/d", 1) << endl;
	cout << fileSystem->get("/c") << endl;
	// cout << fileSystem->get("/a") << endl;
}