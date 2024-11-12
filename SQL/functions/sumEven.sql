-- function to perform addition of first n even natural numbers

create or replace function sumEven(a in number)
return number
as
	i number;
	res number := 0;
begin
	for i in 1 .. a*2
	loop
		if(mod(i,2) = 0)
		then
			res := res + i;
		end if;
	end loop;
	return res;
end sumEven;
/

declare
	a number := &a;
	res number := 0;
begin
	res := sumEven(a);
	dbms_output.put_line('SUM of n numbers = : '||res);
end;
/
