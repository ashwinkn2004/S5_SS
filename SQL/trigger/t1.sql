create or replace trigger tg1
after UPDATE on worker for each ROW
declare
    diff number := 0;
BEGIN
    diff := :new.sal - :old.sal;
    dbms_output.put_line('Salary updated by ' || diff);
END;
/
declare
    empid number := &empid;
    newSal number := &newSal;
BEGIN
    update worker set sal = newSal where id = empid;
END;
/