// Code of ShenZhou
// road: /zhongnan/shanlu17.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","ɽ��");

		  set("long",@LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���ʱ�ͱڱ߱���
����ɽ赣�������������䵱ɽ�ﴵ��ʱ�������ر�С�ģ���Ȼһʧ�㣬
��Ҫ����������Ԩ�ˡ�����ͨ��������������ͨ��ɽ�塣
LONG);

		  set("exits",([ "eastdown" : __DIR__"shanlu16",
								"westup" : __DIR__"shanlu18",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

