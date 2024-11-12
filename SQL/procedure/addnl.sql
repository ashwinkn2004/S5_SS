create or replace procedure insertion(dept_id in number, dept_name in varchar, manager_id in number, location in varchar)
AS
BEGIN
    insert into departments values(dept_id, dept_name, manager_id, location, sysdate());
END insertion;
/

declare
    dept_id number := &dept_id;
    dept_name varchar(20):= '&dept_name';
    manager_id number := &manager_id;
    location varchar(100) := '&location';
BEGIN
    insertion(dept_id, dept_name, manager_id, location);
END;
/
select * from departments;