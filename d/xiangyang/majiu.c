// Code of ShenZhou
// Room: /d/xiangyang/majiu.c ���
//xQin 2/00

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", YEL"���"NOR);
        set("long",@LONG
��������������Ψһһ�ҳ����С���ɻ�Ǯ�������������ط�ȥ���ܽ�Լ������
����������Ϊ������----����������֯�����Ĵ��Ѽ����ǲ��ϣ���������Ӧ������ṩ
�Ƴ������͸��ַ��ǲ��ϡ���������µ���ľ���϶���һ����ľ��(paizi)��
LONG);
        set("no_clean_up", 0);
        set("coordinates", ([ "x" : 4, "y" : 1 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kedian",
  "southwest" : __DIR__"dongjie2",
]));
        set("item_desc", ([
                "paizi": @TEXT
���ֺ������ۡ�

TEXT]));

        set("objects", ([
                "/clone/obj/car" : 2,
                "/d/shaolin/npc/ma-fu" : 1,
                "/clone/horse/xiaoma" : 2,
                "/clone/horse/huangma" : 1,
                "/clone/horse/qingma" : 1,
                "/d/shaolin/obj/caoliao" : 2,
        ]));


        set("outdoors", "xiangyang");
        set("resource/water",1);

	setup();
        replace_program(ROOM);
}
