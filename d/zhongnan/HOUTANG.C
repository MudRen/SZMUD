// Code of ShenZhou
// road: /zhongnan/houtang.c

inherit ROOM;
#include <ansi.h>
void create()
{
		  set("short","����");

		  set("long",@LONG
������������ˡ�ֻ�����Ͽտյ�����ûʲ����衣�������ӿ���ǽ
���š�һЩŮ�����������Ǩ����졣�ڶ��������ϸ�����һ����(hua1)(hua2)��
������һ��ͨ��������С�š�
LONG);

		  set("item_desc",(["hua1" : "
���ڻ������������һ����ʮ�����꣬���ڶԾ���װ����һ����ʮ
�������Ѿ�ߣ��������裬�����̺򡣻��о������곤Ů����ò��������
ü���ޣ��۽�֮��ȴ��������һ��ɱ����
				\n",
									"hua2" : "
���ڻ�����һ��������ߵ�������ˡ�ֻ������������������ʳָָ�Ŷ�
���ǣ�ֻ�Ǳ������⣬��òȴ��������
				\n",
								  ]));

		  set("exits",([ "north" : __DIR__"dating",

							 ])
			  );
                set("objects",([
//                "/kungfu/class/gumu/longnu" : 1
                ]));
	  set("cost",1);

	  setup();
}

void init()
{
         add_action("do_ketou", "ketou"); 
         add_action("do_tuo", "tuo");
         add_action("do_tuo", "tu");
         add_action("do_tuo", "pei");
}

int do_ketou(string arg)
{
          mapping fam;
          object me = this_player();
        if ((!arg) || (arg != "hua1")) return 0;
          message_vision("$N�����򵹣�˫ϥ���أ�������������ʦ���ŵĻ������һ����ͷ. \n", me);
          me->add_temp("marks/ketou", 1);
        if (me->query_temp("marks/tuo") == 2 && me->query_temp("marks/ketou") == 4
          && (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��") && me->query("combat_exp") < 10000){
          me->set("family_name", "��Ĺ��");
          me->set("title", "��Ĺ����");
          me->create_family("��Ĺ��", 5, "����");
          me->set("class","swordsman");
          write(HIR"��ϲ����Ը��Ϊһ����Ĺ���ӡ�\n"NOR);
          me->delete_temp("marks/tuo");
          me->delete_temp("marks/ketou");
          return 1;
          }
}

int do_tuo(string arg)
{
           object me = this_player();
           if (me->query_temp("marks/tuo") == 2)
             return notify_fail("���ٹ���û�У�\n");
           if ( arg=="hua2"){
           message_vision("$N���������Ļ���ݺ�����һ��. \n", me);
           me->add_temp("marks/tuo", 1);
           return 1;
           }
          return notify_fail("�㲻Ҫ������ٿ�ˮ��\n");
}
