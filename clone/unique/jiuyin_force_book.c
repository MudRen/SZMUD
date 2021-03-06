
// Code of ShenZhou
// jiuyin_force_book.c 九阴真经内功篇
// by sdong 08/98

inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>

int do_read(string arg);

void create()
{
	set_name(WHT"九阴真经"NOR, ({ "jiuying zhenjing", "zhenjing" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本残破的线装书，上书《九阴真经上篇之内功心法》，里面记载了上乘的内功心法，可惜缺了好多页。\n");
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
		message_vision("$N搅尽脑汁也看不明白这本$n。\n",me,this_object());
		return 1;
	}else if( lvl < 320 ){
                if (wizardp(me)) tell_object(me, "if your force > 320,this is error message.\n"); 
		message_vision("$N搅尽脑汁也看不明白这本$n。\n",me,this_object());
		return 1;
	}else if ( qx == "granted1" && lvl > 319 ){
		if ( lvl < 399 ) return "/cmds/skill/du.c"->main(me, arg);
		else tell_object(me, HIW"你再也看不明白这本"NOR+WHT"九阴真经"HIW"，也许你的内功没到火候或者没有高人指点。\n"NOR);
		return 1;
        }else if ( qx == "granted2" && lvl > 389 ){
		if ( lvl < 449 ) return "/cmds/skill/du.c"->main(me, arg);
		else tell_object(me, HIW"你再也看不明白这本"NOR+WHT"九阴真经"HIW"，也许你的内功没到火候或者没有高人指点。\n"NOR);
		return 1;
	}else if ( qx == "granted3" && lvl > 439 ){
		if ( lvl < 499 ) return "/cmds/skill/du.c"->main(me, arg);
		else tell_object(me, HIW"你再也看不明白这本"NOR+WHT"九阴真经"HIW"，也许你的内功没到火候或者没有高人指点。\n"NOR);
		return 1;
	}else{
		if ( lvl < 500 ){
	                if (wizardp(me)) tell_object(me, "your force < 500 and no granted,can't du jiuyin zhenjing.\n");
			message_vision("$N搅尽脑汁也看不明白这本$n。\n",me,this_object());
 		}else{
	                if (wizardp(me)) tell_object(me, "your force > 500,your force is full,can't du jiuyin zhenjing.\n");
	 		tell_object(me, HIW"你看着这本"NOR+WHT"九阴真经"HIW"，不知道里面还有没有其他的秘密。\n"NOR);
		}
		return 1;
	}
}


