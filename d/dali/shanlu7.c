// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "�ŵ�");
	set("long", @LONG
һ��ʯ��ŵ���������ľ�Դ䣬ɽ��ƽ����������һ���޼ʵ���
˫���ɴ�ɭ�֡����������һƬ��ΰ������һ�������ĺ�ǽ������
Խ��ǽͷ�ɼ�һ����¥���������Ǵ�����ʤ�廪¥��
LONG
	);

	set("exits", ([
		"west" : __DIR__"shanlu6.c",
		"east" : __DIR__"shanlu8.c",
		"enter" : __DIR__"wuhua1.c",
		]));

	set("cost", 2);
        set("fjing", 1);
	set("outdoors", "dali");
	setup();
}
