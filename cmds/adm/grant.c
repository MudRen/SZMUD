// Code of ShenZhou
// grant.c
// grant file access right to wizard
// by sdong , 11/18/98

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string type,dir,wizlist;
	int result;

	if( me!=this_player(1) ) return 0;

//	if( wizhood(me) != "(admin)" && wizhood(me) != "(arch)" && wizhood(me) != "(wizard)" ) return 0;

	if( !arg )	return notify_fail("ָ���ʽ��grant <AccessType> <Ŀ¼>: <��ʦ>, or grant <AccessType> list.\n");


	if( sscanf(arg, "%s %s:%s", type, dir,wizlist) != 3 )
		if( sscanf(arg, "%s %s", type, dir)!=2 )
		{
			 notify_fail("ָ���ʽ��grant <AccessType> <Ŀ¼>:<��ʦ>, or grant <AccessType> list.\n");
		}

	if( dir == "list" )
	{
		if(type == "read") write( SECURITY_D->query_readlist() );
		else if(type == "write") write( SECURITY_D->query_writelist() );
		else if(type == "cmd") write( SECURITY_D->query_cmdlist() );
		else if(type == "excluderead") write( SECURITY_D->query_exclude_readlist() );
		else if(type == "excludewrite") write( SECURITY_D->query_exclude_writelist() );
		else if(type == "excludecmd") write( SECURITY_D->query_exclude_cmdlist() );
		return 1;
	}

	seteuid(getuid());
	if(type == "read") result = SECURITY_D->set_readaccess(dir,wizlist);
	else if(type == "write") result = SECURITY_D->set_writeaccess(dir,wizlist);
	else if(type == "cmd") result = SECURITY_D->set_cmdlist(dir,wizlist);
	else if(type == "excluderead") result = SECURITY_D->set_exclude_readaccess(dir,wizlist);
	else if(type == "excludewrite") result = SECURITY_D->set_exclude_writeaccess(dir,wizlist);
	else if(type == "excludecmd") result = SECURITY_D->set_exclude_cmdlist(dir,wizlist);
	else return notify_fail("ָ���ʽ��grant <AccessType> <Ŀ¼>:<��ʦ>, or grant <AccessType> list.\n");

	if( !result ) return result;

	message_vision("$N��"+dir+"��"+type+"Ȩ�޸�Ϊ"+wizlist+"ӵ�С�\n", me);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��grant <AccessType> <Ŀ¼>: <��ʦ>, or grant <AccessType> list.

��������Ŀ¼��дȨ��,
//(arch) (admin)
Example:
grant read list
grant write list
grant cmd list
grant excluderead list
grant excludewrite list
grant excludecmd list
grant read d:(wizard)
grant read kungfu:(admin),(arch),(wizard)
grant cmd cmds/arch:(admin),(arch)
grant cmd cmds/wiz/more:(admin),(arch),(wizard),(apprentice),(immortal)
grant cmd cmds/typo
HELP
	 );
	 return 1;
}

