// Code of ShenZhou
// road: /zhongnan/yuxuhole.c

#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short","���鶴");

		  set("long",@LONG
�����鶴Ϊȫ���ǰ���չ�����֮��������ȫ�����Ӿ����ڴ������
ȫ��̵Ĳ���֮�أ����Ǿۻᡣǽ�Ͽ���һ��ʯ�����������ɷ���ǣ���
ü�������һ��Ӣ��������ֻ��������������һϮ�������ڷ�������Ʈ����
����Ϊ֮���ۡ�������¯������������㣬��������������ɢ����һ��
̴��ζ��
LONG);

		  set("exits",([ "out" : __DIR__"yushuidong",
							 ])
			  );
		  set("cost",1);

			set("objects", ([
//				 __DIR__"npc/wang-zd" : 1,
			 ]));

	 setup();
}

void init()
{
		  add_action("do_ketou","ketou");
		  add_action("do_dianhua","dianhua");
}


int do_ketou(string arg)
{
		  object paper, me = this_player();
		  int level1, level2, level3;

		  message_vision("$N��������������ǰ�������Ϲ���������������λ����������ͷ��\n", me);
		  me->receive_damage("qi", random(30), "������������");
		  me->start_busy(1);

		  if ( me->query("qi") <= 50 )
					 write("��ֻ����������Щ�������ġ�\n");
		  if ( me->query("qi") <= 30 )
					 write("�����������ת���ƺ����ϱ�Ҫ��ȥ��\n");

		  if ( !(me->query("family/family_name")=="ȫ���") ) return 1;

		  level1 = me->query_skill("xiantian-gong", 1);
		  level2 = me->query_skill("taoism", 1);
		  level3 = me->query_skill("quanzhen-jian", 1);

		  if ( level1>300 && level2>300 && level3>300 && random(50) == 1 && !me->query_temp("quanzhen/shentong_paper") ) {
					 paper=new(__DIR__"obj/shentong_paper");
					 if ( !paper ) return 1;

					 add("paper_count", -1);
					 me->set_temp("quanzhen/shentong_paper", 1);

					 message_vision(HIG"$N�����������ص�һ�ģ����ѵı��Ϻ�Ȼ���˿�����¶��һС��˿�\n"NOR,me);
					 write("����ϸ�Ľ�˿����һ����������������ļ����������ķ����ƺ�������\n");
					 write("��һ����У���ȴ������¡�\n");
					 message_vision("$N��æ�����պá�\n",me);
					 paper->move(me);
		  }

		  return 1;
}

int do_dianhua(string arg)
{
		  object paper, me = this_player();
		  object feng;
		  object here = environment(me);

		  if(!arg)return notify_fail("��Ҫ�㻯˭?\n");

		  /*if( arg != "feng" && arg != "ouyang" && arg != "ouyang feng" ) return notify_fail("����������㻯��\n");
*/

		  if(me->is_busy())return notify_fail("����æ���ء�\n");

		  feng = present(arg,here);

		  if(!feng)return notify_fail("��Ҫ�㻯˭?\n");

		  if( feng->query("race") != "����" )return notify_fail("��ϧ���������¡�\n");

	     	  if(userp(feng)|| feng->query("shen") > -100000 )return notify_fail("����������㻯��\n");
		  feng->set("combat_exp",me->query("combat_exp")+random(me->query("combat_exp")));
		  feng->set_temp("apply/attack",100+random(200));
		  feng->set_temp("apply/damage",100+random(200));
		  feng->set("jiali",50);
			
		  if( feng->query("combat_exp")*3 < me->query("combat_exp")*2 )
				return notify_fail("�����书̫��޷������д衣\n");
		  if(!living(feng)) return notify_fail("��õ��˼����˲��С�\n");


		  message_vision("$N����$n���е��¾���\n", me,feng);
		  me->receive_damage("jing", random(150), "������������");
		  me->start_busy(1+random(2));

		  if ( me->query("jing") <= 50 )
					 write("��ֻ����������Щ�������ġ�\n");
		  if ( me->query("jing") <= 20 )
					 write("�����������ת���ƺ����ϱ�Ҫ��ȥ��\n");

		  if ( !(me->query("family/family_name")=="ȫ���") ) return 1;

		  if( random(10) == 0 )
		  {
			  message_vision("$N�ܲ��ͷ���˵���������ʿ����ô�������У�\n", feng,me);
			  feng->kill_ob(me);
		  }
		  else if( random(7) == 0 )
		  {
			  message_vision("$N��Ȼ���˵�ͷ��˵����һ�κ����е����\n", feng,me);
			  feng->command("halt");
			  feng->remove_all_killer();

			  if( random(feng->query("combat_exp")) > me->query("combat_exp")/4 )
			  {
				 if( me->query_skill("taoism",1) < 400 )
				 {
				  me->improve_skill("taoism",800+random(1000));
				  write("��Ե�ѧ�ķ�������Щ����\n");
				 }
				 else write("��ĵ�ѧ�ķ��Ѿ��Ž��ޱ��ˡ�\n");
			  }
		  }
		  else if( random(1200)==0 )
		 {
			message_vision(HIY"$N�����Ŀҡͷ�о���ʱ��͵͵������
��\n", feng,me);      
			destruct(feng);
		 }

		  return 1;
}



