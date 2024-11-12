declare
    var1 number := &var1;
    var2 number := &var2;
    var3 number;
begin
    var3 :=  var1 + var2;
    dbms_output.put_line('SUM  = '|| var3);
END;
/