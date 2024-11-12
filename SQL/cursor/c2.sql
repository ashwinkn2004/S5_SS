declare
    cursor s is select* from accdetails;
    crrMonth number := EXTRACT(MONTH FROM SYSDATE);
    tableMonth number;
BEGIN
    for i in s 
    loop
        tableMonth := EXTRACT(MONTH FROM i.lastdate);
        if(tableMonth != crrMonth)
        THEN
            dbms_output.put_line('table month = '|| tableMonth);
            insert into inactive_customer values(i.accno, i.cname);
        ELSE
            if(i.amount < 50000)
            THEN
                update accdetails set amount = i.amount + (i.amount * 0.05) where accno = i.accno;
            elsif(i.amount BETWEEN 25000 and 500000)
            THEN
                update accdetails set amount = i.amount + (i.amount * 0.1) where accno = i.accno;
            elsif(i.amount > 500000)
            THEN
                update accdetails set amount = i.amount + (i.amount * 0.15) where accno = i.accno;
            end if;
        end if;

    end loop;
END;
/