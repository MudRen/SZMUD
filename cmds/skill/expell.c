// Code of ShenZhou
// expell.c

#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	string *skname;
	mapping skills;
	int i;

	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("你要将谁逐出师门？\n");

	if( !ob->is_character() )
		return notify_fail("你逐不动他。\n");

	if( !userp(ob) )
		return notify_fail("你只能开除玩家所扮演的人物。\n");

	if( me->query("family/privs")==-1
	&& (string)me->query("family/family_name")==(string)ob->query("family/family_name")
	|| ob->is_apprentice_of(me) ) {
		message_vision(HIG"\n$N对着$n说道：你我行我素，不守门规，让盟主发落你吧！", me, ob);
		message_vision("\n$N说完，盟主座下的武士走过来，架起$n向泰山方向走去！\n\n"NOR, me, ob);

        log_file("Expell",sprintf("[%s] %s(%s)　被关进武林大狱\n",ctime(time())[0..15],ob->query("name"),ob->query("id"))); 
		ob->move("/d/taishan/jianyu");
		tell_object(ob, HIC"\n你被收押到武林大狱中！\n\n"NOR);
	} else
		return notify_fail("这个人不是你的弟子。\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : expell|kaichu <某人>
 
这个指令可以让你开除不成才的弟子，被开除的弟子所有技能都会降到原来
的一半，而且综合评价一项会变成零，这对于一个人物而言是一个「比死还
严重」的打击，请你在开除一名弟子之前务必审慎考虑。
 
HELP
	);
	return 1;
}
