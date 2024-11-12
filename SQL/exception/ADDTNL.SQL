--pgm to rasie ex if age < 18 for license

declare
    ageLimit EXCEPTION;
    age number := &age;
BEGIN
    if(age < 18)
    THEN
        raise ageLimit;
    ELSE
        dbms_output.put_line('You are eligible for license');
    end if;
EXCEPTION
    when ageLimit
    THEN
        dbms_output.put_line('You are not eligible for license');
END;
/