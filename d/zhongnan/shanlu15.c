// Code of ShenZhou
// road: /zhongnan/shanlu15.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","ɽ��");

		  set("long",@LONG
�˶�ɽ·��ͨ����ɽ�š���������һ��Ƭ���֡������¿�������һ���ϴ�ĺ���
LONG);

		  set("exits",([ "northdown" : __DIR__"taiyici",
								"southup" : __DIR__"shulin6",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
    set("tjjob", 2);
	  setup();
	  replace_program(ROOM);
}

