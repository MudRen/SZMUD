// Code of ShenZhou
// Room: /d/dali/qianzhuang.c
// YZC 1995/12/04 
// LYU 1997/2/10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"Ǯׯ"NOR);
	set("long", @LONG
�˴��˴���Ǯׯ�ֺŶ�����˵��ׯ���꾩�������д�ȡ�Һ���ԭһ�㴦��
LONG
	);

	set("item_desc", ([
		"bugao" : "
�꾩��Ϣ�����������α�������Ʊ����������Ʊһ�Ų��ա�
\n",
	]));

	set("exits", ([
		"east" : __DIR__"taihejie2",
	]));

	set("objects", ([
		__DIR__"npc/cui" : 1
	]));

	set("cost", 0);
	setup();
}

//void init()
////{
//	int balance;
//
//	if( !this_player()->query("newsaver") ) 
//	{
//		balance = this_player()->query("dali-balance");
//		if( balance >= 1000000 ) balance = balance/10;
//		if( balance >= 1000000 ) balance = 1000000;
//		this_player()->set("dali-balance", balance);
//		this_player()->set("newsaver", 1);
//	}
//	
//	this_player()->save();
//}

