inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
    object ob;
    string who, what;
    if( me != this_player(1) ) return 0;

    ob = me->query_temp("link_ob");
    if( !ob ) return 0;
    while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

    write("���������QQ/icq��");
    input_to("get_number", 1, ob);
    return 1;
}

private void get_number(string number, object ob)
{
    seteuid(getuid());
    if( !ob->set("QQ", number) ) {
        write("QQ/icq���ʧ�ܣ�\n");
        return;
    }

    ob->save();
    write("QQ/icp����ɹ�\��\n");
}
 
int help(object me)
{
        write(@HELP
ָ���ʽ : qq
 
���ָ������޸��������QQ/icq��
 
HELP
    );
    return 1;
}
 
