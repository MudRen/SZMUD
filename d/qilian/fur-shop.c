// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
	int i;
        set("short", "Ƥ��ҩ�ĵ�");
        set("long", @LONG
���ǹ��˳���Ψһ��һ�ҵ��̣�һ̤�����ھͿ��ŵ�һ�ɵ�������ζ����
�����Կ����ѷ��ں�Ժ��ɹ�ĸ�ʽƤ�������в���ǧ���������ǽ�ߣ�����һ
�����ľҩ������ʢ���˲�ҩ��
LONG
        );
        set("exits", ([
                "west" : __DIR__"gulang",
        ]));
	switch(random(2)){
        case 0:
                set("objects", ([ "/d/qilian/npc/huoji" : 1]));
                break;
        case 1:
        set("objects", ([
                __DIR__"npc/laotou": 1,
                __DIR__"npc/huoji": 1,
        ]));
		break;
	case 2:
                set("objects", ([ "/d/qilian/npc/huoji" : 1]));
                break;
	}
	set("cost", 0);
        setup();
}

