// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����ǽ������ӱ����ȵض������Ǹ�һ���ģ���������ͨҪ����
������Ҫ�����罫���ƹ���ɽ�ϱ��ͰͶ���ʲ���Զ����ϵľ�����Ȩ��
��ǽ����������̨��ǹ�ۣ��䱸ɭ�ϡ�
LONG
	);
	set("exits", ([
                "north" : __DIR__"yili",
                "south" : __DIR__"shanjiao",
        ]));
	set("objects", ([
                __DIR__"npc/bing" : 4,
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
