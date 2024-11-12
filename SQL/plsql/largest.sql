declare
    a number ;
    b number ;
    c number;
BEGIN
    a := &a;
    b := &b;
    c := &c;
    if(a>c and a>b)
    THEN
        dbms_output.put_line('Largest number is '|| a);
    elsif( b> c and b >a)
    THEN
        dbms_output.put_line('Largest number is '|| b);
    ELSE
        dbms_output.put_line('Largest number is '|| c);
    end if;
END;
/