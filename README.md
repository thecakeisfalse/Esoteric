# Esoteric [![Build Status](https://travis-ci.com/thecaketeam/Esoteric.svg?branch=master)](https://travis-ci.com/thecaketeam/Esoteric)

Esoteric - a simple interpreter for esoteric languages, written in C.

## Summary

-   [Getting Started](#getting-started)
-   [Authors](#authors)
-   [License](#license)
-   [Acknowledgments](#acknowledgments)

## Getting Started

These instructions will get you a copy of the project up and running on your machine.

### Prerequisites

There are apt packages, needed by Esoteric

    gcc, make

### Download

To download Esoteric you need to do next commands.

```bash
git clone https://github.com/thecaketeam/Esoteric
cd esoteric
make
sudo make install
```

After it, you can use esoteric.

### Running

To run esoteric you need to do next.

```bash
esoteric <filename>
```

If you are using Malbolge or HQ9+, it will return output of commands. Otherwise it will generate C code output that you need to compile to use.

## Authors

-   **Simon Chaykin** - *Main developer*

## License

This project is licensed under the [GNU GPL v3.0 LICENSE](LICENSE).

## Acknowledgments

-   [https://esolangs.org](https://esolangs.org/wiki/Main_Page)
