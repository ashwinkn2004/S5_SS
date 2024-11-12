--Create table named emp have column like id with notnull constraint,name etc. Raise 
--an exception “Not null values not allowed “ when the user tries to enter a null value 
--for id.

DECLARE
    emissing EXCEPTION;
    PRAGMA EXCEPTION_INIT(emissing, -1400);
BEGIN
    insert into emp(id) values(null);
EXCEPTION
    when emissing THEN
        dbms_output.put_line('Not null values not allowed');
END;
/