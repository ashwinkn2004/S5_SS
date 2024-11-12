create or replace procedure largest(a in number, b in number, c out number)
AS
BEGIN
    if(a > b)
    THEN
        c := a;
    ELSE
        c := b;
    end if;
END largest;
/
declare
    a number := &a;
    b number := &b;
    c number := 0;
BEGIN
    largest(a, b, c);
    dbms_output.put_line('Largest number is: ' || c);
END;
/
