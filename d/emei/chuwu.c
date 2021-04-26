// Code of ShenZhou
// chuwu.c �����
// Shan: 96/06/22

#include <room.h>
inherit ROOM;

string look_door();

string* names = ({
        __DIR__"obj/changjian",
        __DIR__"obj/zhujian",
	__DIR__"obj/zhudao",
//        __DIR__"obj/changbian",
        __DIR__"obj/fuchen",
});

void create()
{
        set("short", "�����");
	set("long", @LONG
������Ƕ��һ����ֵĴ���䣬���ܶ��Ǽ��ӡ�һ�����Ϸ����˸�����
�����г��������������޵ȣ�������Ŀ����һ�����Ϸ��˸��ַ��ߡ�����һ
�����ϰ������С���ӣ�ԭ����װ��ҩƷ��ҩ��һλʦ̫������������
��Ʒ����æµ��������ߡ���������и�С¥�ݡ��������ի���ˡ�
LONG
	);
	set("exits", ([
		"up" : __DIR__"cangjing",
		"north" : __DIR__"hz_zhaitang",
	]));

        set("objects",([
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,
                CLASS_D("emei") + "/jingfeng" : 1,
        ]));

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        create_door("north", "ľ��", "south", DOOR_CLOSED);

	set("cost", 0);
	setup();
//	replace_program(ROOM);

}

string look_door()
{
        return "һ��С����ͨի���봢��䡣\n";
}

void reset()
{
	delete_temp("tianxiang");
	delete_temp("liuyedao");
	delete_temp("yaodai");
	delete_temp("ruanjian");
	return ::reset();
}
