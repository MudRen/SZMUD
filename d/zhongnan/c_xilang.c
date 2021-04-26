// Code of ShenZhou
///d/zhongnan/c_xilang.c ��������
// sdong: 07/23/98

inherit ROOM;

void create()
{
		  set("short", "������");
		  set("long", @LONG
��������������������������������ש���������ż���ľͷ��(mutouren)��
�м���С��ʿ���������������ǹ㳡��
LONG
		  );
		  set("exits", ([
					 "east" : __DIR__"guangchang",
					 "south" : __DIR__"xilang",
		  ]));


		  set("outdoors", "zhongnan" );

		  set("valid_startroom", 1);

		  set("cost", 1);
		  set("item_desc",([
				"mutouren" : "����һ�����߸ߵ�ľͷ�ˣ���״��С����һλ���ˡ�ȫ����ź���ţƤֽ���������������Ʒ��ģ�����Դ��(strike mutouren)��\n",
		  ]));

		  setup();
}

void init()
{
//		  ::init();
		  add_action("do_strike", "strike");
}


int do_strike(string arg)
{       object me = this_player();
		  int check;
		  if ( !arg )
					 return notify_fail( "�����ʲ��?\n");
		  if ( arg != "mutouren" )
					 return notify_fail( "�����ʲ��?\n");


		if ((int)me->query("qi") < 30 || me->query("jingli") < 30 )
					 return notify_fail("���۵İ�����������������㣬���ƶ�̧�������ˡ�\n");
		  me->receive_damage("qi", 25);
		  me->receive_damage("jingli", 25);

		  message_vision("$N����һ���������ƻ���ľͷ�ˡ�\n", me);

		  check = (int)me->query_skill("strike",1)*(int)me->query_skill("strike",1)*(int)me->query_skill("strike",1);
		  if (check > (int)me->query("combat_exp") * 10)
		  {       write ("�����һ�ᣬ�����Լ�û��ʲô������������ȥŪ��ʵս�����ˡ�\n");
					 return 1;
		  }

		  if ((int)me->query_skill("strike", 1) >= 101)
		  {       write("�����һ�ᣬ���ֺ����ջ�\n");
					 return 1;
		  }

		  me->improve_skill("strike", me->query("int")+me->query("con") );
		  return 1;
}

