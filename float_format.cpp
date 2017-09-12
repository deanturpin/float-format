#include <iostream>
#include <bitset>

int main() {

  using namespace std;

  for (float f = 1.0; f < 4000.0; f += .1) {

    // Dirty cast rather than truncation to long
    const auto bin = *reinterpret_cast<unsigned long*>(&f);

    // Print the hex and the binary
    cout << "0x" << hex << bin << dec << " " << bitset<32>(bin) << " " << f << endl;
  }

  return 0;
}
