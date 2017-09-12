#include <iostream>
#include <bitset>
#include <vector>

int main() {

  using namespace std;

  const vector<vector<float>> ranges {
    {1.0, 100, 1.1},
    {3000.0, 3500.0, .1}
  };

  for (const auto &r : ranges) {

    cout << "# " << r.at(0) << " to " << r.at(1) << endl;
    cout << "```" << endl;

    for (float f = r.at(0); f < r.at(1); f += r.at(2)) {

      // Dirty cast rather than truncation to long
      const auto bin = *reinterpret_cast<unsigned long*>(&f);

      // Print the hex and the binary
      cout << "0x" << hex << bin << dec << " " << bitset<32>(bin) << " " << f << endl;
    }

    cout << "```" << endl;
  }

  return 0;
}
