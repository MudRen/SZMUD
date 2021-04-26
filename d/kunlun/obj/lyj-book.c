// liangyijian-book.c

inherit ITEM;
//inherit F_UNIQUE; 
#include <ansi.h>

int do_study(string arg);


void create()
{
		  set_name(HIW"两仪剑剑谱"NOR, ({ "liangyi jianpu", "jianpu" }));
		  set_weight(600);
		  if( clonep() )
					 set_default_object(__FILE__);
		  else {
		  set("unit", "本");
		  set("long", "这是昆仑派前人所总结的两仪剑法的秘籍。\n");
		  set("value", 500);
		  set("material", "paper");
		  set("skill", ([
		  "name": "liangyi-jian",     // name of the skill
		  "exp_required": 100000,      // minimum combat experience required
		  "jing_cost":    40,     // jing cost every time study this
		  "difficulty":   30,     // the base int to learn this skill
                  "max_skill":    180,      // the maximum level you can learn
                    "int":   24,
		  "menpai":  "昆仑派",
				 ]) );
		  }
//                  ::create();
}

/*
void init()
{
		  add_action("do_study", "du");
		  add_action("do_study", "study");
}

int do_study(string arg)
{
	object me = this_player();

		 if (me->query("family/family_name")!="昆仑派")
        {
			message_vision("$N搅尽脑汁也看不明白这本$n。\n",me,this_object());
			return 1;
		}
                  if (me->query_int()<24)
        {       write("你天资愚鲁,无法领悟剑谱中的奥秘！\n");
                return 1;
        }
		write("你研读着两仪剑谱，颇有心得。\n");
        me->improve_skill("liangyi-jian", (int)me->query_skill("literate", 1)/3+1,0);
        return 1;
}
*/
