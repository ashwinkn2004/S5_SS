select * from employee;
create or replace procedure salupd( eid in number, incr in number)
as
begin
	update employee set salary = salary+((salary*incr)/100) where empid = eid;
    update employee set joindate = sysdate() where empid = eid;
end salupd;
/
declare
	eid number := &eid;
	incr number := &incr;
begin
	salupd(eid, incr);
end;
/
select * from employee;