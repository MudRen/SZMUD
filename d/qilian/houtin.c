// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�伫��Ʒζ��С�������ܵ�ǽ�Ϲ����������ֻ������е�
ǽ�������Ʋ����ġ���ȸͼ�������ڰ��˼��ŵ�ľ�������Σ����Ϸ�
��һ�����ͼ����豭�����������˲��㣬ȷ���ϵȵ�������
LONG
        );
        set("exits", ([
                "south" : __DIR__"datang",
		"north" : __DIR__"xingtang",
        ]));

	set("objects", ([
//		"/d/city/obj/kaoya" : 1,
		"/d/quanzhou/obj/yadan" : 2,
	]));
                
	set("cost", 1);
        setup();
        replace_program(ROOM);
}
