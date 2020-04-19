# Google Code Jam 2020

This repository contains my solutions to the problems from [Google Code Jam 2020][1] and Distributed Google Code Jam 2020. These solutions are provided "as is" - I give no guarantees that they will work as expected.

## Instructions

You can compile all Google Code Jam problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and identifier of the problem you want to compile (see section "Problems Solved" for the list of possible identifiers):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the identifier of the desired problem:

    $ ./<problem_id>

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

Distributed Google Code Jam problems should be compiled and run using the local testing tool described in the [guide][2]. An example would be:

    $ dcj test --source <round_name>/<problem_id>.cpp --nodes <number_of_nodes>

You'll need to have an input header file with the name `<problem_id>.h` in the same directory as the source file. You can download sample inputs from each problem's page.

## Problems Solved

The following is the list of the problems solved. Each problem identifier is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete or aren't efficient enough for the problem's limits.

### Qualification Round

* ✓ [A. Vestigium][qual1] (`vestigium`)
* ✓ [B. Nesting Depth][qual2] (`nesting-depth`)
* ✓ [C. Parenting Partnering Returns][qual3] (`parenting-partnering-returns`)
* ✓ [D. ESAb ATAd][qual4] (`esab-atad`)

### Round 1A

* ✓ [A. Pattern Matching][round1a1] (`pattern-matching`)
* ✓ [B. Pascal Walk][round1a2] (`pascal-walk`)
* ✓ [C. Square Dance][round1a3] (`square-dance`)

### Round 1B

* ✓ [A. Expogo][round1b1] (`expogo`)
* ✗ [B. Blindfolded Bullseye][round1b2] (`blindfolded-bullseye`)
* ✗ [C. Join the Ranks][round1b3] (`join-the-ranks`)

[1]: https://codingcompetitions.withgoogle.com/codejam
[2]: https://code.google.com/codejam/resources/quickstart-guide#dcj
[qual1]: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
[qual2]: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
[qual3]: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
[qual4]: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
[round1a1]: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b3034
[round1a2]: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1353
[round1a3]: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1355
[round1b1]: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b62
[round1b2]: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b63
[round1b3]: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b64
