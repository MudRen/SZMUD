// Code of ShenZhou
// road: /zhongnan/yuanneixiaojing7.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short","Ժ��С��");

        set("long",@LONG
��ȫ��̵���Ժ�����Ϊ��󣬵���ɢ�ɽ�䣬ɽ�ϱ�ֲ��ɼ���֣�
Ȫˮ���ȣ����������ྲ��С������ͨ�ġ��ߵ���������ֻ��֦ͷ���䣬
����һ�����ʵĸо�����Զ��һ���﹤�������񣬿�����һ��һ������
���书���ƣ��п����Ǹ�������ء������ǳ�����������һ��С����
���������������.
LONG);

		  set("exits",([ "west" : __DIR__"kitchen1",
								"north" : __DIR__"yuanneixiaojing6",
						"south" : __DIR__"haodian",
							 ])
			  );
	  set("cost",1);
	  set("outdoors", "zhongnan");

		create_door("south", "ľ��", "north", DOOR_CLOSED);

		setup();

		replace_program(ROOM);
}

