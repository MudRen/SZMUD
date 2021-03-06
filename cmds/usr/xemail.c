inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
    object ob;
    string who, what;
    if( me != this_player(1) ) return 0;

    ob = me->query_temp("link_ob");
    if( !ob ) return 0;
    while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

    write("为了安全起见，请先输入您的保密密码：");
    input_to("get_old_pass", 1, ob);
    return 1;
}
 
private void get_old_pass(string pass, object ob)
{
    string old_pass;

    write("\n");
    old_pass = ob->query("check_password");
    if( crypt(pass, old_pass)!=old_pass ) {
        write("密码错误！\n");
        return;
    }
    write("请输入新的e-mail");
    input_to("get_new_email", 1, ob );
}
 
private void get_new_email(string email, object ob)
{
    seteuid(getuid());
    if( !ob->set("email", email) ) {
        write("email变更失败！\n");
        return;
    }

    ob->save();
    write("email变更成功\。\n");
}
 
int help(object me)
{
        write(@HELP
指令格式 : email
 
这个指令可以修改你的人物email。
 
HELP
    );
    return 1;
}
 
