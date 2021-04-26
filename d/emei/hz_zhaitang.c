// Code of ShenZhou
// hz_zhaitang.c ������ի��
// Shan: 96/06/22

#include <room.h>
inherit ROOM;

string look_door();

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
������Ƕ��һ����ֵ�ի�á�ի��������˳����Ĳ����ͳ��ʣ���λС
ʦ̫������æµ�Ų�����ի�����ϰ��˼��趹��������������Լ���Ѽ����
ζ��ʳ��ի�ú�����һ����ͨ�������ִ���䣬���ߵ�����ͨ��㳡��
LONG
	);
	set("exits", ([
		"south" : __DIR__"chuwu",
		"north" : __DIR__"hz_donglang2",
	]));

        set("objects",([
                __DIR__"obj/qingshui-hulu" : 1,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,
        ]));

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        create_door("south", "ľ��", "north", DOOR_CLOSED);

	set("cost", 0);
	setup();
	replace_program(ROOM);

}

string look_door()
{
        return "һ��С����ͨի����ؾ���\n";
}

