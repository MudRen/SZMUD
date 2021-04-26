// Code of ShenZhou
// road: /zhongnan/laoqurock.c
// sdong 08/98

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","������");

        set("long",@LONG
һ·������ɽ·��Խ��Խ�ա�ֻ��һ�����ʯ����·�У��Կ�ƾ�٣�
����һ���ϸ��������ӣ�����״��ɭ�ɲ�������������η�������ο���
��פ��ۿ���������һƬï�ܵ����֡���������һ�����͵�ɽ·��
LONG);

        set("exits",([ "southdown" : __DIR__"shulin3",
                        "northup" : __DIR__"shanlu5",
                      ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

}


void init()
{
		  object ob = this_player(), robber, *inv;
		  int i, j=0;

		  if ( interactive(ob) &&  ob->query("family/family_name")=="ȫ���" && random(15)==1 &&
				  (
					present("chuanbei", ob) ||
					present("fuling", ob) ||
					present("gouzhi zi", ob) ||
					present("heshouwu", ob) ||
					present("huanglian", ob) ||
					present("jugeng", ob) ||
					present("jinyin hua", ob) ||
					present("shengdi", ob)
					) && ob->query("combat_exp") > 100000
			)
			{
					 message_vision(HIR"ֻ����һ����죬һ��ë���Բݶ������˳�����ס$N��\n"NOR, ob);
					 robber = new(__DIR__"npc/maozei");
					 robber->move(environment(ob));
					 ob->set_temp("herb_victim", 1);
					 return;
			}

		  inv = all_inventory(ob);

		  for (i=0; i<sizeof(inv); i++) {
					 if (inv[i]->query("value") >= 10000
					 && !inv[i]->query("money_id")) j++;
		  }
		  if (j>0) ob->set_temp("rob_victim", 1);

		  if ( interactive(ob) && ob->query_temp("biao/ma")
		  && present("hong biao", ob) && random(5)==1 || j>0 && random(30) ==0
			 && ob->query("combat_exp") > 100000
			) {
					 message_vision(HIR"ֻ����һ�󲦲�����һ���ݿ��Բݶ������˳�����ס$N��\n"NOR, ob);
					 robber = new("/d/village/npc/caokou");
					 robber->move(environment(ob));
					 return;
		  }
}

int valid_leave(object me, string dir)
{
	 object maozei = present("mao zei");
	 object caokou = present("cao kou");
	 if( maozei && ( me->query("id") == maozei->query_temp("victim") )) // me->query_temp("herb_victim",1)==1 &&
	 {
		 if ( dir != "northup" )
		 {
			  return ::valid_leave(me, dir);
		 }
		 message_vision(HIR"$N����ס��ȥ·��\n"NOR, me);
		 return notify_fail("ë���ȵ������û�ţ�\n");
	}


	 if( me->query_temp("rob_victim", 1)==1 && caokou && ( me->query("id") == caokou->query_temp("victim") ) )
	 {
		 message_vision(HIR"$N���ݿܵ�ס��ȥ·��\n"NOR, me);
		 return notify_fail("�ݿܺȵ������û�ţ�\n");
	 }

	 return 1;

}
