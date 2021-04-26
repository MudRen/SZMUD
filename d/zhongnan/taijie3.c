// Code of ShenZhou
// Room: /d/zhongnan/taijie3.c
// Date: sdong 07/23/98

inherit ROOM;


void create()
{
		  set("short", "̨��");
		  set("long", @LONG
��ʯ̨��ͨ�����ߵ�һ�����̨���Ͼ����ο������룬���꣬�ɺ׵����ޣ���̬��
�涯�ˡ�����ǰ�������ĵ������һ��С·ͨ�������
LONG
		  );

		  set("exits", ([
					 "westup" : __DIR__"yangxin",
					 "east" : __DIR__"zhoulang",
		  ]));

		  set("outdoors", "zhongnan");
		  set("objects",([
					 __DIR__"npc/zhang" : 1,
		  ]));
		  set("cost", 2);
		  setup();
}
int valid_leave(object me, string dir)
{
	 mapping myfam;
	 myfam = (mapping)me->query("family");


	 if (dir == "westup" && objectp(present("zhang zhiguang", environment(me)))) {
		  if ( !myfam || myfam["family_name"] != "ȫ���")
			  return notify_fail("��־����ס˵�����Բ������ĵ���⿪�ţ�\n");
	 }

	 return ::valid_leave(me, dir);
}



