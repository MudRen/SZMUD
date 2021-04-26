// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
����һ�伫�����ܵĵ������ң������ٽ̵Ĳ���֮�������ڴӱ�
���ϲ����˱����ܣ��ݴ����в��پ��Ǵ��ڲ��䣬�����ǼپͲ��ö�
֪�ˣ����Ǵ�һЩ�ܳ���ĵ��ʽ������ܵ�֪���Ǽ�ֵ���ǵı��
���м��������ż���ľ���񽣡������澹��һ���ɸߵİ���ƿ������
��ʿҲ���԰ᶯ�����߽�����һ��СС��ʯ�ţ�door����
LONG
        );
	set("no_fight", "1");
        set("no_steal", "1");
        set("sleep_room",1);
        set("exits", ([
                "out" : __DIR__"zibai",
                "west" : __DIR__"houtin",
        ]));
        set("objects", ([
                __DIR__"obj/ping" : 1,
        ]));

	set("item_desc", ([
                "door" : "�����ž����ϰ��¡�\n",
        ]));
        set("no_clean_up", 1);

	set("cost", 1);
        setup();
        replace_program(ROOM);
}
