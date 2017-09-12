#include <bitset>
#include <iostream>
#include <vector>

int main() {

  using namespace std;

  // Define some ranges of interest: start, end, increment
  const vector<vector<float>> ranges{
      {.01f, 0.2f, .01f}, {1.0f, 100.0f, 1.1f}, {3000.0f, 3500.0f, .1f}};

  for (const auto &r : ranges) {

    // Print a nice markdown heading for each range
    cout << "# " << r.at(0) << " to " << r.at(1) << endl;
    cout << "```" << endl;

    for (float f = r.at(0); f < r.at(1); f += r.at(2)) {

      // Dirty cast rather than truncate
      const auto bin = *reinterpret_cast<unsigned long *>(&f);

      // Print the hex and the binary
      const bitset<32> bits(bin);
      cout << "0x" << hex << bits.to_ulong() << dec << " ";
      cout << bits << " " << f << endl;
    }

    cout << "```" << endl;
  }

  return 0;
}
