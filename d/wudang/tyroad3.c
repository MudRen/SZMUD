// Code of ShenZhou
// tyroad3.c ʯ��
// by Marz 
// xQin 04/01

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ������ʵ��ʯ��·����ʱ���н���ͺ����˴��������߹���
̧ͷ��������ΰ��������������������֮�У�Ρ��׳�ۣ�����һ��ʯ��
ͨ��ɽ�£���Լ�ɼ�Զ���һ�ƬƬ��������Ŀ��
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"tyroad2",
		"eastdown" : __DIR__"tyroad4",
	]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}
