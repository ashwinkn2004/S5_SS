--Write a PL/SQL block to raise an exception when a division by zero occurs

declare
    a number;
BEGIN
    a := 10/0;
Exception 
    when zero_divide 
    THEN
        dbms_output.put_line('Division by zero is not allowed');
END;
/