create or replace package pack_age
AS
    procedure alpha( a in number, b out varchar);
    function beta( a in number) return number ;
end pack_age;
/

create or replace package body pack_age
AS
    procedure alpha( a in number, b out varchar)
    AS
    BEGIN
        select suname into b from supplier where suid = a;
    END alpha;

    function beta( a in number)
    return number
    AS
        comm number;
    BEGIN
        select sucom into comm from supplier where suid = a;
        comm := comm * 12;
        return comm;
    END beta;
end pack_age;
/

declare
    sid number := &sid;
    procRes varchar(20);
BEGIN
    pack_age.alpha(sid, procRes);
    dbms_output.put_line('Result of procedure: ' || procRes);
END;
/

declare
    sid number := &sid;
    funRes number;
BEGIN
    funRes := pack_age.beta(sid);
    dbms_output.put_line('Result of Function: ' || funRes);
END;
/