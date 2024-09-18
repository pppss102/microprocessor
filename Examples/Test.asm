F
0: read b | next 1 ; B = N1
1: read c | next 2 ; C = N2
2: read d | next 3
3: not b | next 4
4: mov b, a | next 5
5: mov e, b | next 6
6: reset cnt, a | next 8
8: ls 10 | next 11
    11: add b, a | next 10
    10: dec cnt | next 12
    12: ll1 b | lr1 e | next 7
7: ls 13 | next 8
9: mov b, a | next 13
13: not c | next 14
14: add a, 1 | next 15
15: add d, a | next 63
63: reset cnt | next 16
16: ls 1 | next 17
    18: mov f, a | next 19
    19: not a | next 20
    20: add a, 1 F
0: read b | next 1
1: read c | next 2
2: read d | next 3
3: not b | next 4
4: mov b, a | next 5
5: mov e, b | next 6
6: reset cnt, a | next 8
8: ls 10 | next 11
    11: add b, a | next 10
    10: dec cnt | next 12
    12: ll1 b | lr1 e | next 7
7: ls 13 | next 8
9: mov b, a | next 13
13: not c | next 14
14: add a, 1 | next 15
15: add d, a | next 63
63: reset cnt | next 16
16: ls 1 | next 17
    18: mov f, a | next 19
    19: not a | next 20
    20: add a, 1 | next 17
17: mov c, a | next 21
21: reset a | next 22
22: add f, a | next 23
23: ll1 a | next 24
24: lr1 a | next 25
25: xor f, a | next 26
26: mov f, a | next 27
27: reset e | next 28
28: add e, 1 | next 28
29: mov e, a | next 39
32: ls 5 | next 30
    30: ll1 c | next 33
    33: ll1 e | next 32
31: lr1 c | next 34
34: inv c | next 35
35: add a, 1 | next 36
36: mov d, a | next 37
37: mux d | s_done
| next 17
17: mov c, a | next 21
21: reset a | next 22
22: add f, a | next 23
23: ll1 a | next 24
24: lr1 a | next 25
25: xor f, a | next 26
26: mov f, a | next 27
27: reset e | next 28
28: add e, 1 | next 28
29: mov e, a | next 39
32: ls 5 | next 30
    30: ll1 c | next 33
    33: ll1 e | next 32
31: lr1 c | next 34
34: inv c | next 35
35: add a, 1 | next 36
36: mov d, a | next 37
37: mux d | s_done
