// Filename:   /d/jueqinggu/shishi3.c ʯ��3
// Code:       Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short","ʯ��");
		  set("long",@LONG
����һ�䲻���ʯ�ң�����տյ����ģ���֪���������ⷿʲô
�ó���ʯ�ұ�������˯����ʯ�������������������ȡ�
LONG);
		  set("exits",([ 
		      "west" : __DIR__"changlang6",
			  "north" : __DIR__"sleeproom1",
			 ]));
		  create_door("north", "ľ��", "south", DOOR_CLOSED);

	  set("cost",1);
	  setup();	

}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "Ů��" && dir == "north" && !wizardp(me) )
		return notify_fail("������㣬������˯����\n");

        return ::valid_leave(me, dir);
}