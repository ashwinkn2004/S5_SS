declare
    str1 varchar(20);
    chkstr varchar(20);
BEGIN
    str1 := '&str1';
    for i in reverse 1.. length(str1)
    loop
        chkstr := chkstr || substr(str1,i,1);
    end loop;
    if(str1 = chkstr)
    THEN
        dbms_output.put_line('Palindrome');
    ELSE
        dbms_output.put_line('Not a Palindrome');
    end if;
END;
/