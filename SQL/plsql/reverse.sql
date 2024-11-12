declare
 a number := &a;
 i number ;
 rev number := 0;
 ld number;
BEGIN
    for i in 1.. length(a)
    loop
        ld := mod(a,10);
        rev := (rev*10) + ld;
        a := trunc(a/10);
    end loop;
    dbms_output.put_line('Reverse of number is '|| rev);
END;
/