// Code of ShenZhou
// road: /zhongnan/shanlu29.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","С·");

		  set("long",@LONG
�˶�С·���߶����Ӳݣ������ߵ��˲��࣬���ܵľ�ɫ��Խ��Խ�����������Ѿ�
�쵽ɳĮ�ˣ�����������Կ���һ�����͵�ɽ�塣
LONG);

		  set("exits",([ "northwest" : __DIR__"shanlu30",
								"southeast" : __DIR__"shanlu28",
						  ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

