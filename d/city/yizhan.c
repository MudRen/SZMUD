// Code of ShenZhou
// Write by Wzfeng 12-29
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"��վ"NOR);
        set("long", @LONG
������һ����վ��ר�Ÿ��𴫵ݽ�����ʿ�������ż���������ż��Ŵ��ľ
��������д��֮�á�������ʲô�ż���Ҫ�͸����������ѣ����������������
ة����ߵ�ǽ������һ�Ÿ�ʾ��(gaoshi)
LONG
        );

                        set("exits", ([
                                         "north" : __DIR__"kedian",
                        ]));
	set("item_desc", ([
			"gaoshi":
		  "-------------------------������֪---------------------------\n\n\n"
			"\tһ���뽫Ҫд������ֽ��д�á�(write letter)��\n\n"
			"\t����������ϸ��װ�ڷ����У���á�(feng xin)��\n\n"
			"\t��������õ��ż�������ة(send letter)��\n\n"

			 ]) );
	

        set("objects", ([
                __DIR__"npc/xinshi" : 1,
"/task/guo_job/guo" : 1,
        ]));

                set("no_fight",1);
        set("no_sleep",1);
               setup();

}
