-module(my_math).
-export([factorial/1]).

factorial(Num) when is_integer(Num) and (Num >= 0) ->
	factorial(Num, 1).
factorial(0, Res)->
	Res;
factorial(Num, Res)->
	factorial(Num -1, Num*Res).
