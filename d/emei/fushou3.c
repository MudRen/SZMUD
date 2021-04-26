// Code of ShenZhou
// fushou3.c ������ի��

#include <room.h>
inherit ROOM;

string* names = ({
        __DIR__"obj/mala-doufu",
        __DIR__"obj/bocai-fentiao",
        __DIR__"obj/shanhu-baicai",
        __DIR__"obj/liuli-qiezi",
});

void create()
{
        set("short", "������ի��");
	set("long", @LONG
������Ƕ��Ҹ����ֵ�ի�á������ֱ����󣬵����ھ����Ӵ������ֵĵ��ӣ�
ի�õ�Ҳ��С��ֻ�����ڰ����˳����Ĳ����ͳ��ʣ���λСʦ̫������æµ�Ų���
��ի�����ϰ��˼��趹��������������Լ���Ѽ����ζ��ʳ��������һ����(door)��
LONG
	);
	set("exits", ([
		"northup" : __DIR__"fushou2",
		"east"    : __DIR__"fushou1",
	]));

        set("item_desc",([
                "door"  : "һ��С��ͨ������¥�ϵ���Ϣ�ҡ�\n",
        ]));

        set("objects",([
                __DIR__"obj/qingshui-hulu" : 1,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,
        ]));

        create_door("northup", "ľ��", "southdown", DOOR_CLOSED);

	set("cost", 0);
	setup();
	replace_program(ROOM);

}
