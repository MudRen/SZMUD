// Code of ShenZhou
// hz_back.c �����ֺ�� 
// Shan: 96/06/29

#include <room.h>
inherit ROOM;

void create()
{
        set("short", " �����ֺ��");
	set("long", @LONG
���Ƕ���ɽ�����ֵĺ��Ƕ����������˴��̵��ӹ���ĵط������﹩
��һ���������������Կ�ǽ���ż���̫ʦ�Σ����Ϸ��ż������š���������
���򼸸�Ů���Ӵ����书��
LONG
	);
	set("exits", ([
		"north" : __DIR__"daxiong",
	]));

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        set("objects",([
                CLASS_D("emei") + "/miejue" : 1,
        ]));

        create_door("north", "ľ��", "south", DOOR_CLOSED);

	set("cost", 0);
	setup();
	replace_program(ROOM);

}
