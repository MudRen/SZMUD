// liangyijian-book.c

inherit ITEM;
//inherit F_UNIQUE; 
#include <ansi.h>

int do_study(string arg);


void create()
{
                  set_name(HIW"�����¾���"NOR, ({ "daode jing", "jing", "book" }));
		  set_weight(600);
		  if( clonep() )
					 set_default_object(__FILE__);
		  else {
		  set("unit", "��");
                  set("long", "���Ǵ��������ɵ��������õĵ��¾���������ɵ������˿��ܺ������ա�\n");
		  set("value", 500);
		  set("material", "paper");
		  set("skill", ([
                  "name": "taoism",     // name of the skill
		  "exp_required": 100000,      // minimum combat experience required
		  "jing_cost":    40,     // jing cost every time study this
		  "difficulty":   30,     // the base int to learn this skill
                  "max_skill":    300,      // the maximum level you can learn
                    "int":   24,
		  "menpai":  "������",
				 ]) );
		  }
//                  ::create();
}

void init()
{
		  add_action("do_study", "du");
		  add_action("do_study", "study");
}

int do_study(string arg)
{
	object me = this_player();

		 if (me->query("family/family_name")!="������")
        {
			message_vision("$N������֭Ҳ���������Ȿ$n��\n",me,this_object());
			return 1;
		}
                  if (me->query_int()<24)
        {       write("��������³,�޷����������¾��İ��أ�\n");
                return 1;
        }
                write("���ж��ŵ��¾��������ĵá�\n");
        me->improve_skill("taoism", (int)me->query_skill("literate", 1)/3+1,0);
        return 1;
}
