// Code of ShenZhou
// road: /zhongnan/shanlu25.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","ɽ·");

		  set("long",@LONG
�˶�ɽ·���߶����Ӳݣ������ߵ��˲��࣬����ͨ������ɽɽ�壬����ͨ����������
LONG);

		  set("exits",([ "north" : __DIR__"shanlu26",
								"southup" : __DIR__"shanlu24",
						  ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

