// Code of ShenZhou
// tyroad10.c ��԰С·
// by Marz 
// xQin 04/01

inherit ROOM;

void create()
{
	set("short", "��԰С·");
	set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ������������֣�����ʢ
���ŷۺ���һ�������һƬ���������ߡ���ʱ���۷䡸���ˡ��طɹ�����ʧ
���ڻ����У���ֻ���������ϻ���׷���ţ�ߴߴ�������������ӡ��ϱ�����
��ͨ��������԰����ڡ�
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"tyroad11",
		"west" : __DIR__"tyroad9",
		"north" : __DIR__"tygate1",
		"south" : __DIR__"tygate2",
	]));

	set("cost", 1);
	setup();
}
