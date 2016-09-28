# Project Fuzzy Testing

Innovative Programming at Liu.

# Build example

To build the provided example run:
```sh
mkdir build
cd build
cmake ../example/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make
```

The current example will fail during linking.
The team thus have to provide the missing implementation/symbols.
Note that the -DCMAKE_EXPORT_COMPILE_COMMANDS instructs cmake to generate a compile_commands.json.
