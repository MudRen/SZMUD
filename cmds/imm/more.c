// Code of ShenZhou
// cat.c
// modified by sdong for more security 11/02/98

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file) < 0 ) {
		ob = present(arg, me);
		if( !ob ) ob = present(arg, environment(me));
		if( !ob ) return notify_fail("没有这个档案。\n");
		file = base_name(ob) + ".c";
	}

	//记录查看的文件/log/cmds/more   山猫(adx)
	//记录查看的文件改为/log/static/more   菱儿(April)
	log_file("static/more",
	sprintf("%s(%s) more %s on %s\n",
	me->name(1), //记录使用命令的人名
	geteuid(me), //记录使用命令的ID
	file,        //记录读取文件的路径
	ctime(time()) ) ); //记录使用命令的时间	

	CHANNEL_D->do_channel(me, "sys", sprintf("浏览文件%s。", file));
	if(!SECURITY_D-> valid_read(file, this_object(), "read_file") && me->query("id") != "buwu" )return notify_fail("对不起，你没有读这个档案的权力。\n");

	me->start_more_file(file);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : more <档案>|<物件名>
 
分页显示档案内容。
 
more 模式下的指令:
q      : 离开 more.
b      : 显示前一页的内容.
[ENTER]: 显示下一页的内容.

HELP
    );
    return 1;
}
