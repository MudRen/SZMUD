//                标准描述长度示例                                   |
// spark 的房间，呵呵   spark_room.c
// by naihe  2002-05-16  于茂名
// 请勿擅自更改本文件源码，谢谢！

#include <ansi.h>
inherit ROOM;

string look_mirror();

void create()
{
	set("short", YEL"峰顶小屋"NOR);
	set("long", "一间新建起来的小屋子，里面除了墙上挂着的小木牌（pai） 之外，还是空
空的什么都没有。\n");
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
保留代码方便copy……
*/
	set("exits", ([
	    "east":"/u/naihe/naihe_room",
	    "out":"/d/huashan/fengding",
	    ]));

	setup();
	call_other("/clone/board/naihe_b","???");
// 此留言版与奈何共用，但要测试一下，看看要不要改一下naihe_b.c的指向对象。
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


