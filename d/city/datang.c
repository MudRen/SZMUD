// Code of ShenZhou
// Room: /city/datang.c
// xQin 5/00

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIC"����¥����"NOR);
	set("long", @LONG
���Ǳ����¿�������¥���ã����������˲��������ĸо���ǰһ����������      
�Ĳ��ô������ֹ�������Ȼ���д������ϲ��֮�á�ֻ��ǽ�Ϲ���һ������(dui
lian)��������Ϊ�������ڲ�ס��������֮����������õ���������ϵ���ĵ������
����ܽ������
LONG);
	set("exits", ([
		"east"   : __DIR__"meigui",
		"north"  : __DIR__"furong",
		"south"  : __DIR__"mudan",
		"west"   : __DIR__"zuixianlou2",
	]));
	set("item_desc", ([
	"duilian" : HIG"
       * * * * * * *
       * ��	�� *\n
       * ��	�� *\n
       * ��	�� *\n
       * ��	�� *\n
       * һ	�� *\n
       * ��	�� *\n
       * ��	�� *\n
       * ��	�� *\n
       * ��	�� *\n
       * Ϣ	�� *\n
       * * * * * * *
\n"NOR
	]) );
        set("no_fight","1");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

