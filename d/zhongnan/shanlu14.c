// Code of ShenZhou
// road: /zhongnan/shanlu14.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","ɽ��");

		  set("long",@LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���ʱ�ͱڱ߱���
����ɽ赣�������������䵱ɽ�ﴵ��ʱ�������ر�С�ģ���Ȼһʧ�㣬
��Ҫ����������Ԩ�ˡ�������ͨ����ɽ�ţ�ԶԶ��������һ���ϴ�ĺ���
LONG);

		  set("exits",([ "northdown" : __DIR__"shulin4",
								"southup" : __DIR__"shanlu13",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

