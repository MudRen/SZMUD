
// Code of ShenZhou
// jiuyin_force_book.c �����澭�ڹ�ƪ
// by sdong 08/98

inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>

int do_read(string arg);

void create()
{
	set_name(WHT"�����澭"NOR, ({ "jiuying zhenjing", "zhenjing" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����Ƶ���װ�飬���顶�����澭��ƪ֮�ڹ��ķ���������������ϳ˵��ڹ��ķ�����ϧȱ�˺ö�ҳ��\n");
		set("value", 1000000);
		set("material", "paper");
		set("skill", ([
			"name": "force",        // name of the skill
			"exp_required": 1000000,  // minimum combat experience required
			"jing_cost":    100,     // jing cost every time study this
			"difficulty":   30,     // the base int to learn this skill
			"max_skill":    500      // the maximum level you can learn
					 ]) );
		  }
		  ::create();
}

void init()
{
		  add_action("do_read", "du");
		  add_action("do_read", "study");
}

int do_read(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("force",1);
	string qx = me->query("9yin");
	if( !arg || arg == "" ) return 0;
	else if( !stringp(qx) && qx != "granted1" && qx != "granted2" && qx != "granted3" ){
                if (wizardp(me)) tell_object(me, "if you called granted,this is error message.\n"); 
		message_vision("$N������֭Ҳ���������Ȿ$n��\n",me,this_object());
		return 1;
	}else if( lvl < 320 ){
                if (wizardp(me)) tell_object(me, "if your force > 320,this is error message.\n"); 
		message_vision("$N������֭Ҳ���������Ȿ$n��\n",me,this_object());
		return 1;
	}else if ( qx == "granted1" && lvl > 319 ){
		if ( lvl < 399 ) return "/cmds/skill/du.c"->main(me, arg);
		else tell_object(me, HIW"����Ҳ���������Ȿ"NOR+WHT"�����澭"HIW"��Ҳ������ڹ�û��������û�и���ָ�㡣\n"NOR);
		return 1;
        }else if ( qx == "granted2" && lvl > 389 ){
		if ( lvl < 449 ) return "/cmds/skill/du.c"->main(me, arg);
		else tell_object(me, HIW"����Ҳ���������Ȿ"NOR+WHT"�����澭"HIW"��Ҳ������ڹ�û��������û�и���ָ�㡣\n"NOR);
		return 1;
	}else if ( qx == "granted3" && lvl > 439 ){
		if ( lvl < 499 ) return "/cmds/skill/du.c"->main(me, arg);
		else tell_object(me, HIW"����Ҳ���������Ȿ"NOR+WHT"�����澭"HIW"��Ҳ������ڹ�û��������û�и���ָ�㡣\n"NOR);
		return 1;
	}else{
		if ( lvl < 500 ){
	                if (wizardp(me)) tell_object(me, "your force < 500 and no granted,can't du jiuyin zhenjing.\n");
			message_vision("$N������֭Ҳ���������Ȿ$n��\n",me,this_object());
 		}else{
	                if (wizardp(me)) tell_object(me, "your force > 500,your force is full,can't du jiuyin zhenjing.\n");
	 		tell_object(me, HIW"�㿴���Ȿ"NOR+WHT"�����澭"HIW"����֪�����滹��û�����������ܡ�\n"NOR);
		}
		return 1;
	}
}


