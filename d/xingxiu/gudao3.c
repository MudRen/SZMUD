// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "�����ŵ�");
	set("long", @LONG
���ص�ǧ��ŵ��������ѩ���������ƣ��������̣����Ի�����
���ն�����������ǹ�˿���ϼ�����Խ�����ա�����ʱ����������
�ĳ�˻�����նӵ�������Զ���������Ǹ�������˿�񡢲�Ҷ����ƥ
���յ��̶ӡ�
LONG
	);
	set("exits", ([
                "northup" : __DIR__"ertai",
                "eastdown" : __DIR__"gudao2",
        ]));
	set("objects", ([
		__DIR__"npc/trader": 1,
	]));
	set("cost", 3);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
