// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "ͷ̨");
	set("long", @LONG
�뿪���˶�������ʮ����͵���ͷ̨������ɽ���Եÿ�����ɽ
��Ҳ���õ���Щ�������Ǵ��������ڵصĵ�һ��վ�����п͵꣬����
��̨���ñ����أ����������˳����ڴ˹�ҹ��
LONG
	);
	set("exits", ([
                "north" : __DIR__"",
                "south" : __DIR__"",
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
