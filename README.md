# ZReduction
An implementation of the linear-time online algorithm  inferring the shortest path from a walk, published in [1] and [2].

An implementaion of Raghavan's O(n log n) time algorithm [3] is also included for comparison.

## Usage
```
$ make

$ ./ZReduction abcaacbbbaabccbbca
abca

$ ./Raghavan abcaacbbbaabccbbca
abca
```

## References
1. Shintaro Narisada, Diptarama Hendrian, Ryo Yoshinaka, Ayumi Shinohara, "*Linear-Time Online Algorithm Inferring the Shortest Path from a Walk*", [arXiv:1806.09806](https://arxiv.org/abs/1806.09806), 2018.

2. Shintaro Narisada, Diptarama Hendrian, Ryo Yoshinaka, Ayumi Shinohara, "*Linear-Time Online Algorithm Inferring the Shortest Path from a Walk*", In Proc. International Symposium on String Processing and Information Retrieval (SPIRE2018), pp. 311-328, 2018.
[DOI:10.1007/978-3-030-00479-8_25](https://doi.org/10.1007/978-3-030-00479-8_25)

3. Raghavan, V. "*Bounded degree graph inference from walks*", Journal of Computer and System Sciences, Vol. 49, No. 1, pp. 108–132, 1994. [DOI:10.1016/S0022-0000(05)80089-3](https://doi.org/10.1016/S0022-0000(05)80089-3)
