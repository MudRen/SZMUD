// Code of ShenZhou
// Room: /d/xixia/wangling.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���������������ʵ۵���Ĺ��������������������Χ��ɽ��������
���ǳ��ľ�����Χ�����˲��ɴ�أ����е������Ļʵ���Ԫ껵ĸ�����
��������Ĺ��Ϊ��ΰ���������������Ƴ�������Ȼֱ���γ��Ե����ų�
�ʵۣ�������Ԫ껳��Ա�Ϊ������ڶ���������������Ĺ����쳣���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"chiling",
  "southup" : __DIR__"spring",
]));
	set("objects", ([
		__DIR__"npc/lingshi" : 3,
	]));
	set("cost", 2);
        set("fjing", 1);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
