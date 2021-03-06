// Code of ShenZhou
// blkbot.c

inherit F_CLEAN_UP;
#define SYNTAX	"指令格式：blk <使用者姓名> because <原因>\n"

int main(object me, string str)
{
	object ob;
	string name, reason;
	int i;
        if (!str) return notify_fail(SYNTAX);

	if( sscanf(str, "%s because %s", name, reason)!=2 )
		return notify_fail(SYNTAX);

	ob = LOGIN_D->find_body(name);
	if (!ob) return notify_fail("咦... 有这个人吗?\n");
	// moving
	tell_room(environment(ob),"天空中伸出一只大手把"+
	(string)ob->query("name")+"抓了起来, 然後不见了.\n", ob);
	tell_object(ob,"一只手把你抓了起来, 你眼前一阵黑....\n");
	ob->move("/d/death/blkbot");
        tell_object(me, "你把"+(string)ob->query("name")+"送入空房间。\n");
	tell_object(ob,".... 醒来时发现是"+(string)me->query("name")+
	"把你弄过来的.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然出现"+
	"在你眼前\n",({me,ob}));
	// ok ..
	log_file("static/BLK", sprintf("[%s]%s(%s)因为%s被%s(%s)送进空房间。\n",
                ctime(time())[0..15], ob->name(), geteuid(ob),reason, me->name(), geteuid(me)));
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : blk <某人> because <原因>

此指令可让你(你)将某人关到空房间里去。
HELP
    );

    return 1;
}
