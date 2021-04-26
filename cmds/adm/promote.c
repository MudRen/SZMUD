// Code of ShenZhou
// promote.c
// modified by sdong so that can edit wizard's ip access online, 11/18/98

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string promotee,old_status, new_status,new_site;
	int my_level, ob_level, level;
	string uid, *wiz, wizlist;
	int i;


	if( me!=this_player(1) ) return 0;

        if( wizhood(me) != "(admin)" && wizhood(me) != "(arch)" && me->geteuid() != "buwu" ) return 0;

	if( !arg )	return notify_fail("ָ���ʽ��promote <ʹ����> <�ȼ�> <Access IP> or promote list\n");

	if(arg == "list")
	{
		write( SECURITY_D->query_wizlist() );
		return 1;
	}


	if( sscanf(arg, "%s %s %s", promotee, new_status,new_site) != 3 )
		if( sscanf(arg, "%s %s", promotee, new_status)!=2 )
			return notify_fail("ָ���ʽ��promote <ʹ����> <�ȼ�> <Access IP>\n");

	if( wiz_level(new_status) <= 0 && new_status != "(player)" ) return notify_fail("û�����ֵȼ���\n");

	if( !objectp(ob = present(promotee, environment(me))) )
		ob = find_player(promotee);

	if( ob && !userp(ob) )
		return notify_fail("��ֻ�ܸı�ʹ���ߵ�Ȩ�ޡ�\n");

	if(!ob)
	{
		seteuid(getuid());
		ob = new("/clone/test/dummy");
		ob->set("id", promotee);
		if ( !ob->restore() )
		{
			notify_fail("û�������ҡ�\n");
		}
		seteuid(getuid());
	}

/*
	if( wiz_level(me) < wiz_level(ob) )
		return notify_fail("��û������Ȩ����\n");

	if( wiz_level(me) < wiz_level(new_status) )
		return notify_fail("��û������Ȩ����\n");
*/
	old_status = wizhood(ob);

	seteuid(getuid());
	if( !(SECURITY_D->set_status(ob, new_status,new_site,me->query("name")+"("+me->query("id")+")" )) )
		return notify_fail("�޸�ʧ�ܡ�\n");

	message_vision("$N��$n��Ȩ�޴� " + old_status + " ��Ϊ " + new_status + "�� ���ߵ�ַ��Ϊ: " + new_site + " ��\n", me, ob);
	seteuid(getuid());
	ob->setup();

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : promote <ĳ��> (Ȩ�޵ȼ�) (Access IP)

��������Ȩ�޵ȼ�, (player) (immortal) (apprentice) (wizard)
(arch) (admin)
һ�� admin ������Ȩ�����κεȼ�, �� arch ֻ�������� arch��
HELP
	 );
	 return 1;
}

