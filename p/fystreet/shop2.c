#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"�Ҿ߳�"NOR);
	set("long",@LONG
�����ǼҾ����ӵĶ�¥���ڷ��Ÿ�ʽ�����ļҾߣ������Ҫ����Ҿ�
��һ�����ܴ��������������Ǹ�ʽ�����Ĵ󴲣��������θ�����ɫ
�Ķ��С����⣬Ҳ�ٲ�������֮��ı�Ҫ�Ҿߡ�
    ��˵���ﻹ�ڲ��ϵ�����µļҾ��أ���������Ժ�����������
LONG	);
	set("exits",([
	"down" : __DIR__"shop",
	]));
	set("objects",([
	__DIR__"npc/seller":1,
	__DIR__"npc/obj/jiaju":1,
	__DIR__"npc/obj/jiaju1":1,
	__DIR__"npc/obj/jiaju2":1,
	__DIR__"npc/obj/jiaju3":1,
	__DIR__"npc/obj/jiaju4":1,
	__DIR__"npc/obj/jiaju5":1,
	__DIR__"npc/obj/jiaju6":1,
	]));
	set("coor/x",60);
	set("coor/y",20);
	set("coor/z",10);
	set("no_fight",1);
	setup();
}