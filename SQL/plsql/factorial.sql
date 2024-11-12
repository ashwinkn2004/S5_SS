declare
    num1 number;
    i number;
    fact number := 1;
BEGIN
    num1 := &num1;
    for i in 1 ..num1 
    loop
        fact := fact * i;
    end loop;
    dbms_output.put_line('Factorial of '|| num1 || ' is ' || fact);
END;
/