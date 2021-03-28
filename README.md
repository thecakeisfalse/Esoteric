# Esoteric

Esoteric - a simple interpreter for esoteric languages, written in C++.

## Summary

-   [Getting Started](#getting-started)
-   [Authors](#authors)
-   [License](#license)
-   [Acknowledgments](#acknowledgments)

## Getting Started

These instructions will get you a copy of the project up and running on your machine.

### Prerequisites

There are apt packages, needed by Esoteric

    g++, cmake

### Download

To download esoteric you need to do next commands.

    git clone https://github.com/thecaketeam/esoteric
    cd esoteric
    cmake -B build
    make -C build
    sudo make -C build install

After it, you can use esoteric.

### Usage

    Usage: esoteric [options] file...
    Options:
      -x <language>    Specify the language of the following input file.
      -c               Converts input file to C file.
      -o <file>        Place the output info <file>.

## Authors

-   **Simon Chaykin** - *Main developer*

## License

This project is licensed under the [GNU GPL v3.0 LICENSE](LICENSE).

## Acknowledgments

-   [https://esolangs.org](https://esolangs.org/wiki/Main_Page)
