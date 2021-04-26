// Code of ShenZhou
///d/zhongnan/c_dlang.c ��������
// sdong: 07/23/98

inherit ROOM;

int do_hit(string arg);

void create()
{
		  set("short", "������");
		  set("long", @LONG
��������������������������������ש�����������ż���ɳ��(shadai)��
�м���С��ʿ���������������ǹ㳡��
LONG
		  );
		  set("exits", ([
					 "west" : __DIR__"guangchang",
					 "south": __DIR__"donglang",
		  ]));


		  set("outdoors", "zhongnan" );

		  set("valid_startroom", 1);

		  set("cost", 1);
		  set("item_desc",([
				"shadai" : "����һ����ɳ�����������ǳ���ʵ��������������ȭ���ģ�����Դ��(da shadai)��\n",
		  ]));

		  setup();
}

void init()
{
//		  ::init();
		  add_action("do_hit", "da");
}


int do_hit(string arg)
{       object me = this_player();
		  int check;
		  if ( !arg )
					 return notify_fail( "�����ʲ��?\n");
		  if ( arg != "shadai" )
					 return notify_fail( "�����ʲ��?\n");


		if ((int)me->query("qi") < 26 || me->query("jingli") < 30 )
					 return notify_fail("���۵İ�����������������㣬�ֶ�̧�������ˡ�\n");
		  me->receive_damage("qi", 25);
		  me->receive_damage("jingli", 25);

		  message_vision("$N��ȭ�ݺݵػ���ɳ��������ȭͷ΢΢��Щʹ��\n", me);

		  check = (int)me->query_skill("cuff",1)*(int)me->query_skill("cuff",1)*(int)me->query_skill("strike",1);
		  if (check > (int)me->query("combat_exp") * 10)
		  {       write ("�����һ�ᣬ�����Լ�û��ʲô������������ȥŪ��ʵս�����ˡ�\n");
					 return 1;
		  }

		  if ((int)me->query_skill("cuff", 1) >= 101)
		  {       write("�����һ�ᣬ���ֺ����ջ�\n");
					 return 1;
		  }

		  me->improve_skill("cuff", me->query("int")+me->query("con") );
		  return 1;
}
