// Filename:   /d/jueqinggu/changlang6.c ����6
// Code:       Jiuer
// Date:       Aug 15, 2001

#include <room.h>
inherit ROOM;

void create()
{
		  set("short","����");
		  set("long",@LONG
����һ�����������ȣ�ǽ�ڶ��������ߺ����ʯ���������ɡ���
��ǽ�Ͼ��ȵ���Ƕ��һЩС��������ڷ���һЩ��յ���ѳ����յ���
���õġ������ϲ���Ů˯�������ߵ���������Ų����������ࡣ
LONG);
		  set("exits",([ 
		      "east" : __DIR__"shishi3",
			  "west" : __DIR__"changlang5",
			  "south" : __DIR__"sleeproom2",
			 ]));
		  create_door("south", "ľ��", "north",DOOR_CLOSED);
		  set("cost",1);
		  setup();	
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "����" && dir == "south" && !wizardp(me) )
		return notify_fail("������㣬����Ů˯����\n");

        return ::valid_leave(me, dir);
}
