//renwu.c 
//keyboy@shiji
#include <ansi.h>
inherit F_CLEAN_UP;

string replace_color(string, int);

int main(object me, string arg)
{
        int i, flag = 0;
        object ob;
        string mission, bm, sb;
        if( me!=this_player(1) ) return 0;

        if( !arg)
                return notify_fail("ָ���ʽ��renwu [<��ʦ��> <������>]|[list]\n");

	if(arg == "list")
	{
		write( SECURITY_D->query_renwu());
		return 1;
	}

        if( sscanf(arg, "%s %s %s", sb, bm, mission)!=3 )
        	if( sscanf(arg, "%s %s", sb, mission)!=2 )
                	return notify_fail("ָ���ʽ��renwu <��ʦ��> <���Ŵ���> (Ŀǰ����)\n");

        if( strlen(mission) > 100 )
		return notify_fail("��д������̫���ˣ�����һЩ�ɣ�\n");

        if( !objectp(ob = present(sb, environment(me))))
		ob = find_player(sb);

	if( ob && !userp(ob) )
		return notify_fail("��ֻ�ܸı�ʹ���ߵ�����\n");

	if(!ob)
	{
		seteuid(getuid());
		ob = new("/clone/test/dummy");
		ob->set("id", sb);
		if ( !ob->restore() )
		{
			notify_fail("û�������ҡ�\n");
		}
		seteuid(getuid());
	}
                
//        if( ob && !wizardp(ob) && mission != "del")
//                 return notify_fail("��ֻ�ܸı���ְ��ʦ������\n");

	seteuid(getuid());

	if (bm && bm != "GLB" && bm != "SWB" && bm != "KFB")
			return notify_fail("���Ŵ������\n����ֱ��ǣ�GLB ������KFB ��������SWB ������񲿡�\n");
	
	if( !(SECURITY_D->set_renwu(ob, mission, bm)) )
		return notify_fail("�޸�ʧ�ܡ�\n");
          
	if( mission != "del")
        	message_vision("$N��$n�Ĺ��������Ϊ " + mission + " ��\n", me, ob);
	else message_vision("$N��$n�Ĺ�������ȡ���ˡ�\n", me, ob);
	seteuid(getuid());
	ob->setup();
        return 1;
}
        
string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : renwu <��ʦ��> <���Ŵ���> (Ŀǰ����)

������������GLB ������KFB ��������SWB �������
�����ı���ʦ��ǰ���������˵����
ȡ�������� renwu del ���
HELP
        );
        return 1;
}




