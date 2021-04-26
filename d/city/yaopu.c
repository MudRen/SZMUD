// Code of ShenZhou
// Room: /city/yaopu.c
// YZC 1995/12/04 

//#include <room.h>   
#include <ansi.h>   
inherit ROOM;

//void close_path(); 

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С��
����ɢ�������ġ���ҽƽһָ���ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�һ��
С���վ�ڹ�̨���к��Ź˿͡���̨������һ�ŷ��ƵĹ��(guanggao)��
LONG
	);
	set("exits", ([
		"south" : __DIR__"dongdajie2",
		]));

	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
		��ҩ��\t��������
		�ߡ�ҩ��\t��������
		��������\tҼ������
		������ҩ���ϰ����顣\n",
		]));

//	set("item_desc", ([
//		"guanggao" : "�����ϰ�ƽһָ�����ҩδ�飬������ͣӪҵ��\n",
//	]));

	set("objects", ([
		__DIR__"npc/ping" : 1,
                __DIR__"npc/huoji" : 1,
	]));

	set("cost", 0);
	set("day_shop", 1);
	setup();
}
/*
void init() 
{
	add_action("do_open", "open"); 
}

int do_open(string arg)
{
	object me; 
	me = this_player(); 
	if( !arg || arg=="" ) return 0; 
	if( arg=="door" ) {
		write(HIW"��һ��������ȥ,�������ƿ������š�\n"NOR); 
		return 1;
	}
	if( me->query("id") == "surf" || "leiidian" ) {
		write(HIY"���������һ����ڡ�\n"NOR);
		return 1;
	}
	if( !query("exits/up") ) { 
		set("exits/up", __DIR__"surf_room");
		call_out("close_path", 3);
		return 1;
	}
	else {
		write(HIY"û����ħ���貨�۵�ָ�������������\n"NOR); 
		message_vision( HIR "ͻȻ�ŷ���ӿ��һ���ɫ������$N���ɵ�������һ��������Ȼ�о���һ�����,���ǸϿ��߰�!\n\n\n" NOR,me); 
		return 1;
	}
	write("��Ҫ�ƶ�ʲô��\n"); 
	return 0;
}
void close_path() 
{
	if( !query("exits/up") ) return;
	message("vision", HIW"�����ǰһ�����ѵ�����Ŀ��Լ�����ҽ��\n"NOR,this_object() ); 
	delete("exits/enter"); 
}
*/
