#include <bitset>
#include <iostream>
#include <vector>

int main() {

  using namespace std;

  // Define some ranges of interest: start, end, increment
  const vector<vector<float>> ranges{{.01f, 0.2f, .01f},
                                     {1.0f, 100.0f, 1.1f},
                                     {500.0f, 550.0f, .5f},
                                     {3000.0f, 3200.0f, .05f}};

  for (const auto &r : ranges) {

    // Print a nice markdown heading for each range
    cout << "# " << r.at(0) << " to " << r.at(1) << endl;
    cout << "```" << endl;

    for (float f = r.at(0); f < r.at(1); f += r.at(2)) {

      // Dirty cast rather than truncate
      const auto bin = *reinterpret_cast<unsigned long *>(&f);

      // Convert bits to a string so we can split them up nicely
      const auto bits = bitset<32>(bin);
      auto bit_string = bits.to_string();

      // Space out the bits for readability
      // 1 sign, 8 exponent, 23 mantissa
      bit_string.insert(9, "_");
      bit_string.insert(1, "_");

      // Print the hex and the binary
      cout << hex << bits.to_ulong() << dec << " ";
      cout << bit_string << " " << f << endl;
    }

    cout << "```" << endl;
  }

  return 0;
}
