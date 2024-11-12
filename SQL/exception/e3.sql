-- Write a PL/SQL block to raise an exception “No transactions today”,when the sysday is Sunday
declare
    today varchar(30) := to_char(SYSDATE, 'DY');
    dateException EXCEPTION;
BEGIN
    if(today = 'TUE')
    then
        raise dateException;
    end if;
EXCEPTION
    when dateException THEN
        dbms_output.put_line('No transactions today');
END;
/