# Getting started with nlohmann/json using conan package manager

## Installing and setting up conan

```
pip install --user conan --upgrade
source ~/.profile
conan profile detect --force
```

When encountering issues, consult [official documentation][1].

[1]: https://docs.conan.io/2/installation.html

## Build

```
conan install . --output-folder=build --build=missing
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

More info [here][2] and [here][3].

[2]: https://docs.conan.io/2/tutorial/consuming_packages.html
[3]: https://conan.io/center/recipes/nlohmann_json?version=

## Run

```
./hello_json
```
