// Code of ShenZhou
// road: /zhongnan/shanlu24.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","ɽ·");

		  set("long",@LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���������ͨ��
ɽ�ţ�����ͨ���嶥��
LONG);

		  set("exits",([ "northdown" : __DIR__"shanlu25",
								"eastup" : __DIR__"shanlu23",
						  ])
			  );
	  set("cost",4);
    set("tjjob", 4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

