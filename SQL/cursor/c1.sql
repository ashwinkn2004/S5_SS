declare
    cursor s is select * from customers;
BEGIN
    for i in s 
    loop
        if(i.bal_amt > 100000 and i.doj < '01-jan-2010')
        THEN
            insert into premium_customers values(i.acc_no, i.c_name, i.bal_amt, i.doj);
        ELSE
            insert into nonpremium_customers values(i.acc_no, i.c_name, i.bal_amt, i.doj);
        end if;
    end loop;
END;
/