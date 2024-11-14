# Notes
## CMake Commands
### Build
```
>> cmake -S . -B build
>> cmake --build build
```

or
```
>> mkdir build
>> cd build
>> cmake ..
>> make
```

### Test
```
>> ctest --test-dir build
>> ./build/vector_test
```

or
```
>> cd build
>> ctest
>> ./vector_test
```
