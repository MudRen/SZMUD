// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "��̨");
	set("long", @LONG
�ļ��ľ�ɫ��������һɽ֮�С�ɽ���ϣ���ѩ�����������϶���
ɽ������ɴ䣬��ɫŨ�أ�ɽ���ϣ�ɽ����������ֵ���ģ�������
ѩ��ֱ��������Ϫ�����ѩ���ڣ����ⰻȻ����̨�Ա�����һʯ����
�˳����˶���
LONG
	);
	set("exits", ([
                "west" : __DIR__"guozi",
                "southdown" : __DIR__"gudao3",
		"north" : __DIR__"xrdong",
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
