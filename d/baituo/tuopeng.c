//Cracked by shenzhou
// Room: /baituo/tuopeng.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"������"NOR);
        set("long", @LONG
���ǰ���ɽ�����������������ذڷ���Щ��y�ĸɲݡ������
�������������������ι�����㣬��ϴˢ�ø�Ǭ������������һ���԰Ӿ�
������Դ�ˮ�����գ�yin camel����
LONG
        );

        set("objects", ([
			__DIR__"npc/tu" : 1,            
			"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
			"north" : __DIR__"btgate",
        ]));

        set("resource/water",1);
        set("outdoors", "baituo");
        set("cost",1);
        setup();
}
