//                ��׼��������ʾ��                                   |
// spark �ķ��䣬�Ǻ�   spark_room.c
// by naihe  2002-05-16  ��ï��
// �������Ը��ı��ļ�Դ�룬лл��

#include <ansi.h>
inherit ROOM;

string look_mirror();

void create()
{
	set("short", YEL"�嶥С��"NOR);
	set("long", "һ���½�������С���ӣ��������ǽ�Ϲ��ŵ�Сľ�ƣ�pai�� ֮�⣬���ǿ�
�յ�ʲô��û�С�\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("valid_startroom", 1);

	set("item_desc",([
	    "pai":"spark room\n",
	    "mirror": (: look_mirror :),
	    "jingzi": (: look_mirror :),
	]));

/*	set("objects", ([
	    __DIR__"obj/yizi" : 1,
	    ]));
�������뷽��copy����
*/
	set("exits", ([
	    "east":"/u/naihe/naihe_room",
	    "out":"/d/huashan/fengding",
	    ]));

	setup();
	call_other("/clone/board/naihe_b","???");
// �����԰����κι��ã���Ҫ����һ�£�����Ҫ��Ҫ��һ��naihe_b.c��ָ�����
}
/*
void init()
{
	add_action("do_huazhuang","hz");
}

string look_mirror()
{
	object me=this_player();
	string face;

	if(!me->query_temp("hz/spark")) face="new";
	if((int)me->query_temp("hz/spark")<=5) face="ugly";
	if((int)me->query_temp("hz/spark")>5 && (int)me->query_temp("hz/spark")<=10) face="btf";
	if((int)me->query_temp("hz/spark")>10) face="yeah";

	if(face=="new")
	switch(random(2))
	{
*/


