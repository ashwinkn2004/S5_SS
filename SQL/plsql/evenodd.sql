create table even(even number);
create table odd(odd number);

declare
    i number;
BEGIN
    for i in 1 ..20
    loop
        if(mod(i,2) = 0)
        THEN
            insert into even values(i);
        else 
            insert into odd values(i);
        end if;
    end loop;
END;
/
select * from odd;
select * from even;