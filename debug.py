# coding: utf-8

import time
from lutlib import apply_lut


def main():
    start = time.time()
    result = apply_lut(
        "/Users/phyng/dev/lut/hype.cube",
        "/Users/phyng/dev/lut/1.jpg",
        "/Users/phyng/dev/lut/1_output.jpg",
    )
    print('Result:', result)
    print("Time:", time.time() - start)


if __name__ == "__main__":
    main()
