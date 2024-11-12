declare
    a number := 0;
    b number := 1;
    c number;
    limit number;
    i number;
BEGIN
    dbms_output.put_line(a);
    dbms_output.put_line(b);
    limit := &limit;
    for i in 1 ..limit-2
    loop
        c:= a + b;
        dbms_output.put_line(c);
        a := b;
        b := c;
    end loop;
END;
/