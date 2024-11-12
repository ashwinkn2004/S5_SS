create or replace function factorial(a in number)
return number
AS
    fact number := 1;
    i number ;
BEGIN
    for i in 1 ..a 
    loop
        fact := fact * i;
    end loop;
    return fact;
END factorial;
/

declare
    a number := &a;
    res number ;
BEGIN
    res := factorial(a);
    dbms_output.put_line('Factorial of ' || a || ' is: ' || res);
END;
/